//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM1049_H
#define ACWINGSOLUTION_PROBLEM1049_H

#include <iostream>

using namespace std;

class Problem1049 {
public:
    int robMaxValue(const int *arr, const int N) {
        auto dp = new int *[N + 1];
        for (int i = 0; i <= N; ++i) {
            dp[i] = new int[2];
        }
        dp[0][0] = 0;
        dp[0][1] = -1;
        for (int i = 1; i <= N; ++i) {
            if (dp[i - 1][1] == -1) {
                dp[i][0] = dp[i - 1][0];
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            }
            dp[i][1] = dp[i - 1][0] + arr[i];
        }
        int result = max(dp[N][0], dp[N][1]);
        for (int i = 0; i <= N; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int T;
        scanf("%d", &T);
        while (T--) {
            int N;
            scanf("%d", &N);
            auto arr = new int[N + 1];
            for (int i = 1; i <= N; ++i) {
                scanf("%d", &arr[i]);
            }
            printf("%d\n", robMaxValue(arr, N));
            delete[] arr;
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1049_H
