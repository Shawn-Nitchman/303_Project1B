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
			bookList.push(bookList.front());
			bookList.pop();
		}
	}

	void passOn(string name, Date d) {
		//(O)n^2
		if (!bookList.empty() && bookList.front().name == name && !bookList.front().bookQ.empty() && !bookList.front().isArchived) {
			for (unsigned int i = 0; i < employeeList.size(); i++) {
				if (employeeList.at(i).name == bookList.front().bookQ.front().name) {
					employeeList.at(i).retainTime += d - bookList.front().bookQ.front().prevDate;
					employeeList.at(i).prioNum = employeeList.at(i).waitTime - employeeList.at(i).retainTime;
				}
			}
			bookList.front().bookQ.pop();
			if (!bookList.front().bookQ.empty()) {
				for (unsigned int i = 0; i < employeeList.size(); i++) {
					if (employeeList.at(i).name == bookList.front().bookQ.front().name) {
						employeeList.at(i).waitTime += d - bookList.front().circStart;
						bookList.front().bookQ.front().prevDate = d;
					}
				}
			}
		}

		if (!bookList.empty() && bookList.front().bookQ.empty()) {
			cout << bookList.front().name << " has been archived" << endl << endl;;
			bookList.front().isArchived = true;
			bookList.pop();
			if (!bookList.empty()) {
				for (unsigned int i = 0; i < employeeList.size()S; i++) {
					for (unsigned int j = employeeList.size() - 1; j > i; j--) {
						if (employeeList.at(i).prioNum < employeeList.at(j).prioNum) {
							swap(employeeList.at(i), employeeList.at(j));
						}
					}
				}
				if (!bookList.front().bookQ.empty()) {
					Date a = bookList.front().bookQ.front().prevDate;
					for (int i = 0; i < employeeList.size(); i++) {
						bookList.front().bookQ.pop();
						bookList.front().bookQ.push(employeeList.at(i));
					}
					bookList.front().bookQ.front().prevDate = a;
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

#endif