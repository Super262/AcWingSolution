//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0901_H
#define ACWINGSOLUTION_PROBLEM0901_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0901 {
public:
    int dfs(int **graph,
            int **dp,
            const int N,
            const int M,
            const int X,
            const int Y,
            const int dx[4],
            const int dy[4]) {
        if (dp[X][Y]) {
            return dp[X][Y];
        }
        dp[X][Y] = 1;
        for (int i = 0; i < 4; ++i) {
            auto nextX = dx[i] + X;
            auto nextY = dy[i] + Y;
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M || graph[nextX][nextY] >= graph[X][Y]) {
                continue;
            }
            dp[X][Y] = max(dp[X][Y], dfs(graph, dp, N, M, nextX, nextY, dx, dy) + 1);
        }
        return dp[X][Y];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        auto graph = new int *[n];
        for (int i = 0; i < n; ++i) {
            graph[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                scanf("%d", &graph[i][j]);
            }
        }
        auto dp = new int *[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = new int[m];
            memset(dp[i], 0, sizeof(int) * m);
        }
        int result = 0;
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                result = max(result, dfs(graph, dp, n, m, x, y, dx, dy));
            }
        }
        for (int i = 0; i < n; ++i) {
            delete[] dp[i];
            delete[] graph[i];
        }
        delete[] dp;
        delete[] graph;
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0901_H
