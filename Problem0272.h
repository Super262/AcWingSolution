//
// Created by Fengwei Zhang on 2021/7/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0272_H
#define ACWINGSOLUTION_PROBLEM0272_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0272 {
public:
    int maxCommonLIS(const int *a, const int *b, const int N) {
        auto dp = new int *[N + 1];
        for (int i = 0; i <= N; ++i) {
            dp[i] = new int[N + 1];
            memset(dp[i], 0, sizeof(int) * (N + 1));
        }
        for (int i = 1; i <= N; ++i) {
            int maxPre = 0;
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (a[i] == b[j]) {
                    dp[i][j] = max(dp[i][j], maxPre + 1);
                } else if (b[j] < a[i]) {
                    maxPre = max(maxPre, dp[i][j]);
                }
            }
        }
        int result = 0;
        for (int i = 0; i <= N; ++i) {
            result = max(result, dp[N][i]);
        }
        for (int i = 0; i <= N; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto a = new int[n + 1];
        auto b = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &b[i]);
        }
        printf("%d\n", maxCommonLIS(a, b, n));
        delete[] a;
        delete[] b;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0272_H
