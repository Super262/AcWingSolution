//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM0275_H
#define ACWINGSOLUTION_PROBLEM0275_H

#include <iostream>

using namespace std;

class Problem0275 {
    // https://www.acwing.com/solution/content/3954/
private:
    const int N = 50;
    int graph[N + 1][N + 1];
    int dp[2 * N + 1][N + 1][N + 1];

    int maxValue(const int m, const int n) {
        for (int s = 2; s <= n + m; ++s) {
            for (int x1 = 1; x1 <= s - 1 && x1 <= m; ++x1) {
                for (int x2 = 1; x2 <= s - 1 && x2 <= m; ++x2) {
                    int v = graph[x1][s - x1];
                    if (x1 != x2) {
                        v += graph[x2][s - x2];
                    }
                    dp[s][x1][x2] = max(dp[s][x1][x2], dp[s - 1][x1][x2] + v);
                    dp[s][x1][x2] = max(dp[s][x1][x2], dp[s - 1][x1 - 1][x2] + v);
                    dp[s][x1][x2] = max(dp[s][x1][x2], dp[s - 1][x1][x2 - 1] + v);
                    dp[s][x1][x2] = max(dp[s][x1][x2], dp[s - 1][x1 - 1][x2 - 1] + v);
                }
            }
        }
        return dp[m + n][m][m];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &graph[i][j]);
            }
        }
        printf("%d\n", maxValue(n, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0275_H
