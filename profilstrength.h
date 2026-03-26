............................profilstrength.h.............................................
  #ifndef PROFILE_STRENGTH_H
#define PROFILE_STRENGTH_H

#include <vector>
#include <string>

using namespace std;

class ProfileStrength {
public:
    double compute(const vector<string>& candidateSkills, const vector<string>& jobSkills);
};

#endif
