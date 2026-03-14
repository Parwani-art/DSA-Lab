#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() : head(nullptr)
{

}

LinkedList::~LinkedList() 
{
    clear();
}

void LinkedList::clear() 
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = nullptr;
}

bool LinkedList::isEmpty() const 
{
    return head == nullptr;
}

// Sorted insertion (ascending)
void LinkedList::sortedInsert(int value) 
{
    Node* newNode = new Node(value);

    if (head == nullptr || value < head->data)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data < value) 
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete first occurrence of value
bool LinkedList::deleteNode(int value) 
{
    if (head == nullptr) return false;

    if (head->data == value) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) 
    {
        temp = temp->next;
    }

    if (temp->next == nullptr) return false;

    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
    return true;
}

// Search: return position (1-based) or -1 if not found
int LinkedList::search(int key) const 
{
    Node* temp = head;
    int pos = 1;

    while (temp != nullptr) 
    {
        if (temp->data == key) return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

void LinkedList::display() const 
{
    if (head == nullptr) 
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}