#pragma once
#include <string>

using namespace std;

struct Node {

	string name;

	Node* next;

	Node(string item, Node* nextPtr = NULL) {
		this->name = item;
		this->next = nextPtr;
	}
};