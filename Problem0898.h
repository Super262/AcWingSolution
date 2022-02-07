//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0898_H
#define ACWINGSOLUTION_PROBLEM0898_H

#include <iostream>

using namespace std;

class Problem0898 {
private:
    static const int N = 510;
    int dp[2][N];
    int matrix[N][N];

    int maxPath(const int n) {
        memset(dp, -0x3f, sizeof dp);
        dp[1][1] = matrix[1][1];
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - 1]) + matrix[i][j];
            }
        }
        int result = -0x3f3f3f3f;
        for (int i = 1; i <= n; ++i) {
            result = max(result, dp[n % 2][i]);
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
