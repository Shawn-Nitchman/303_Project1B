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


/*
namespace CQ {

	template<typename Item_Type>
	class queue {
	public:
		queue() : capacity(DEFAULT_CAPACITY), num_items(0),
			front_index(0), rear_index(DEFAULT_CAPACITY - 1),
			the_data(new Item_Type[DEFAULT_CAPACITY]) {}

		queue(size_t capacity) : capacity(capacity), num_items(0),
			front_index(0), rear_index(capacity - 1),
			the_data(new Item_Type[capacity]) {}

		// Cost: O(1) (even on average when grows)
		void push(const Item_Type& item) {

			if (num_items == capacity) {
					reallocate();
				}

				num_items++;
				rear_index = (rear_index + 1) % capacity;
				the_data[rear_index] = item;
			}

			Item_Type& front() {
				return the_data[front_index];
			}

			void pop() {
				front_index = (front_index + 1) % capacity;
				num_items--;


			/*
			if (num_items == capacity)
				reallocate();

			int index = 0, i = 0, new_index = 0;

			for (unsigned int i = 0; i < num_items; ++i) {
				index = (front_index + 1) % capacity;
				if (item > the_data[index])
					break;
			}

			for (unsigned int j = 0; j < num_items - 1; ++j) {
				index = (rear_index - j) % capacity;
				new_index = (index + 1) % capacity;
				the_data[new_index] = the_data[index];
			}

			num_items++;
			the_data[(front_index + i) % capacity] = item;
			rear_index = (rear_index + 1) % capacity;

		}

		Item_Type& front() {
			return the_data[front_index];
		}

		void pop() {
			front_index = (front_index + 1) % capacity;
			num_items--;
		}


	private:
		void reallocate() {
			size_t new_capacity = 2 * capacity;
			Item_Type* new_data = new Item_Type[new_capacity];
			size_t j = front_index;
			for (size_t i = 0; i < num_items; i++) {
				new_data[i] = the_data[j];
				j = (j + 1) % capacity;
			}
			front_index = 0;
			rear_index = num_items - 1;
			capacity = new_capacity;
			std::swap(the_data, new_data);
			delete[] new_data;
		}


		// Data fields
		static const size_t DEFAULT_CAPACITY = 10;
		size_t capacity;
		size_t num_items;
		size_t front_index;
		size_t rear_index;
		Item_Type* the_data;
	};

};
*/

#endif 