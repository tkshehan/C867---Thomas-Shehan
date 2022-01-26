#include <iostream>
#include "student.h"
using namespace std;

Student::Student(string id, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degree) {
    this->studentId = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->daysToComplete = vector<int>{ days1, days2, days3 };
    this->degree = degree;
}

void Student::setStudentId(string id) {
    this->studentId = id;
}
string Student::getStudentId() const {
    return studentId;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
string Student::getFirstName() const {
    return firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
string Student::getLastName() const {
    return lastName;
}

void Student::setEmail(string email) {
    this->email = email;
}
string Student::getEmail() const {
    return email;
}

void Student::setAge(int age) {
    this->age = age;
}
int Student::getAge() const {
    return age;
}

void Student::setDaysToComplete(int days1, int days2, int days3) {
    this->daysToComplete = vector<int>{ days1, days2, days3 };
}
vector<int> Student::getDaysToComplete() const{
    return daysToComplete;
}

void Student::setDegree(DegreeProgram degree) {
    this->degree = degree;
}
DegreeProgram Student::getDegreeProgram() const {
    return degree;
}

void Student::print() {
    string daysPrint = "{" + to_string(daysToComplete.at(0)) + "," + to_string(daysToComplete.at(1))+ ","+ to_string(daysToComplete.at(2)) + "}";
    cout << studentId << "\t First Name: " << firstName << "\t Last Name: " << lastName << "\t Age: " << age << "\t daysInCourse: "
        << daysPrint << " Degree Program: " << degree; // Degree may need conversion to string
    // A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security
}

