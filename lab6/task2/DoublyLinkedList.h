#pragma once
#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        explicit Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Core operations
    void sortedInsert(const T& value);
    bool deleteValue(const T& value);
    int search(const T& key) const;

    // Traversal
    void displayForward() const;
    void displayBackward() const;

    // Utilities
    bool isEmpty() const;
    void clear();
    int getSize() const;
};

// Template implementation MUST be included here (only once)
#include "DoublyLinkedList.tpp"