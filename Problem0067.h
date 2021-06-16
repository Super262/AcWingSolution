//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0067_H
#define ACWINGSOLUTION_PROBLEM0067_H

#include <vector>

using namespace std;

class Problem0067 {
public:
    int getNumberOfK(vector<int> &nums, int k) {
        int result = 0;
        for (auto i = nums.begin(); i < nums.end(); ++i) {
            result += *i == k ? 1 : 0;
        }
        return result;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0067_H
