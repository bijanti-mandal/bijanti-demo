............................admin.cpp...............................
  #include "AdminReport.h"
#include <iostream>
#include <map>

using namespace std;

void AdminReport::skillDemandReport(const vector<string>& jobSkills) {
    map<string, int> skillCount;
    for (const string& skill : jobSkills) {
        skillCount[skill]++;
    }

    cout << "\n--- Skill Demand Report ---\n";
    for (auto& pair : skillCount) {
        cout << "Skill: " << pair.first << " | Demand: " << pair.second << endl;
    }
}

void AdminReport::candidateActivityReport(const vector<string>& candidates, const vector<int>& activityCount) {
    cout << "\n--- Candidate Activity Report ---\n";
    for (size_t i = 0; i < candidates.size(); i++) {
        cout << "Candidate: " << candidates[i] << " | Activities: " << activityCount[i] << endl;
    }
}

void…
