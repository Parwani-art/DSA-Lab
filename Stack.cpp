#include <iostream>
#include "Stack.h"
#include <stdexcept>
using namespace std;

Stack::Stack()
{
    top = 0;
    maxSize = 100;
    items = new ItemType[maxSize];
}

Stack::Stack(int size)
{
    top = 0;
    maxSize = size;
    items = new ItemType[maxSize];
}

Stack::~Stack()
{
    delete[] items;
}

int Stack::IsEmpty() const
{
    return top == 0;
}

int Stack::isFull() const
{
    return top == maxSize;
}

void Stack::push(ItemType newItem)
{
    if (isFull()) {
        throw overflow_error("Stack is full, cannot push");
    }
    items[top++] = newItem;
}

void Stack::Pop(ItemType& item)
{
    if (IsEmpty())
    {
        throw underflow_error("Stack is empty, cannot pop");
    }
    item = items[--top];
}
