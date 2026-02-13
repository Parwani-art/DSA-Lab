#pragma once

class Student
{
private:
    char name[30];
    int lab[10];
    float average;
    int gradeCount;

public:
    Student();
    void setName(char n[]);
    void setGrade(int index, int grade);
    void setGradeCount(int count);
    void calculateAverage();

    char* getName();
    int getGrade(int index);
    float getAverage();
    int getGradeCount();

    void display();
};