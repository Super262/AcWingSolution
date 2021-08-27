//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0898_H
#define ACWINGSOLUTION_PROBLEM0898_H

#include <iostream>

using namespace std;

class Problem0898 {
private:
    const int N = 510;
    int dp[N][N];
    int matrix[N][N];

    int maxPath(const int n) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = -0x7f7f7f7f;
            }
        }
        dp[1][1] = matrix[1][1];
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
            }
        }
        int result = -0x7f7f7f7f;
        for (int i = 1; i <= n; ++i) {
            result = max(result, dp[n][i]);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }
        printf("%d\n", maxPath(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0898_H
