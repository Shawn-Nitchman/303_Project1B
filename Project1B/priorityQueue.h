#pragma once
#ifndef priorityQueue_H
#define priorityQueue_H
#include "Node.h";

template<typename itemType>
class prioQueue {
public:
	
	prioPQueue() {};

	bool isempty() const;
	itemType& front() const;
	void pop();
	void push(const itemType& item);
	size_t size() const;

	Node* front = nullptr;
	Node* rear = nullptr;
private:
};

#endif 