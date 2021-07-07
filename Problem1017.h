//
// Created by Fengwei Zhang on 2021/7/7.
//

#ifndef ACWINGSOLUTION_PROBLEM1017_H
#define ACWINGSOLUTION_PROBLEM1017_H

#include <iostream>

using namespace std;

class Problem1017 {
public:
    int LIS(const int *items, int *dp, const int N) {
        int result = 0;
        for (int i = 0; i < N; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (items[j] >= items[i]) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        for (int i = N - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = N - 1; j > i; --j) {
                if (items[j] >= items[i]) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        return result;
    }

    int main() {
        auto items = new int[100];
        auto dp = new int[100];
        int k;
        scanf("%d", &k);
        for (int c = 0; c < k; ++c) {
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                scanf("%d", &items[i]);
            }
            printf("%d\n", LIS(items, dp, n));
        }
        delete[] items;
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1017_H
