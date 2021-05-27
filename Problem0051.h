//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0051_H
#define ACWINGSOLUTION_PROBLEM0051_H

#include <vector>

using namespace std;

class Problem0051 {

public:
    vector<vector<int>> permutation(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        do {
            result.emplace_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0051_H
