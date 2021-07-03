//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0898_H
#define ACWINGSOLUTION_PROBLEM0898_H

#include <iostream>

using namespace std;


class Problem0898 {
public:
    int maxPath(int **matrix, const int n) {
        auto dp = new int*[n + 1];
        for (int i = 1; i <= n; ++i) {
            dp[i] = new int[i + 2];
            for (int j = 0; j < i + 2; ++j) {
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
        for (int i = 0; i < n + 2; ++i) {
            result = max(result, dp[n][i]);
        }
        for (int i = 1; i <= n; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto matrix = new int*[n + 1];
        for (int i = 1; i <= n; ++i) {
            matrix[i] = new int[i + 1];
            for (int j = 1; j <= i; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }
        printf("%d\n", maxPath(matrix, n));
        for (int i = 1; i <= n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0898_H
