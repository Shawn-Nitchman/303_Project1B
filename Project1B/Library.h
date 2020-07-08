#pragma once
#ifndef Library_H
#define Library_H
#include "Date.h"
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

// struct that holds the employee data
struct Employee {
	string name;
	int waitTime;
	int retainTime;
	int prioNum;
	Date prevDate;

	//Constructors
	Employee() {
		name = "";
		waitTime = 0;
		retainTime = 0;
		prioNum = 0;
		prevDate = Date(1000, 1, 1, US);
	}

	Employee(string name, int waitTime = 0, int retainTime = 0) { // 
		this->name = name;
	}

};

// strucuture that holds the book data
struct Book {
	string name;
	Date circStart;
	Date circEnd;
	bool isArchived;
	queue<Employee> bookQ;

	// Constructors
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

// this class is where most of the functions are to pass and circulate the books for the employees
class Library {
public:
	// Creates book with said name
	void addBook(string name) {
		Book B;
		B.name = name;

		// Adds book to list of books
		bookList.push(B);
	}

	// Creates employee with said name
	void addEmployee(string name) {
		Employee E;
		E.name = name;

		// Adds employee to list of Employees
		employeeList.push_back(E);
	}

	void circulate(string name, Date d) {
		// BigO=(n*n).
			// Check if book is archived and have the right book
		if (!bookList.front().isArchived && bookList.front().name == name) {

			// Set the circulation date
			bookList.front().circStart = d;

			// Run through employee list
			for (unsigned int j = 0; j < employeeList.size(); ++j) {
				// Push the whole employee list to that one book.
				bookList.front().bookQ.push(employeeList.at(j));
			}
			// Sets the previous date to calculate retain time
			bookList.front().bookQ.front().prevDate = d;

			// Cycles through 
			bookList.push(bookList.front());
			bookList.pop();
		}
	}

	void passOn(string name, Date d) {
		//(O)n^2
			// Checks if the list of books and employee is empty, compares name, and checks for achive status
		if (!bookList.empty() && bookList.front().name == name && !bookList.front().bookQ.empty() && !bookList.front().isArchived) {
			// Cycles through list of employees
			for (unsigned int i = 0; i < employeeList.size(); i++) {
				// Checks to see if the employee at the front of Queue is the employee at a certain element
				if (employeeList.at(i).name == bookList.front().bookQ.front().name) {
					// Calculates retain time based on current date and the previous date set above and saves it to the employee list, not the employee in the queue
					employeeList.at(i).retainTime += d - bookList.front().bookQ.front().prevDate;
					// Calculates the priority of the employee for future use
					employeeList.at(i).prioNum = employeeList.at(i).waitTime - employeeList.at(i).retainTime;
				}
			}
			// Removes the current front of the employee queue
			bookList.front().bookQ.pop();
			// Checks if employee queue is empty
			if (!bookList.front().bookQ.empty()) {
				// Cycles through list of employees
				for (unsigned int i = 0; i < employeeList.size(); i++) {
					// Checks to see if the employee at the front of Queue is the employee at a certain element
					if (employeeList.at(i).name == bookList.front().bookQ.front().name) {
						// Calculates wait time of the new retaining employee based on current date and circulation start date and sets to employee list
						employeeList.at(i).waitTime += d - bookList.front().circStart;
						// Sets previous date to calculate the next retain time of employee
						bookList.front().bookQ.front().prevDate = d;
					}
				}
			}
		}

		//
		if (!bookList.empty() && bookList.front().bookQ.empty()) {
			// Displays a book being archived
			cout << endl << bookList.front().name << " has been archived" << endl << endl << endl;
			// Sets current book to be archived
			bookList.front().isArchived = true;
			// Adds book to archived list of books
			archivedBooks.push_back(bookList.front());
			// Removes book from queue
			bookList.pop();

			// Checks if book list is empty after removing the front book
			if (!bookList.empty()) {
				// Sorts vector of employees based on priority
				for (unsigned int i = 0; i < employeeList.size(); i++) {
					for (unsigned int j = employeeList.size() - 1; j > i; j--) {
						if (employeeList.at(i).prioNum < employeeList.at(j).prioNum) {
							swap(employeeList.at(i), employeeList.at(j));
						}
					}
				}
				// Checks if employee queue is empty for current book
				if (!bookList.front().bookQ.empty()) {
					// Sets previous date for future use as a variable
					Date a = bookList.front().bookQ.front().prevDate;
					// Loops through the filled queue, removes the non-sorted and pushes the new, sorted set of employees into queue
					for (unsigned int i = 0; i < employeeList.size(); i++) {
						bookList.front().bookQ.pop();
						bookList.front().bookQ.push(employeeList.at(i));
					}
					// Sets proper previous date
					bookList.front().bookQ.front().prevDate = a;
				}
			}
		}
	}

	// this method prints out the what is happening and displays wait and retain time along with each employee priority for getting a book and archived books
	void getStats() {
		cout << string(35, '_') << endl;
		cout << "Name" << setw(10) << "Retain" << setw(10) << "Wait" << setw(9) << "Prio" << endl;
		cout << string(34, '-') << endl;
		for (unsigned int i = 0; i < employeeList.size(); i++) {
			cout << employeeList.at(i).name << setw(12 - employeeList.at(i).name.length()) << employeeList.at(i).retainTime << setw(10) << employeeList.at(i).waitTime << setw(9) << employeeList.at(i).prioNum << endl;
		}
		cout << endl;
		cout << "Archived books" << endl;
		cout << string(34, '-') << endl;
		if (archivedBooks.size() == 0) {
			cout << "None" << endl;
		}
		else {
			for (unsigned int i = 0; i < archivedBooks.size(); i++) {
				cout << archivedBooks.at(i).name << endl;
			}
			cout << string(35, '_') << endl;
			cout << endl;
		}
	}

	// these are the list that hold the employees we have and the books we have.
private:
	queue<Book> bookList;
	vector<Book> archivedBooks;
	vector<Employee> employeeList;
};

#endif