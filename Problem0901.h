//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0901_H
#define ACWINGSOLUTION_PROBLEM0901_H

#include <iostream>

using namespace std;

class Problem0901 {
    // 如果题意是寻找不增序列（相邻两项可以相等），动态规划思想失效（状态转移存在环），需使用图论中的最长路算法
    // 之所以使用DFS，是因为DFS会主动按照拓扑顺序搜索，遵循动态规划的思想
private:
    static const int N = 300;
    int matrix[N][N];
    int dp[N][N];
    const int dx[4] = {0, 1, -1, 0};
    const int dy[4] = {1, 0, 0, -1};

    int dfs(const int x, const int y, const int n, const int m) {
        // 不要忘记递归退出条件！
        if (dp[x][y]) {
            return dp[x][y];
        }
        dp[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            auto nx = x + dx[i];
            auto ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || matrix[nx][ny] >= matrix[x][y]) {
                continue;
            }
            dp[x][y] = max(dp[x][y], dfs(nx, ny, n, m) + 1);
        }
        return dp[x][y];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res = max(res, dfs(i, j, n, m));
            }
        }
        printf("%d\n", res);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0901_H
