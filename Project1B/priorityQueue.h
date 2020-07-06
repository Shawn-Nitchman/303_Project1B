#pragma once
#ifndef priorityQueue_H
#define priorityQueue_H
#include "Node.h";
#include <cstddef>
#include <string>


class prioQueue {
	private:

		Node* frontOfQueue;
		Node* backOfQueue;
		size_t num_items;

	public:
		
		prioQueue(Node* frontOfQueue = NULL, Node* backOfQueue = NULL) :
			frontOfQueue(frontOfQueue), backOfQueue(backOfQueue), num_items(0) {}

		void push(const string item) {
			if (frontOfQueue == NULL) {
				backOfQueue = new Node(item, NULL);
				frontOfQueue = backOfQueue;

				backOfQueue = new Node(item, NULL);
				frontOfQueue = backOfQueue;
			}
			else {
				backOfQueue->next = new Node(item, NULL);
				backOfQueue = backOfQueue->next;
			}
			num_items++;
		}

		string front() {
			return frontOfQueue->name;
		}

		int size() {
			return num_items;
		}

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