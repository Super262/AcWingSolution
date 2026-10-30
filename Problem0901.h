//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0901_H
#define ACWINGSOLUTION_PROBLEM0901_H

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

/*
AcWing 901 - 滑雪

严格下降关系构成 DAG：

    高 -> 低

如果需要每个节点的最长下降路径：
    需要 DP：
        f[v] = max(f[v], f[u] + 1)

如果只需要整张图的最长下降路径长度：
    f[] 可以完全省略。

做分层 Kahn 拓扑排序：

    每处理完一层：
        answer++

最终拓扑层数就是 DAG 最长路径长度。

时间：
    O(n * m)

空间：
    O(n * m)
*/

class Problem0901
{
    // 如果题意是寻找不增序列（相邻两项可以相等），动态规划思想失效（状态转移存在环），需使用图论中的最长路算法
    // 之所以使用DFS，是因为DFS会主动按照拓扑顺序搜索，遵循动态规划的思想
private:
    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
    
        const int total = n * m;
    
        int *height =
            (int *)malloc(sizeof(int) * total);
    
        int *indegree =
            (int *)calloc(total, sizeof(int));
    
        int *q =
            (int *)malloc(sizeof(int) * total);

#define ID(x, y) ((x) * m + (y))
#define H(x, y) height[ID(x, y)]
#define DEG(x, y) indegree[ID(x, y)]

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%d", &H(i, j));
    
        const int dx[4] = {1, -1, 0, 0};
        const int dy[4] = {0, 0, 1, -1};
    
        /*
         * 建边：
         *     高 -> 低
         *
         * 因此低点的 indegree + 1。
         */
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < m; ++y)
            {
                for (int d = 0; d < 4; ++d)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
    
                    if (nx < 0 || nx >= n ||
                        ny < 0 || ny >= m)
                    {
                        continue;
                    }
    
                    if (H(x, y) > H(nx, ny))
                        ++DEG(nx, ny);
                }
            }
        }
    
        int head = 0;
        int tail = 0;
    
        /*
         * DAG source：
         * 没有更高的邻居能够滑到这里。
         */
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < m; ++y)
            {
                if (DEG(x, y) == 0)
                    q[tail++] = ID(x, y);
            }
        }
    
        int answer = 0;
    
        /*
         * 分层 Kahn 拓扑排序。
         *
         * 每一层对应最长下降路径中的一个位置，
         * 因此最终层数就是 DAG 最长路径长度。
         */
        while (head < tail)
        {
            int levelEnd = tail;
    
            ++answer;
    
            while (head < levelEnd)
            {
                int id = q[head++];
    
                int x = id / m;
                int y = id % m;
    
                for (int d = 0; d < 4; ++d)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
    
                    if (nx < 0 || nx >= n ||
                        ny < 0 || ny >= m)
                    {
                        continue;
                    }
    
                    /*
                     * 只沿着下降边走。
                     */
                    if (H(nx, ny) >= H(x, y))
                        continue;
    
                    if (--DEG(nx, ny) == 0)
                        q[tail++] = ID(nx, ny);
                }
            }
        }
    
        printf("%d\n", answer);

#undef DEG
#undef H
#undef ID

        free(q);
        free(indegree);
        free(height);
    
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0901_H
