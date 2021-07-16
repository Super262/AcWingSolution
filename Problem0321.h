//
// Created by Fengwei Zhang on 2021/7/16.
//

#ifndef ACWINGSOLUTION_PROBLEM0321_H
#define ACWINGSOLUTION_PROBLEM0321_H

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Problem0321 {
    // https://www.acwing.com/solution/content/34369/
public:
    const int N = 8;
    const int M = 15;
    double dp[N + 1][N + 1][N + 1][N + 1][M];
    double prefixSum[N + 1][N + 1];
    double X = 0;

    double subSum(const int x1, const int y1, const int x2, const int y2) {
        auto sum = prefixSum[x2][y2] - prefixSum[x2][y1 - 1] - prefixSum[x1 - 1][y2] + prefixSum[x1 - 1][y1 - 1];
        sum -= X;
        return sum * sum;
    }

    double dfs(const int x1, const int y1, const int x2, const int y2, const int k) {
        if (dp[x1][y1][x2][y2][k] >= 0) {
            return dp[x1][y1][x2][y2][k];
        }
        if (k == 1) {
            dp[x1][y1][x2][y2][k] = subSum(x1, y1, x2, y2);
            return dp[x1][y1][x2][y2][k];
        }
        dp[x1][y1][x2][y2][k] = 0x7f7f7f7f;
        for (int i = x1; i < x2; ++i) {
            dp[x1][y1][x2][y2][k] = min(dp[x1][y1][x2][y2][k], dfs(x1, y1, i, y2, k - 1) + subSum(i + 1, y1, x2, y2));
            dp[x1][y1][x2][y2][k] = min(dp[x1][y1][x2][y2][k], subSum(x1, y1, i, y2) + dfs(i + 1, y1, x2, y2, k - 1));
        }
        for (int i = y1; i < y2; ++i) {
            dp[x1][y1][x2][y2][k] = min(dp[x1][y1][x2][y2][k], dfs(x1, y1, x2, i, k - 1) + subSum(x1, i + 1, x2, y2));
            dp[x1][y1][x2][y2][k] = min(dp[x1][y1][x2][y2][k], subSum(x1, y1, x2, i) + dfs(x1, i + 1, x2, y2, k - 1));
        }
        return dp[x1][y1][x2][y2][k];
    }

    int main() {
        int k;
        scanf("%d", &k);
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                scanf("%lf", &prefixSum[i][j]);
                prefixSum[i][j] += prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1];
            }
        }
        X = prefixSum[N][N] / k;
        memset(dp, -1, sizeof dp);
        printf("%.3lf\n", sqrt(dfs(1, 1, N, N, k) / k));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0321_H
