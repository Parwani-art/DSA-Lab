#include <iostream>
#include <limits>
#include "LinkedList.h"

using namespace std;

static bool readInt(const char* prompt, int& out) 
{
    cout << prompt;
    cin >> out;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer.\n";
        return false;
    }
    return true;
}

int main() 
{
    LinkedList list;
    int choice;

    while (true) 
    {
        cout << "\n----- MENU -----\n";
        cout << "1. Sorted Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Traverse (Display)\n";
        cout << "5. Clear List\n";
        cout << "6. Exit\n";

        if (!readInt("Enter choice: ", choice)) continue;

        if (choice == 1) {
            int value;
            if (!readInt("Enter value: ", value)) continue;
            list.sortedInsert(value);
            cout << "Inserted.\n";
        }
        else if (choice == 2) 
        {
            int value;
            if (!readInt("Enter value to delete: ", value)) continue;
            if (list.deleteNode(value)) cout << "Node deleted.\n";
            else cout << "Value not found.\n";
        }
        else if (choice == 3)
        {
            int value;
            if (!readInt("Enter value to search: ", value)) continue;
            int pos = list.search(value);
            if (pos == -1) cout << "Element not found.\n";
            else cout << "Element found at position " << pos << ".\n";
        }
        else if (choice == 4) 
        {
            list.display();
        }
        else if (choice == 5)
        {
            list.clear();
            cout << "List cleared.\n";
        }
        else if (choice == 6)
        {
            cout << "Exiting program...\n";
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}