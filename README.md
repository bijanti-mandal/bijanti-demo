#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// ─────────────────────────────────────────────
// 1. ADMIN REPORT
// ─────────────────────────────────────────────
class AdminReport {
public:
    // ---------- Skill Demand Report ----------
    void skillDemandReport(const vector<string>& jobSkills) {
        map<string, int> skillCount;
        for (const string& skill : jobSkills) {
            skillCount[skill]++;
        }

        cout << "\n--- Skill Demand Report ---\n";
        for (auto& pair : skillCount) {
            cout << "Skill: " << pair.first << " | Demand: " << pair.second << endl;
        }
    }

    // ---------- Candidate Activity Report ----------
    void candidateActivityReport(const vector<string>& candidates, const vector<int>& activityCount) {
        cout << "\n--- Candidate Activity Report ---\n";
        for (size_t i = 0; i < candidates.size(); i++) {
            cout << "Candidate: " << candidates[i] << " | Activities: " << activityCount[i] << endl;
        }
    }

    // ---------- System Statistics ----------
    void systemStatistics(int totalCandidates, int totalJobs, int totalApplications) {
        cout << "\n--- System Statistics ---\n";
        cout << "Total Candidates: " << totalCandidates << endl;
        cout << "Total Jobs: " << totalJobs << endl;
        cout << "Total Applications: " << totalApplications << endl;
    }
};

// ─────────────────────────────────────────────
// 2. PROFILE STRENGTH
// ─────────────────────────────────────────────
class ProfileStrength {
public:
    // Basic formula: (matched skills / total job skills) * 100
    double compute(const vector<string>& candidateSkills, const vector<string>& jobSkills) {
        if (jobSkills.empty()) return 0.0;

        int matchedSkills = 0;
        for (const string& skill : jobSkills) {
            if (find(candidateSkills.begin(), candidateSkills.end(), skill) != candidateSkills.end()) {
                matchedSkills++;
            }
        }

        double strength = (double)matchedSkills / jobSkills.size() * 100;
        return strength;
    }
};

// ─────────────────────────────────────────────
// MAIN FUNCTION
// ─────────────────────────────────────────────
int main() {
    AdminReport admin;
    ProfileStrength ps;

    int nCandidates, nJobSkills, nCandidateSkills, nActivities;

    // ----- Input Job Skills -----
    cout << "Enter number of job skills: ";
    cin >> nJobSkills;
    cin.ignore(); // ignore newline
    vector<string> jobSkills(nJobSkills);
    for (int i = 0; i < nJobSkills; i++) {
        cout << "Enter job skill #" << i + 1 << ": ";
        getline(cin, jobSkills[i]);
    }

    // ----- Input Candidates -----
    cout << "\nEnter number of candidates: ";
    cin >> nCandidates;
    cin.ignore();
    vector<string> candidates(nCandidates);
    vector<int> activityCount(nCandidates);

    for (int i = 0; i < nCandidates; i++) {
        cout << "Enter candidate name #" << i + 1 << ": ";
        getline(cin, candidates[i]);

        cout << "Enter activity count for " << candidates[i] << ": ";
        cin >> activityCount[i];
        cin.ignore();
    }

    // ----- Input System Stats -----
    int totalJobs, totalApplications;
    cout << "\nEnter total number of jobs in system: ";
    cin >> totalJobs;
    cout << "Enter total number of applications in system: ";
    cin >> totalApplications;

    // ----- Display Admin Reports -----
    admin.skillDemandReport(jobSkills);
    admin.candidateActivityReport(candidates, activityCount);
    admin.systemStatistics(nCandidates, totalJobs, totalApplications);

    // ----- Profile Strength for Each Candidate -----
    cout << "\n--- Profile Strength Calculation ---\n";
    for (int i = 0; i < nCandidates; i++) {
        cout << "\nEnter number of skills for " << candidates[i] << ": ";
        cin >> nCandidateSkills;
        cin.ignore();
        vector<string> candidateSkills(nCandidateSkills);

        for (int j = 0; j < nCandidateSkills; j++) {
            cout << "Enter skill #" << j + 1 << ": ";
            getline(cin, candidateSkills[j]);
        }

        double strength = ps.compute(candidateSkills, jobSkills);
        cout << candidates[i] << "'s profile strength for the job: " << strength << "%\n";
    }

    return 0;
}