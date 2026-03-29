//.............................admin.h................................
#ifndef ADMIN_REPORT_H
#define ADMIN_REPORT_H

#include <vector>
#include <string>

using namespace std;

class AdminReport {
public:
    void skillDemandReport(const vector<string>& jobSkills);
    void candidateActivityReport(const vector<string>& candidates, const vector<int>& activityCount);
    void systemStatistics(int totalCandidates, int totalJobs, int totalApplications);
};

#endif
