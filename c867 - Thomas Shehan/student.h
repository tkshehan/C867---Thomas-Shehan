#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
#include <vector>
using namespace std;

class Student {
public:
    Student(string id, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degree);

    void setStudentId(string id);
    string getStudentId() const;

    void setFirstName(string firstName);
    string getFirstName() const;

    void setLastName(string lastName);
    string getLastName() const;

    void setEmail(string email);
    string getEmail() const;

    void setAge(int age);
    int getAge() const;

    void setDaysToComplete(int days1, int days2, int days3);
    vector<int> getDaysToComplete() const;

    void setDegree(DegreeProgram degree);
    DegreeProgram getDegreeProgram() const;

    void print();

private:
    string studentId;
    string firstName;
    string lastName;
    string email;
    int age;
    vector<int> daysToComplete;
    DegreeProgram degree;
};

#endif