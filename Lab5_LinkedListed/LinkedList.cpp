
#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList<int> list;
    int choice, value, afterValue;

    cout << "=== LINKED LIST TEST PROGRAM ===" << endl;

    do {
        cout << "\n1. Push (insert at beginning)" << endl;
        cout << "2. Insert after a value" << endl;
        cout << "3. Delete a value" << endl;
        cout << "4. Pop (remove from beginning)" << endl;
        cout << "5. Display list" << endl;
        cout << "6. Check if empty" << endl;
        cout << "7. Exit" << endl;
        cout << "\nEnter choice: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.push(value);
                list.display();
                break;

            case 2:
                cout << "Enter value to insert after: ";
                cin >> afterValue;
                cout << "Enter new value: ";
                cin >> value;
                if (list.insertAfter(afterValue, value)) {
                    cout << "Value inserted successfully." << endl;
                }
                else {
                    cout << "ERROR: value " << afterValue << " not found in list." << endl;
                }
                list.display();
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                if (list.deleteValue(value)) {
                    cout << "Value deleted successfully." << endl;
                }
                else {
                    cout << "ERROR: value " << value << " not found in list." << endl;
                }
                list.display();
                break;

            case 4:
                value = list.pop();
                cout << "Popped value: " << value << endl;
                list.display();
                break;

            case 5:
                list.display();
                break;

            case 6:
                if (list.isEmpty()) {
                    cout << "List is empty." << endl;
                }
                else {
                    cout << "List is NOT empty." << endl;
                }
                break;

            case 7:
                cout << "\nExiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 7);

    return 0;
}
