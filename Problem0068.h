//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0068_H
#define ACWINGSOLUTION_PROBLEM0068_H

#include <vector>
#include <unordered_set>

using namespace std;

class Problem0068 {
public:
    int getMissingNumber(vector<int> &nums) {
        unordered_set<int> s;
        for (int num = 0; num <= nums.size(); ++num) {
            s.insert(num);
        }
        for (int num : nums) {
            s.erase(num);
        }
        return *s.begin();
    }
};

#endif //ACWINGSOLUTION_PROBLEM0068_H
