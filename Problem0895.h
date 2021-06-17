//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0895_H
#define ACWINGSOLUTION_PROBLEM0895_H

#include <iostream>

using namespace std;

class Problem0895 {
public:
    unsigned int longestAscendingSubsequence(const int *arr, const unsigned int n) {
        auto dp = new unsigned int[n];
        for (unsigned int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (unsigned int j = 0; j < i; ++j) {
                if (arr[j] >= arr[i]) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        unsigned int result = 0;
        for (unsigned int i = 0; i < n; ++i) {
            result = max(result, dp[i]);
        }
        delete[] dp;
        return result;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        auto arr = new int[n];
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", longestAscendingSubsequence(arr, n));
        delete[] arr;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0895_H
