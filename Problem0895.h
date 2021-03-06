//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0895_H
#define ACWINGSOLUTION_PROBLEM0895_H

#include <iostream>

using namespace std;

class Problem0895 {
public:
    int longestAscendingSubsequence(const int *arr, const int n) {
        auto dp = new int[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (arr[j] >= arr[i]) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, dp[i]);
        }
        delete[] dp;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto arr = new int[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", longestAscendingSubsequence(arr, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0895_H
