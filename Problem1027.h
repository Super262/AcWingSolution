//
// Created by Fengwei Zhang on 2021/7/6.
//

#ifndef ACWINGSOLUTION_PROBLEM1027_H
#define ACWINGSOLUTION_PROBLEM1027_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1027 {
public:
    int maxPathsPair(int **graph, const int n) {
        auto dp = new int **[2 * n + 1];
        for (int k = 1; k <= 2 * n; ++k) {
            dp[k] = new int *[n + 1];
            for (int i = 0; i <= n; ++i) {
                dp[k][i] = new int[n + 1];
                memset(dp[k][i], 0, sizeof(int) * (n + 1));
            }
        }
        for (int k = 2; k <= 2 * n; ++k) {
            for (int i1 = 1; i1 <= n; ++i1) {
                for (int i2 = 1; i2 <= n; ++i2) {
                    int j1 = k - i1;
                    int j2 = k - i2;
                    if (j1 < 1 || j2 < 1 || j1 > n || j2 > n) {
                        continue;
                    }
                    int w = graph[i1][j1];
                    if (i1 != i2) {
                        w += graph[i2][j2];
                    }
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1 - 1][i2 - 1] + w);
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1 - 1][i2] + w);
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1][i2 - 1] + w);
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1][i2] + w);
                }
            }
        }
        int result = dp[2 * n][n][n];
        for (int k = 1; k <= 2 * n; ++k) {
            for (int i = 0; i <= n; ++i) {
                delete[] dp[k][i];
            }
            delete[] dp[k];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto graph = new int *[n + 1];
        for (int i = 1; i <= n; ++i) {
            graph[i] = new int[n + 1];
            memset(graph[i], 0, sizeof(int) * (n + 1));
        }
        int x, y, value;
        while (true) {
            scanf("%d%d%d", &x, &y, &value);
            if (!x && !y && !value) {
                break;
            }
            graph[x][y] = value;
        }
        printf("%d\n", maxPathsPair(graph, n));
        for (int i = 1; i <= n; ++i) {
            delete[] graph[i];
        }
        delete[] graph;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1027_H
