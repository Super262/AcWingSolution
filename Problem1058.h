//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM1058_H
#define ACWINGSOLUTION_PROBLEM1058_H

#include <iostream>

using namespace std;

class Problem1058 {
public:
    int maxValue(const int *arr, const int N) {
        auto dp = new int *[2];
        for (int i = 0; i < 2; ++i) {
            dp[i] = new int[3];
            for (int j = 0; j < 3; ++j) {
                dp[i][j] = -0x7f7f7f7f;
            }
        }
        dp[0][2] = 0;
        for (int i = 1; i <= N; ++i) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][2] - arr[i]);
            dp[i % 2][1] = dp[(i - 1) % 2][0] + arr[i];
            dp[i % 2][2] = max(dp[(i - 1) % 2][2], dp[(i - 1) % 2][1]);
        }
        int result = max(dp[N % 2][1], dp[N % 2][2]);
        for (int i = 0; i < 2; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int N;
        scanf("%d", &N);
        auto arr = new int[N + 1];
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", maxValue(arr, N));
        delete[] arr;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1058_H
