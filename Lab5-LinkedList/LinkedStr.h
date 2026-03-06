#pragma
#include <iostream>
using namespace std;

struct Node {
    int info;       // Data stored in node
    Node* next;     // Pointer to next node
};

class LinkedStr {
private:
    Node* ptr;      // Pointer to first node (head of list)

public:
    // Constructor - initialize ptr to NULL
    LinkedStr();

    // Destructor - remove all nodes from dynamic memory
    ~LinkedStr();

    // Create a linked structure of length len
    // Values are input from keyboard
    void makeStr(int len);

    // Display all elements on screen
    void displayStr();

    // Remove the first element
    // If structure is empty, do nothing
    void removeFirst();

    // Remove the last element   
    // If structure is empty, do nothing
    void removeLast();

    // Remove the first element with info field equal to k
    // If no such element or list is empty, do nothing
    void remove(int k);
};

