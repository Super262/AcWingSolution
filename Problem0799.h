//
// Created by Fengwei Zhang on 2021/6/1.
//

#ifndef ACWINGSOLUTION_PROBLEM0799_H
#define ACWINGSOLUTION_PROBLEM0799_H

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Problem0799 {
public:
    unsigned int longestUniqueSubsequence(const vector<int> &array) {
        if (array.empty()) {
            return 0;
        }
        unsigned int result = 0;
        unordered_map<int, unsigned int> count;
        for (unsigned int left = 0, right = 0; right < array.size(); ++right) {
            count[array[right]] = count.find(array[right]) == count.end() ? 1 : count[array[right]] + 1;
            while (left < right && count[array[right]] > 1) {
                --count[array[left]];
                ++left;
            }
            result = max(right - left + 1, result);
        }
        return result;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        vector<int> array(n, 0);
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d", &array[i]);
        }
        printf("%d\n", longestUniqueSubsequence(array));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0799_H
