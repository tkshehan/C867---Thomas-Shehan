#include "roster.h"

Roster::Roster() {
    this->classRosterArray =  vector<Student*>(0);
}

vector<Student*> Roster::getClassRosterArray()
{
    return classRosterArray;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
    classRosterArray.push_back(newStudent);
}

void Roster::remove(string studentID) {
    bool foundID = false;
    for (int i = 0; !foundID && i < classRosterArray.size(); ++i) {
        if (classRosterArray.at(i)->getStudentId() == studentID) {
            delete classRosterArray.at(i);
            classRosterArray.erase(classRosterArray.begin() + i);
            foundID = true;
        }
    } 
    if (!foundID) {
        cout << "Error: StudentID " << studentID << " not found" << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i < classRosterArray.size(); ++i) {
        classRosterArray.at(i)->print();
        cout << endl;
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
    bool foundID = false;
    vector<int> daysLeft;
    int totalDays = 0;

    for (int i = 0; !foundID && i < classRosterArray.size(); ++i) {
        if (classRosterArray.at(i)->getStudentId() == studentID) {
            daysLeft = classRosterArray.at(i)->getDaysToComplete();
            foundID = true;
        }
    }

    if (foundID) {
        for (int i = 0; i < daysLeft.size(); ++i) {
            totalDays += daysLeft.at(i);
        }
        cout << "Student " << studentID << " has an average of " << totalDays / daysLeft.size() << " days left." << endl;
    } else {
        cout << "Error: StudentID " << studentID << " not found" << endl;
    }
}

void Roster::printInvalidEmails() {
    cout << "Invalid Emails:" << endl;
    for (int i = 0; i < classRosterArray.size(); ++i) {
        string email = classRosterArray.at(i)->getEmail();
        if (!isValidEmail(email)) {
            cout << email << endl;
        }
    }
    cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < classRosterArray.size(); ++i) {
        if (classRosterArray.at(i)->getDegreeProgram() == degreeProgram) {
            classRosterArray.at(i)->print();
            cout << endl;
        }
    }
    cout <<  endl;
}

bool Roster::isValidEmail(string email) {
    // Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
    bool hasAt = (email.find('@') != string::npos);
    bool hasPeriod = (email.find('.') != string::npos);
    bool hasSpace = (email.find(' ') != string::npos);

    return (hasAt && hasPeriod && !hasSpace);
}
