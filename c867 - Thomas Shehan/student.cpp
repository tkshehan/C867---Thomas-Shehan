#include "student.h"
using namespace std;

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

void Student::setDaysToComplete(vector<int> daysInCourse) {
	this->daysToComplete = daysInCourse;
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
	// print what?
}

