#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    cout << "Creating stack with default size (100)" << endl;
    Stack s1;

    cout << "\nPushing 10 items onto stack:" << endl;
    for (int i = 1; i <= 10; i++)
    {
        s1.push(i * 5);
        cout << "Pushed: " << i * 5 << endl;
    }

    cout << "\nPopping 5 items from stack:" << endl;
    int item;
    for (int j = 0; j < 5; j++)
    {
        s1.Pop(item);
        cout << "Popped: " << item << endl;
    }

    cout << "\nCreating anoter stack with size 5" << endl;
    Stack s2(5);

    cout << "Pushing items until stuck is full:" << endl;
    for (int i = 10; i <= 50; i += 10)
    {
        if (!s2.isFull()) {
            s2.push(i);
            cout << "Pushed: " << i << endl;
        }
    }

    cout << "\nChecking if stack is full: ";
    if (s2.isFull()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    cout << "\nPopping all items:" << endl;
    while (!s2.IsEmpty())
    {
        s2.Pop(item);
        cout << "Popped: " << item << endl;
    }

    cout << "\nChecking if stack is empty: ";
    if (s2.IsEmpty()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}
