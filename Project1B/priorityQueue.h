#pragma once
#ifndef priorityQueue_H
#define priorityQueue_H
#include "Node.h";
#include <string>

// this is a work in progess and has only been implemented in a single linked list format
class prioQueue {
public:
	
	Node* head;

	// contructor for creating the head
	prioQueue() {
		head = NULL;
	}

	// This method is for inserting a node at the beginning of the list making it the new head
	void insertStart(string newName) {
		Node* h = new Node;
		h->name = newName;
		h->next = head;
		head = h;
	}

	// this method is for inserting a node at the end of the list making it the last element pointing to null
	void insertEnd(string newName) {
		Node* e = head;
		while (e->next != NULL) {
			e = e->next;
		}
		Node* temp = new Node;
		temp->name = newName;
		temp->next = NULL;
		e->next = temp;
	}

	// this is for deleting the head and checks to make sure the list is not empty
	void deleteFirst() {
		if (head == NULL) {
			cout << "queue is empty" << endl;
		}
		else {
			Node* d = new Node;
			d = head;
			head = head->next;
			delete d;
			d = NULL;
		}
	}

	// this deletes the last element and makes sure the last element is not empty
	void deleteEnd() {
		if (head == NULL) {
			cout << "queue is empty" << endl;
		}
		else if (head->next == NULL) {
			delete head;
			head = NULL;
		}
		else {
			Node* d;
			d = head;
			Node* temp = NULL;
			while (d->next != NULL) {
				temp = d;
				d = d->next;
			}
			temp->next = NULL;
			delete d;
		}
	}

	// this will create a new node and insert it in the list. does not check if postion is in list
	void insertAtAnyPoint(string newName, int pos) {
		Node* ptr2 = head;
		for (int i = 1; i < pos - 1; i++) {
			ptr2 = ptr2->next;
		}
		Node* ptr = new Node;
		ptr->name = newName;
		ptr->next = ptr2->next;
		ptr2->next = ptr;
	}

	// delets the node at any position, does not check if position is in list
	void deleteAtAnyPos(int pos) {
		Node* ptr = head;
		for (int i = 1; i < pos - 1; i++) {
			ptr = ptr->next;
		}
		Node* ptr1 = ptr->next;
		ptr->next = ptr1->next;
		delete ptr1;
		ptr1 = NULL;
	}

	// goes through the list and outputs the list
	void tranverse() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->name << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	// destructor for list
	~prioQueue() {
		head = NULL;
		delete head;
	}

};

#endif 