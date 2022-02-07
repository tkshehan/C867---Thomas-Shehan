#include "roster.h"



Roster::Roster() {
    this->classRosterArray = vector<Student>(0);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    Student newStudent = Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse1, daysInCourse3, degreeprogram);
    classRosterArray.push_back(newStudent);
}

void Roster::remove(string studentID) {
    bool foundID = false;
    for (int i = 0; !foundID || i < classRosterArray.size(); ++i) {
        if (classRosterArray.at(i).getStudentId() == studentID) {
            classRosterArray.erase(classRosterArray.begin() + i);
            foundID = true;
        }
    }
    if (!foundID) {
        cout << "Error: StudentID " << studentID <<  " not found";
    }
}

void Roster::printAll() {
    for (int i = 0; i < classRosterArray.size(); ++i) {
        classRosterArray.at(i).print();
        cout << endl;
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    bool foundID = false;
    vector<int> daysLeft;
    int totalDays = 0;

    for (int i = 0; !foundID || i < classRosterArray.size(); ++i) {
        if (classRosterArray.at(i).getStudentId() == studentID) {
            daysLeft = classRosterArray.at(i).getDaysToComplete();
            foundID = true;
        }
    }

    if (foundID) {
        for (int i = 0; i < daysLeft.size(); ++i) {
            totalDays += daysLeft.at(i);
        }
        cout << "Student " << studentID << " has an average of " << totalDays / daysLeft.size() << " days left.";
    } else {
        cout << "Error: StudentID " << studentID << " not found";
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < classRosterArray.size(); ++i) {
        string email = classRosterArray.at(i).getEmail();
        if (!validateEmail(email)) {
            cout << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    // prints out student information for a degree program specified by an enumerated type.
    // what is "student information"?
    cout << "Degree Program Noise, finish this function";
}

bool Roster::validateEmail(string email) {
    // Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
    // Validate Email
    return false;
}
