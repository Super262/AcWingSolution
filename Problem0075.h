//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0075_H
#define ACWINGSOLUTION_PROBLEM0075_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem0075 {
public:
    vector<int> findNumbersWithSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        auto left = nums.begin();
        auto right = nums.end() - 1;
        while (left < right) {
            if (*left + *right == target) {
                result.emplace_back(*left);
                result.emplace_back(*right);
                break;
            } else if (*left + *right < target) {
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0075_H
