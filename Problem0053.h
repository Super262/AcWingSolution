//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0053_H
#define ACWINGSOLUTION_PROBLEM0053_H

#include <vector>

using namespace std;

class Problem0053 {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(), input.end());
        if (k < input.size()) {
            input.erase(input.begin() + k, input.end());
        }
        return input;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0053_H
