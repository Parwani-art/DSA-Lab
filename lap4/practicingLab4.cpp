
#include <iostream>
#include "DynamicQueue.h"
using namespace std;
int main() {
	cout << "=== Testing Dynamic Queue with Templates ===" << endl;
	// Test with integers
	cout << "\n--- Integer Queue ---" << endl;
	DynamicQueue<int> intQueue(5);
	cout << "Enqueue 10 integers:" << endl;
	for (int i = 1; i <= 10; i++) {
		intQueue.Enqueue(i);
		cout << "Enqueued: " << i << " (Size: " << intQueue.Size()
			<< ", Capacity: " << intQueue.Capacity() << ")" << endl;
	}
	intQueue.Display();
	// Test with strings
	cout << "\n--- String Queue ---" << endl;
	DynamicQueue<string> strQueue(3);
	string names[] = { "Alice", "Bob", "Charlie", "David", "Eve" };
	for (int i = 0; i < 5; i++) {
		strQueue.Enqueue(names[i]);
		cout << "Enqueued: " << names[i] << " (Size: " <<
			strQueue.Size()
			<< ", Capacity: " << strQueue.Capacity() << ")" << endl;
	}
	strQueue.Display();
	// Test dequeue with strings
	cout << "\nDequeue 3 names:" << endl;
	string name;
	for (int i = 0; i < 3; i++) {
		strQueue.Dequeue(name);
		cout << "Dequeued: " << name << endl;
	}
	strQueue.Display();
	return 0;
}
