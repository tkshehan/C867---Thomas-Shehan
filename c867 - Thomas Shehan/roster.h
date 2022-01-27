#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "student.h"
#include <string>
using namespace std;


class Roster {
public:
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
        int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);

    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);


private:
    const string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Thomas,Shehan,[emailaddress],33, [numberofdaystocomplete3courses],SOFTWARE"
    };
    Student *classRosterArray[];
};

#endif