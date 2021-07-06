//
// Created by Fengwei Zhang on 2021/7/6.
//

#ifndef ACWINGSOLUTION_PROBLEM1015_H
#define ACWINGSOLUTION_PROBLEM1015_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1015 {
public:
    int maxPath(int **graph, int **dp, const int N, const int M) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + graph[i][j];
            }
        }
        return dp[N][M];
    }

    int main() {
        auto graph = new int *[101];
        auto dp = new int *[101];
        for (int i = 0; i < 101; ++i) {
            graph[i] = new int[101];
            dp[i] = new int[101];
            memset(dp[i], 0, sizeof(int) * 101);
        }
        int s;
        scanf("%d", &s);
        for (int k = 0; k < s; ++k) {
            int r, c;
            scanf("%d%d", &r, &c);
            for (int i = 1; i <= r; ++i) {
                for (int j = 1; j <= c; ++j) {
                    scanf("%d", &graph[i][j]);
                }
            }
            printf("%d\n", maxPath(graph, dp, r, c));
        }
        for (int i = 0; i < 101; ++i) {
            delete[] graph[i];
            delete[] dp[i];
        }
        delete[] graph;
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1015_H
