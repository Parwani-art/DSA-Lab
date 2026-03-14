#pragma once
#include"Node.h"

class LinkedList
{
private:
	Node* head;
public:
	LinkedList();
	~LinkedList();

	void clear();
	bool isEmpty() const;

	void sortedInsert(int value);
	bool deleteNode(int value);
	int search(int key) const;	// returns position (1-based) or -1
	void display() const;

};
