//
// Created by Fengwei Zhang on 2021/7/7.
//

#ifndef ACWINGSOLUTION_PROBLEM1016_H
#define ACWINGSOLUTION_PROBLEM1016_H

#include <iostream>

using namespace std;

class Problem1016 {
public:
    int maxSumLIS(const int *a, const int N) {
        int result = 0;
        auto dp = new int[N];
        for (int i = 0; i < N; ++i) {
            dp[i] = a[i];
            for (int j = 0; j < i; ++j) {
                if (a[j] >= a[i]) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
            result = max(dp[i], result);
        }
        delete[] dp;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto a = new int[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", maxSumLIS(a, n));
        delete[] a;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1016_H
