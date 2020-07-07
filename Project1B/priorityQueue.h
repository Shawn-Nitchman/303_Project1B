#pragma once
#ifndef priorityQueue_H
#define priorityQueue_H
#include "Node.h";
#include <cstddef>
#include <string>

// created a simple queue
class prioQueue {
	private:
		// data that will be used for queue

		Node* frontOfQueue;
		Node* backOfQueue;
		size_t num_items;

	public:
		
		// constructor with member inilizer list setting the front and back of queue as null and number of items as 0
		prioQueue(Node* frontOfQueue = NULL, Node* backOfQueue = NULL)
			: frontOfQueue(frontOfQueue), backOfQueue(backOfQueue), num_items(0) {}

		// this method adds a member to the queue at the back of the line. 
		void push(const string item) {

			// if no element exist in the queue then it will create the element and assign it to the front
			if (frontOfQueue == NULL) {
				backOfQueue = new Node(item, NULL);
				frontOfQueue = backOfQueue;
			}

			// if there is an elemment then it will add it to the back 
			else {
				backOfQueue->next = new Node(item, NULL);
				backOfQueue = backOfQueue->next;
			}

			num_items++;
		}

		// returns the data of the element in front
		string front() {
			return frontOfQueue->name;
		}

		// returns the size of queue
		int size() {
			return num_items;
		}

		// this will delete the front member. it has to assign the front of the queue nexts as the front so the data isn't forgotten then it can delete it
		void pop() {
			Node* old_front = frontOfQueue;

			frontOfQueue = frontOfQueue->next;
			if (frontOfQueue == NULL) {
				backOfQueue = NULL;
			}

			delete old_front;
			num_items--;
		}

};


#endif 