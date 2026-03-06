#include "LinkedStr.h"

// Constructor - initialize ptr to NULL
LinkedStr::LinkedStr() {
    ptr = nullptr;
}

// Destructor - remove all nodes from dynamic memory
LinkedStr::~LinkedStr() {
    Node* current = ptr;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    ptr = nullptr;
    cout << "Destructor called: All nodes deleted." << endl;
}

// Create a linked structure of length len
// Values are input from keyboard
void LinkedStr::makeStr(int len) {
    if (len <= 0) {
        cout << "Length must be positive." << endl;
        return;
    }

    // Clear existing list if any
    Node* current = ptr;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    ptr = nullptr;

    // Create new list
    cout << "Enter " << len << " values:" << endl;

    for (int i = 0; i < len; i++) {
        int value;
        cout << "Value " << (i + 1) << ": ";
        cin >> value;

        Node* newNode = new Node;
        newNode->info = value;
        newNode->next = nullptr;

        // If list is empty, make this the first node
        if (ptr == nullptr) {
            ptr = newNode;
        }
        else {
            // Otherwise, add to the end
            Node* temp = ptr;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    cout << "Linked structure created successfully." << endl;
}

// Display all elements on screen
void LinkedStr::displayStr() {
    if (ptr == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "List: ";
    Node* temp = ptr;
    while (temp != nullptr) {
        cout << temp->info;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

// Remove the first element
// If structure is empty, do nothing
void LinkedStr::removeFirst() {
    if (ptr == nullptr) {
        cout << "List is empty. Cannot remove first element." << endl;
        return;
    }

    Node* temp = ptr;
    ptr = ptr->next;
    delete temp;

    cout << "First element removed successfully." << endl;
}

// Remove the last element   
// If structure is empty, do nothing
void LinkedStr::removeLast() {
    if (ptr == nullptr) {
        cout << "List is empty. Cannot remove last element." << endl;
        return;
    }

    // If only one node
    if (ptr->next == nullptr) {
        delete ptr;
        ptr = nullptr;
        cout << "Last element removed successfully." << endl;
        return;
    }

    // Find second-to-last node
    Node* temp = ptr;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // Delete last node
    delete temp->next;
    temp->next = nullptr;

    cout << "Last element removed successfully." << endl;
}

// Remove the first element with info field equal to k
// If no such element or list is empty, do nothing
void LinkedStr::remove(int k) {
    if (ptr == nullptr) {
        cout << "List is empty. Cannot remove element." << endl;
        return;
    }

    // If first node contains k
    if (ptr->info == k) {
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
        cout << "Element " << k << " removed successfully." << endl;
        return;
    }

    // Search for k in the rest of the list
    Node* current = ptr;
    Node* previous = nullptr;

    while (current != nullptr && current->info != k) {
        previous = current;
        current = current->next;
    }

    // If k not found
    if (current == nullptr) {
        cout << "Element " << k << " not found in list." << endl;
        return;
    }

    // Remove the node containing k
    previous->next = current->next;
    delete current;

    cout << "Element " << k << " removed successfully." << endl;
}