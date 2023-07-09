//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM0275_H
#define ACWINGSOLUTION_PROBLEM0275_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0275 {
    // https://www.acwing.com/solution/content/3954/
private:
    static const int N = 50;
    int graph[N + 1][N + 1];

    int maxValue(const int m, const int n) {
        int dp[m + 1][m + 1];
        memset(dp, 0, sizeof dp);
        for (int s = 2; s <= n + m; ++s) {
            for (auto x1 = min(m, s - 1); x1 >= 1; --x1) {
                for (auto x2 = min(m, s - 1); x2 >= 1; --x2) {
                    int v = graph[x1][s - x1];
                    if (x1 != x2) {
                        v += graph[x2][s - x2];
                    }
                    dp[x1][x2] = max(dp[x1][x2], dp[x1][x2] + v);
                    dp[x1][x2] = max(dp[x1][x2], dp[x1 - 1][x2] + v);
                    dp[x1][x2] = max(dp[x1][x2], dp[x1][x2 - 1] + v);
                    dp[x1][x2] = max(dp[x1][x2], dp[x1 - 1][x2 - 1] + v);
                }
            }
        }
        return dp[m][m];
    }

    int main() {
        int m, n;
        scanf("%d%d", &m, &n);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &graph[i][j]);
            }
        }
        printf("%d\n", maxValue(m, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0275_H
