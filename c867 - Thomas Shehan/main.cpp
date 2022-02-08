#include <iostream>
#include "roster.h"
#include "degree.h"

int main() {
    Roster* classRoster;
    classRoster = new Roster();

    // Populate Roster
    for (int i = 0; i < 5; ++i) {
        string studentString = classRoster->studentData[i];
        vector<string> studentData(9);
        for (int i = 0; i < studentData.size(); ++i) {
            size_t position = studentString.find(',');
            studentData.at(i) = studentString.substr(0, position);
            studentString.erase(0, position + 1);
        }
        DegreeProgram degree;
        if (studentData.at(8) == "SOFTWARE") {
            degree = SOFTWARE;
        }
        else if (studentData.at(8) == "NETWORK") {
            degree = NETWORK;
        }
        else if (studentData.at(8) == "SECURITY") {
            degree = SECURITY;
        }

        classRoster->add(studentData.at(0), studentData.at(1), studentData.at(2), studentData.at(3),
            stoi(studentData.at(4)), stoi(studentData.at(5)), stoi(studentData.at(6)), stoi(studentData.at(7)), degree);
    }

    classRoster->printAll();
    classRoster->printInvalidEmails();
    
    // Loop Throught Students and print Average Days
    vector<Student*> students = classRoster->getClassRosterArray();
    for (int i = 0; i < students.size(); ++i) {
        classRoster->printAverageDaysInCourse(students.at(i)->getStudentId());
    }
    cout << endl;


    classRoster->printByDegreeProgram(SOFTWARE);

    classRoster->remove("A3");
    classRoster->printAll();

    classRoster->remove("A3");
    //expected: the above line should print a message saying such a student with this ID was not found.

    delete classRoster;
}
    
