//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0901_H
#define ACWINGSOLUTION_PROBLEM0901_H

#include <iostream>

using namespace std;

class Problem0901
{
    // 如果题意是寻找不增序列（相邻两项可以相等），动态规划思想失效（状态转移存在环），需使用图论中的最长路算法
    // 之所以使用DFS，是因为DFS会主动按照拓扑顺序搜索，遵循动态规划的思想
private:
    static const int N = 300;
    int f[N][N];
    int matrix[N][N];
    const int dx[4] = {0, 1, -1, 0};
    const int dy[4] = {1, 0, 0, -1};

    int dfs(const int &x, const int &y, const int &n, const int &m)
    {
        // 不要忘记递归退出条件！
        if (f[x][y])
        {
            return f[x][y];
        }
        f[x][y] = 1;
        for (int i = 0, nx, ny; i < 4; ++i)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || matrix[nx][ny] >= matrix[x][y])
            {
                continue;
            }
            f[x][y] = max(f[x][y], dfs(nx, ny, n, m) + 1);
        }
        return f[x][y];
    }

    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &matrix[i][j]);
            }
        }
        int res = 0;
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < m; ++y)
            {
                res = max(res, dfs(x, y, n, m));
            }
        }
        printf("%d\n", res);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0901_H
