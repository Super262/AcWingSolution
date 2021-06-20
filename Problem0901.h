//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0901_H
#define ACWINGSOLUTION_PROBLEM0901_H

#include <iostream>

using namespace std;

class Problem0901 {
public:
    int dfsLongestSlide(int **graph,
                        int **dp,
                        const int n,
                        const int m,
                        const int x,
                        const int y,
                        const int dx[4],
                        const int dy[4]) {
        if (dp[x][y]) {
            return dp[x][y];
        }
        dp[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || graph[nextX][nextY] >= graph[x][y]) {
                continue;
            }
            dp[x][y] = max(dp[x][y], 1 + dfsLongestSlide(graph, dp, n, m, nextX, nextY, dx, dy));
        }
        return dp[x][y];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        auto dp = new int *[n];
        auto graph = new int *[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = new int[m];
            graph[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                scanf("%d", &graph[i][j]);
                dp[i][j] = 0;
            }
        }
        int result = 0;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result = max(result, dfsLongestSlide(graph, dp, n, m, i, j, dx, dy));
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
