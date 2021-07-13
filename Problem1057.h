//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM1057_H
#define ACWINGSOLUTION_PROBLEM1057_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1057 {
    // 一次交易：有货到无货，完整的一次买入卖出
public:
    int maxValue(const int *arr, const int N, const int k) {
        auto dp = new int **[2];
        for (int i = 0; i <= 1; ++i) {
            dp[i] = new int *[k + 1];
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = new int[2];
                dp[i][j][0] = -0x7f7f7f7f;
                dp[i][j][1] = -0x7f7f7f7f;
            }
        }
        dp[0][0][0] = 0;
        dp[1][0][0] = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i % 2][j][0] = max(dp[(i - 1) % 2][j][0], dp[(i - 1) % 2][j][1] + arr[i]);
                dp[i % 2][j][1] = max(dp[(i - 1) % 2][j][1], dp[(i - 1) % 2][j - 1][0] - arr[i]);
            }
        }
        int result = 0;
        for (int j = 1; j <= k; ++j) {
            result = max(result, dp[N % 2][j][0]);
        }
        for (int i = 0; i <= 1; ++i) {
            for (int j = 0; j <= k; ++j) {
                delete[] dp[i][j];
            }
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int N, k;
        scanf("%d%d", &N, &k);
        auto arr = new int[N + 1];
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", maxValue(arr, N, k));
        delete[] arr;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1057_H
