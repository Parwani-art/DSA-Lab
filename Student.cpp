#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

Student::Student()
{
    name[0] = '\0';
    average = 0.0;
    gradeCount = 0;
    for (int i = 0; i < 10; i++) {
        lab[i] = 0;
    }
}

void Student::setName(char n[])
{
    strcpy_s(name, 30, n);
}

void Student::setGrade(int index, int grade)
{
    lab[index] = grade;
}

void Student::setGradeCount(int count)
{
    gradeCount = count;
}

void Student::calculateAverage()
{
    float sum = 0;
    for (int i = 0; i < gradeCount; i++) {
        sum += lab[i];
    }
    average = sum / gradeCount;
}

char* Student::getName()
{
    return name;
}

int Student::getGrade(int index)
{
    return lab[index];
}

float Student::getAverage()
{
    return average;
}

int Student::getGradeCount()
{
    return gradeCount;
}

void Student::display()
{
    cout << "Name: " << name << endl;
    cout << "Grades: ";
    for (int i = 0; i < gradeCount; i++) {
        cout << lab[i] << " ";
    }
    cout << endl;
    cout << "Average: " << average << endl;
    cout << "------------------------" << endl;
}