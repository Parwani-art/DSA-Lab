#include "DynamicQueue.h"
#include <iostream>
using namespace std;
// Default/Parameterized Constructor
template<class ItemType>
DynamicQueue<ItemType>::DynamicQueue(int maxSize) {
	capacity = maxSize;
	items = new ItemType[capacity];
	front = 0;
	rear = -1;
	count = 0;
}
// Copy Constructor
template<class ItemType>
DynamicQueue<ItemType>::DynamicQueue(const DynamicQueue& other) {
	CopyFrom(other);
}
// Destructor
template<class ItemType>
DynamicQueue<ItemType>::~DynamicQueue() {
	delete[] items;
}
// Copy helper function
template<class ItemType>
void DynamicQueue<ItemType>::CopyFrom(const DynamicQueue& other) {
	capacity = other.capacity;
	count = other.count;
	front = other.front;
	rear = other.rear;
	items = new ItemType[capacity];
	for (int i = 0; i < capacity; i++) {
		items[i] = other.items[i];
	}
}
// Assignment operator
template<class ItemType>
DynamicQueue<ItemType>& DynamicQueue<ItemType>::operator=(const
	DynamicQueue& other) {
	if (this != &other) {
		delete[] items;
		CopyFrom(other);
	}
	return *this;
}
// Check if queue is empty
template<class ItemType>
bool DynamicQueue<ItemType>::IsEmpty() const {
	return (count == 0);
}
// Check if queue is full
template<class ItemType>
bool DynamicQueue<ItemType>::IsFull() const {
	return (count == capacity);
}
// Enqueue operation
template<class ItemType>
void DynamicQueue<ItemType>::Enqueue(ItemType newItem) {
	if (IsFull()) {
		// Resize if needed (optional)
		Resize(capacity * 2);
	}
	rear = (rear + 1) % capacity;
	items[rear] = newItem;
	count++;
}
template < class ItemType>

void DynamicQueue<ItemType>::Dequeue(ItemType& item) {
	if (IsEmpty()) {
		cout << "Queue Underflow!" << endl;
		return;
	}
	item = items[front];
	front = (front + 1) % capacity;
	count--;
}
// Peek operation
template<class ItemType>
ItemType DynamicQueue<ItemType>::Peek() const {
	if (IsEmpty()) {
		cout << "Queue is empty!" << endl;
		return ItemType(); // Return default value
	}
	return items[front];
}
// Get current size
template<class ItemType>
int DynamicQueue<ItemType>::Size() const {
	return count;
}
// Get capacity
template<class ItemType>
int DynamicQueue<ItemType>::Capacity() const {
	return capacity;
}
// Display queue contents
template<class ItemType>
void DynamicQueue<ItemType>::Display() const {
	if (IsEmpty()) {
		cout << "Queue is empty!" << endl;
		return;
	}
	cout << "Queue (Front to Rear): ";
	for (int i = 0; i < count; i++) {
		int index = (front + i) % capacity;
		cout << items[index] << " ";
	}
	cout << endl;
}
// Resize queue capacity
template<class ItemType>
void DynamicQueue<ItemType>::Resize(int newCapacity) {
	if (newCapacity <= capacity) {
		return; // Only allow increasing size
	}
	ItemType* newItems = new ItemType[newCapacity];
	// Copy elements maintaining order
	for (int i = 0; i < count; i++) {
		int oldIndex = (front + i) % capacity;
		newItems[i] = items[oldIndex];
	}
	delete[] items;
	items = newItems;
	capacity = newCapacity;
	front = 0;
	rear = count - 1;
	cout << "Queue resized to capacity: " << capacity << endl;
}
//explicit template instantiations
template class DynamicQueue<int>;        //tell the compiler: “Generate the full code for
template class DynamicQueue<std::string>;//DynamicQueue<int> and DynamicQueue<std::string>