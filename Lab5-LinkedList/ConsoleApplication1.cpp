#include "LinkedStr.h"
#include <iostream>
using namespace std;

int main() {
    LinkedStr list;
    int choice, len, value;

    cout << "  LINKED STRUCTURE TEST PROGRAM  " << endl;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Create linked structure (makeStr)" << endl;
        cout << "2. Display linked structure" << endl;
        cout << "3. Remove first element" << endl;
        cout << "4. Remove last element" << endl;
        cout << "5. Remove specific value" << endl;
        cout << "6. Exit" << endl;
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter length of linked structure: ";
            cin >> len;
            list.makeStr(len);
            list.displayStr();
            break;

        case 2:
            list.displayStr();
            break;

        case 3:
            list.removeFirst();
            list.displayStr();
            break;

        case 4:
            list.removeLast();
            list.displayStr();
            break;

        case 5:
            cout << "Enter value to remove: ";
            cin >> value;
            list.remove(value);
            list.displayStr();
            break;

        case 6:
            cout << "\nExiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}