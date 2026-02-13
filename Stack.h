#pragma once
typedef int ItemType;

class Stack
{
private:
    int top;
    int maxSize;
    ItemType* items;  

public:
    Stack();                    
    Stack(int size);           
    ~Stack();                  
    
    int IsEmpty() const;
    int isFull() const;
    void push(ItemType newItem);
    void Pop(ItemType& item);
};

