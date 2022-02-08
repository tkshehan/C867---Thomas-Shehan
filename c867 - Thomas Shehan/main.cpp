// C867 - Thomas Shehan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "roster.h"
#include "degree.h"

void populateRoster(Roster roster);

int main() {
    Roster classRoster;
    populateRoster(classRoster);


}

void populateRoster(Roster roster) {
    for (int i = 0; i < 5; ++i) {
        string studentString = roster.studentData[i];
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

        roster.add(studentData.at(0), studentData.at(1), studentData.at(2), studentData.at(3),
            stoi(studentData.at(4)), stoi(studentData.at(5)), stoi(studentData.at(6)), stoi(studentData.at(7)), degree);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
