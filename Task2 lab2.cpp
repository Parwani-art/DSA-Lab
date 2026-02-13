#include <iostream>
#include <fstream>
#include <cstring>
#include "Student.h"
using namespace std;

int main()
{
    Student students[100];
    char filename[50];
    int numStudents, numGrades;

    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    inputFile >> numStudents;
    inputFile >> numGrades;

    for (int i = 0; i < numStudents; i++)
    {
        char firstName[20], lastName[20];
        char fullName[40];

        inputFile >> firstName >> lastName;

        strcpy_s(fullName, 40, firstName);
        strcat_s(fullName, 40, " ");
        strcat_s(fullName, 40, lastName);

        students[i].setName(fullName);
        students[i].setGradeCount(numGrades);

        for (int j = 0; j < numGrades; j++)
        {
            int grade;
            inputFile >> grade;
            students[i].setGrade(j, grade);
        }

        students[i].calculateAverage();
    }

    inputFile.close();

    cout << "\nData loaded successfully!\n" << endl;

    int choice;

    while (true)
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Print all students information" << endl;
        cout << "2. Find a student" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\n===== All Students Information =====" << endl;
            for (int i = 0; i < numStudents; i++)
            {
                students[i].display();
            }
        }
        else if (choice == 2)
        {
            char searchName[40];
            char firstName[20], lastName[20];

            cout << "\nEnter student name (First Last): ";
            cin >> firstName >> lastName;

            strcpy_s(searchName, 40, firstName);
            strcat_s(searchName, 40, " ");
            strcat_s(searchName, 40, lastName);

            int found = 0;

            for (int i = 0; i < numStudents; i++)
            {
                if (strcmp(students[i].getName(), searchName) == 0)
                {
                    cout << "\nStudent found!" << endl;
                    cout << "------------------------" << endl;
                    students[i].display();
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                cout << "\nStudent not found!" << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "\nExiting program." << endl;
            break;
        }
        else
        {
            cout << "\nInvalid choice! Please try again." << endl;
        }
    }

    return 0;
}