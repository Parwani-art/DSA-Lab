#pragma once

template<class ItemType>
class DynamicQueue {
private:
	ItemType* items; // Dynamic array for queue elements
	int front; // Index of front element
	int rear; // Index of rear element
	int count; // Number of elements in queue
	int capacity; // Maximum capacity of queue

public:
	// Constructors and destructor
	DynamicQueue(int maxSize = 100);
	DynamicQueue(const DynamicQueue& other); // Copy constructor
	~DynamicQueue();
	// Queue operations
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType newItem);
	void Dequeue(ItemType& item);
	ItemType Peek() const;
	int Size() const;
	int Capacity() const;
	void Display() const;
	// Utility functions
	void Resize(int newCapacity);
	DynamicQueue& operator=(const DynamicQueue& other); // Assignment operator
private:
		void CopyFrom(const DynamicQueue& other);

};

