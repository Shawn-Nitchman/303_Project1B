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
	int prioNum;
	Date prevDate;

	Employee() {
		name = "";
		waitTime = 0;
		retainTime = 0;
		prioNum = 0;
		prevDate = Date(1000, 1, 1, US);
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
		circStart = Date(1000, 1, 1, US);
		circEnd = Date(1000, 1, 1, US);
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
	void addBook(string name) {
		Book B;
		B.name = name;

		bookList.push(B);
	}

	void addEmployee(string name) {
		Employee E;
		E.name = name;

		employeeList.push_back(E);
	}

	void circulate(string name, Date d) {
		///BigO=(n*n).
		if (!bookList.front().isArchived && bookList.front().name == name) { //check if book is archived and have the right book

			bookList.front().circStart = d; //set the circulation date

			for (unsigned int j = 0; j < employeeList.size(); ++j) { //run throug employee list

				bookList.front().bookQ.push(employeeList.at(j)); //push the whole employee list to that one book.
			}
			bookList.front().bookQ.front().prevDate = d;
		}
	}

	void passOn(string name, Date d) {
		//(O)n^2
		for (unsigned int i = 0; i < bookList.size(); ++i) {
			if (bookList.front().name == name && !bookList.front().bookQ.empty()) {
				for (unsigned int j = 0; j < employeeList.size(); ++j) { // sets employeeList info
					if (bookList.front().bookQ.front().name == employeeList.at(j).name) {

						employeeList.at(j).retainTime += d - bookList.front().bookQ.front().prevDate;
						employeeList.at(j).prioNum = employeeList.at(j).waitTime - employeeList.at(j).retainTime;
						bookList.front().bookQ.pop();
						if (bookList.front().bookQ.front().name == employeeList.at(j).name) {
							employeeList.at(j).waitTime += d - bookList.front().circStart;
						}
					}
				}
				/*bookList.front().bookQ.pop();
				if (!bookList.front().bookQ.empty()) {
					bookList.front().bookQ.front().prevDate = d;
				}*/
			}

			else if (bookList.front().bookQ.empty()) {
				bookList.front().isArchived = true;
				bookList.pop();
				if (!bookList.empty()) {
					for (unsigned int i = 0; i < employeeList.size(); i++) {
						for (unsigned int j = employeeList.size() - 1; j > i; j--) {
							if (employeeList.at(i).prioNum < employeeList.at(j).prioNum) {
								swap(employeeList.at(i), employeeList.at(j));
							}
						}
						bookList.front().bookQ.push(employeeList.at(i));
					}
				}
			}
		}
	}

	void getStats() {
		cout << "Name, Retain, Wait, Prio" << endl;
		for (unsigned int i = 0; i < employeeList.size(); i++) {
			cout << employeeList.at(i).name << " " << employeeList.at(i).retainTime << " " << employeeList.at(i).waitTime << " " << employeeList.at(i).prioNum << endl;
		}
		cout << endl;
	}

private:
	int waitTime;
	queue<Book> bookList;
	vector<Employee> employeeList;
};

/*

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


*/
#endif