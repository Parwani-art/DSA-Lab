#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Disable copying
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // Check if list is empty
    bool isEmpty() const;

    // Get size of list
    int getSize() const;

    // Push - Insert at beginning
    void push(T value);

    // Pop - Remove from beginning
    T pop();

    // Insert after a specific value
    bool insertAfter(T afterValue, T newValue);

    // Delete first occurrence of value
    bool deleteValue(T value);

    // Display the list
    void display() const;

    // Clear entire list
    void clear();
};

// Template implementation must be in header file
template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template<typename T>
int LinkedList<T>::getSize() const {
    return size;
}

template<typename T>
void LinkedList<T>::push(T value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
}

template<typename T>
T LinkedList<T>::pop() {
    if (isEmpty()) {
        throw runtime_error("ERROR: the list is empty.");
    }

    Node* temp = head;
    T value = temp->data;
    head = head->next;
    delete temp;
    size--;
    return value;
}

template<typename T>
bool LinkedList<T>::insertAfter(T afterValue, T newValue) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == afterValue) {
            Node* newNode = new Node(newValue);
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<typename T>
bool LinkedList<T>::deleteValue(T value) {
    if (isEmpty()) {
        return false;
    }

    // If head node contains the value
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    // Search for the value
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }

    previous->next = current->next;
    delete current;
    size--;
    return true;
}

template<typename T>
void LinkedList<T>::display() const {
    if (isEmpty()) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

template<typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}
