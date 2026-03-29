//.........................profil strength.cpp.................................
#include "ProfileStrength.h"
#include <algorithm>

using namespace std;

double ProfileStrength::compute(const vector<string>& candidateSkills, const vector<string>& jobSkills) {
    if (jobSkills.empty()) return 0.0;

    int matchedSkills = 0;
    for (const string& skill : jobSkills) {
        if (find(candidateSkills.begin(), candidateSkills.end(), skill) != candidateSkills.end()) {
            matchedSkills++;
        }
    }

    return (double)matchedSkills / jobSkills.size() * 100;
}
