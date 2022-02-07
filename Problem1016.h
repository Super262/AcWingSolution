//
// Created by Fengwei Zhang on 2021/7/7.
//

#ifndef ACWINGSOLUTION_PROBLEM1016_H
#define ACWINGSOLUTION_PROBLEM1016_H

#include <iostream>

using namespace std;

class Problem1016 {
private:
    int maxSumLIS(const int *a, const int n) {
        int result = 0;
        int dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = a[i];
            for (int j = 0; j < i; ++j) {
                if (a[j] >= a[i]) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
            result = max(dp[i], result);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", maxSumLIS(a, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1016_H
