//
// Created by Fengwei Zhang on 2021/7/6.
//

#ifndef ACWINGSOLUTION_PROBLEM1027_H
#define ACWINGSOLUTION_PROBLEM1027_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1027 {
    // dp[s][x1][x2] 表示从(1, 1)走到(x1, s - x1)和从(1, 1)走到(x2, s - x2)的两条路径的长度和的最大值
private:
    static const int N = 10;
    int dp[2][N + 1][N + 1];
    int graph[N + 1][N + 1];

    int maxPathsPair(const int n) {
        for (int s = 2; s <= 2 * n; ++s) {
            memset(dp[s % 2], 0, sizeof dp[s % 2]);
            for (int x1 = 1; x1 <= s - 1 && x1 <= n; ++x1) {
                for (int x2 = 1; x2 <= s - 1 && x2 <= n; ++x2) {
                    auto y1 = s - x1;
                    auto y2 = s - x2;
                    auto w = graph[x1][y1];
                    if (x1 != x2 && y1 != y2) {
                        w += graph[x2][y2];
                    }
                    dp[s % 2][x1][x2] = max(dp[s % 2][x1][x2], dp[(s - 1) % 2][x1][x2] + w);
                    dp[s % 2][x1][x2] = max(dp[s % 2][x1][x2], dp[(s - 1) % 2][x1][x2 - 1] + w);
                    dp[s % 2][x1][x2] = max(dp[s % 2][x1][x2], dp[(s - 1) % 2][x1 - 1][x2] + w);
                    dp[s % 2][x1][x2] = max(dp[s % 2][x1][x2], dp[(s - 1) % 2][x1 - 1][x2 - 1] + w);
                }
            }
        }
        return dp[(2 * n) % 2][n][n];
    }

    int main() {
        int n;
        scanf("%d", &n);
        while (true) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (a == 0 && b == 0 && c == 0) {
                break;
            }
            graph[a][b] = c;
        }
        printf("%d\n", maxPathsPair(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1027_H
