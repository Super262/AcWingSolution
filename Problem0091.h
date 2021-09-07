//
// Created by Fengwei Zhang on 2021/6/19.
//

#ifndef ACWINGSOLUTION_PROBLEM0091_H
#define ACWINGSOLUTION_PROBLEM0091_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0091 {
private:
    const int N = 20;
    int graph[N][N];

    // dp[i][j]所有从0走到j，走过的点是i的所有路径中最短的路径的长度
    // 状态计算时利用倒数第二个点来分类
    int dp[1 << N][N];

    int shortestHamilton(const int n) {
        memset(dp, 0x3f, sizeof dp);
        const int LAST_STATE = (1 << n) - 1;
        dp[1][0] = 0;
        for (int p = 0; p <= LAST_STATE; ++p) {
            for (int s1 = 0; s1 < n; ++s1) {
                if (!((p >> s1) & 1)) {
                    continue;
                }
                for (int s0 = 0; s0 < n; ++s0) {
                    if (dp[p - (1 << s1)][s0] == 0x7f7f7f7f || graph[s0][s1] == 0x7f7f7f7f) {
                        continue;
                    }
                    dp[p][s1] = min(dp[p][s1], dp[p - (1 << s1)][s0] + graph[s0][s1]);
                }
            }
        }
        return dp[LAST_STATE][n - 1];
    }

    int main() {
        memset(graph, 0x7f, sizeof graph);
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &graph[i][j]);
            }
        }
        printf("%d\n", shortestHamilton(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0091_H
