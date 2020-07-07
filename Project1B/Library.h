#pragma once
#ifndef Library_H
#define Library_H
#include "Date.h"
#include <vector>
#include <queue>

using namespace std;

struct Employee {
	string name;
	int waitTime;
	int retainTime;

	Employee() {
		name = "";
		waitTime = 0;
		retainTime = 0;
	}

	Employee(string name, int waitTime = 0, int retainTime = 0) {
		this->name = name;
	}

};

struct Book {
	string name;
	Date circStart;
	Date circEnd;
	bool isArchived;
	queue<Employee> bookQ;

	Book() {
		name = "";
		circStart = Date(0, 0, 0, DateFormat::US);
		circEnd = Date(0, 0, 0, DateFormat::US);
		isArchived = false;
	}

	Book(string name, Date circStart, Date circEnd, bool isArchived = false) {
		this->name = name;
		this->circStart = circStart;
		this->circEnd = circEnd;
	}

};

class Library {
public:
	void addBook(string name, Date circStart, Book B) {
		B.name = name;
		B.circStart = circStart;

		bookList.push_back(B);
	}

	void addEmployee(string name, Employee E) {
		E.name = name;

		employeeList.push_back(E);
	}

	bool circulate(string name, Date d) {
		///BigO=(n*n).
		for (int i = 0; i < bookList.size(); ++i) { //go through list of books/

			if (!bookList.at(i).isArchived && bookList.at(i).name == name) { //check if book is archived and have the right book

				bookList.at(i).circStart = d; //set the circulation date

				for (int j = 0; j < employeeList.size(); ++j) { //run throug employee lits

					bookList.at(i).bookQ.push(employeeList.at(j)); //push the whole employee list to that one book.
				}
			}
		}
		return true;


	}

	void passOn(string name, Date d) {
		for (int i = 0; i < bookList.size(); ++i) {
			if (bookList.at(i).name == name && circulate(name, bookList.at(i).circStart)) {
				bookList.at(i).bookQ.front().passDate = d;
				bookList.at(i).bookQ.push(bookList.at(i).bookQ.front());
				bookList.at(i).bookQ.pop();
				bookList.at(i).bookQ.front().retainTime = d - bookList.at(i).bookQ.front().passDate;
				bookList.at(i).bookQ.front().waitTime = d - bookList.at(i).circStart;
			}

		}
	}

	int getSize() {
		return employeeList.size();
	}

private:
	int waitTime;
	vector<Book> bookList;
	vector<Employee> employeeList;
};

/*

map<int, int> x;
int size = employeeList.size();
for (int i = 0; i < size; i++) {

	}




(Weight: 20%) Makea data structure (priority queue) that allows the pushing and popping of items.
The popped item is the item with the highest priority.
The queue should also be updatable whenever an item’s priority changes.
•The more the employee waited, the higher the priority. The more she retained a book, the lower the priority.
To put it simply, the priority is: waiting_time –retaining_time.The employee in front of the queue gets the book.
•(Weight: 40%) The system should allow the employee to pass the book on to the next employee on the queue on a given date.
•Passing on the book has the following outcome:
If the employee who is passing on the book is the last in the queue, the book gets archived.
The total retaining time for the employee who passed on the book gets adjusted.
The total waiting time for the employee who got the book gets adjusted.
If there are other queues for other books, and these queues contain the employee who passed on the book and the employee who got the book, then adjust these queues (because the priorities have changed).
See Figure 1 for an illustration.






*/
#endif