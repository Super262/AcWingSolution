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
    
        int *f =
            (int *)malloc(sizeof(int) * total);
    
        int *q =
            (int *)malloc(sizeof(int) * total);
    
#define ID(x, y) ((x) * m + (y))
#define H(x, y)  height[ID(x, y)]
#define DEG(x, y) indegree[ID(x, y)]
#define DP(x, y) f[ID(x, y)]
    
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &H(i, j));
                DP(i, j) = 1;
            }
        }
    
        const int dx[4] = {1, -1, 0, 0};
        const int dy[4] = {0, 0, 1, -1};
    
        /*
         * 建图方向：
         *
         * 高 -> 低
         *
         * 如果：
         *     H(x,y) > H(nx,ny)
         *
         * 则存在有向边：
         *     (x,y) -> (nx,ny)
         *
         * 所以低点 indegree + 1。
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
    
        /*
         * indegree == 0：
         *
         * 没有任何更高的相邻格子能滑到这里。
         *
         * 这些点就是 DAG 的拓扑起点。
         */
        int head = 0;
        int tail = 0;
    
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < m; ++y)
            {
                if (DEG(x, y) == 0)
                    q[tail++] = ID(x, y);
            }
        }
    
        int answer = 1;
    
        while (head < tail)
        {
            int id = q[head++];
    
            int x = id / m;
            int y = id % m;
    
            answer = max(answer, DP(x, y));
    
            /*
             * 枚举从当前高点可以滑到的低点。
             */
            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
    
                if (nx < 0 || nx >= n ||
                    ny < 0 || ny >= m)
                {
                    continue;
                }
    
                if (H(nx, ny) >= H(x, y))
                    continue;
    
                /*
                 * DAG 最长路 DP。
                 */
                DP(nx, ny) =
                    max(
                        DP(nx, ny),
                        DP(x, y) + 1
                    );
    
                /*
                 * 删除：
                 *     (x,y) -> (nx,ny)
                 */
                if (--DEG(nx, ny) == 0)
                    q[tail++] = ID(nx, ny);
            }
        }
    
        printf("%d\n", answer);
    
#undef DP
#undef DEG
#undef H
#undef ID
    
        free(q);
        free(f);
        free(indegree);
        free(height);
    
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0901_H
