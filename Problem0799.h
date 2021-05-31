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
    unsigned long getMaxLen(const vector<int> &arr) {
        unsigned long result = 0;
        unordered_map<int, int> count;
        for (unsigned long right = 0, left = 0; right < arr.size(); ++right) {
            count[arr[right]] = (count.find(arr[right]) == count.end() ? 0 : count[arr[right]]) + 1;
            while (count[arr[right]] > 1) {
                count[arr[left]] = max(count[arr[left]] - 1, 0);
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<int> arr(n, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        printf("%ld\n", getMaxLen(arr));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0799_H
