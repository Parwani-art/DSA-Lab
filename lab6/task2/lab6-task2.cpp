#include <iostream>
#include <limits>
#include "DoublyLinkedList.h"

using namespace std;

static bool readInt(const char* prompt, int& out) {
    cout << prompt;
    cin >> out;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer.\n";
        return false;
    }
    return true;
}

int main() {
    DoublyLinkedList<int> list;
    int choice;

    while (true) {
        cout << "\n   DOUBLY LINKED LIST (TEMPLATE) MENU    \n";
        cout << "1. Sorted Insert\n";
        cout << "2. Delete Value\n";
        cout << "3. Search\n";
        cout << "4. Traverse Forward\n";
        cout << "5. Traverse Backward\n";
        cout << "6. Clear List\n";
        cout << "7. Exit\n";

        if (!readInt("Enter choice: ", choice)) continue;

        if (choice == 1) {
            int value;
            if (!readInt("Enter value to insert: ", value)) continue;

            list.sortedInsert(value);

            cout << "\n--- Screenshot after INSERTION (Forward) ---\n";
            list.displayForward();
            cout << "--- Screenshot after INSERTION (Backward) ---\n";
            list.displayBackward();
        }
        else if (choice == 2) {
            int value;
            if (!readInt("Enter value to delete: ", value)) continue;

            bool deleted = list.deleteValue(value);

            if (deleted) cout << "\nDeleted successfully.\n";
            else cout << "\nValue not found.\n";

            cout << "\n--- Screenshot after DELETION (Forward) ---\n";
            list.displayForward();
            cout << "--- Screenshot after DELETION (Backward) ---\n";
            list.displayBackward();
        }
        else if (choice == 3) {
            int key;
            if (!readInt("Enter value to search: ", key)) continue;

            int pos = list.search(key);

            cout << "\n--- Screenshot after SEARCH ---\n";
            if (pos == -1) cout << "Element not found.\n";
            else cout << "Element found at position " << pos << ".\n";

            cout << "Current list (Forward):\n";
            list.displayForward();
        }
        else if (choice == 4) {
            cout << "\n--- Screenshot after TRAVERSING FORWARD ---\n";
            list.displayForward();
        }
        else if (choice == 5) {
            cout << "\n--- Screenshot after TRAVERSING BACKWARD ---\n";
            list.displayBackward();
        }
        else if (choice == 6) {
            list.clear();
            cout << "\nList cleared.\n";
            cout << "--- List now ---\n";
            list.displayForward();
        }
        else if (choice == 7) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}