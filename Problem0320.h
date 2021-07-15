//
// Created by Fengwei Zhang on 2021/7/15.
//

#ifndef ACWINGSOLUTION_PROBLEM0320_H
#define ACWINGSOLUTION_PROBLEM0320_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0320 {
public:
    int maxValue(const int *weight, const int N) {
        auto dp = new int *[2 * N + 1];
        for (int i = 1; i <= 2 * N; ++i) {
            dp[i] = new int[2 * N + 1];
            memset(dp[i], 0, sizeof(int) * (2 * N + 1));
        }
        for (int length = 2; length <= N + 1; ++length) {
            for (int start = 1; start + length - 1 <= 2 * N; ++start) {
                int end = start + length - 1;
                for (int mid = start + 1; mid < end; ++mid) {
                    dp[start][end] = max(dp[start][end],
                                         dp[start][mid] + dp[mid][end] + weight[start] * weight[mid] * weight[end]);
                }
            }
        }
        int result = 0;
        for (int i = 1; i <= N; ++i) {
            result = max(result, dp[i][i + N]);
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto weight = new int[2 * n + 1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &weight[i]);
            weight[i + n] = weight[i];
        }
        printf("%d\n", maxValue(weight, n));
        delete[] weight;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0320_H
