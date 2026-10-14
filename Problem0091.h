//
// Created by Fengwei Zhang on 2021/6/19.
//

#ifndef ACWINGSOLUTION_PROBLEM0091_H
#define ACWINGSOLUTION_PROBLEM0091_H

/*
状态压缩 Hamilton Path DP：

f(mask, v)：
    访问 mask 中所有点，
    最后停在 v 的最优值。

删除最后一个点：
    prevMask = mask ^ (1 << v)

枚举倒数第二个点 u：
    f(mask, v) = best(f(prevMask, u) + cost[u][v])

优化：
    1. lowbit 只枚举 mask 中存在的 v / u
    2. DP 使用连续一维数组
    3. 若起点固定为 0，可将 0 从 mask 中省略，
       状态数从 2^n 降为 2^(n-1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

class Problem0091
{
private:
    int main()
    {
        int n;
        scanf("%d", &n);
    
        int *_graph_ = (int *)malloc(sizeof(int) * n * n);
    
#define g(i, j) _graph_[(i) * n + (j)]
    
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &g(i, j));
    
        if (n == 1)
        {
            printf("0\n");
            free(_graph_);
            return 0;
        }
    
        /*
         * 城市 0 固定为起点，因此 mask 只记录城市 1...n-1。
         *
         * city v 对应 bit (v - 1)。
         */
        const int endpointCount = n - 1;
        const int maxMask = 1 << endpointCount;
        const int INF = 0x3f3f3f3f;
    
        /*
         * f(mask, v):
         * 从城市 0 出发，
         * 已访问 mask 中的所有城市，
         * 最后停在城市 v (v >= 1) 的最短距离。
         */
        int *_f_ = (int *)malloc(sizeof(int) * (size_t)maxMask * endpointCount);
        memset(_f_, 0x3f, sizeof(int) * (size_t)maxMask * endpointCount);
    
#define f(mask, v) _f_[(size_t)(mask) * endpointCount + ((v) - 1)]
    
        /*
         * Base case：
         * 只访问一个非起点城市 v。
         */
        for (int v = 1; v < n; ++v)
        {
            int bit = 1 << (v - 1);
            f(bit, v) = g(0, v);
        }
    
        for (int mask = 1; mask < maxMask; ++mask)
        {
            /*
             * 只枚举 mask 中存在的终点 v。
             */
            int vMask = mask;
    
            while (vMask)
            {
                int vBit = vMask & -vMask;
                int v = __builtin_ctz((unsigned)vBit) + 1;
    
                vMask &= vMask - 1;
    
                int prevMask = mask ^ vBit;
    
                /*
                 * 只有一个城市时已经初始化。
                 */
                if (!prevMask)
                    continue;
    
                int uMask = prevMask;
    
                /*
                 * 枚举倒数第二个城市 u。
                 */
                while (uMask)
                {
                    int uBit = uMask & -uMask;
                    int u = __builtin_ctz((unsigned)uBit) + 1;
    
                    uMask &= uMask - 1;
                    f(mask, v) = min(f(mask, v), f(prevMask, u) + g(u, v));
                }
            }
        }
    
        int answer = f(maxMask - 1, n - 1);
        printf("%d\n", answer);
    
#undef f
#undef g
    
        free(_f_);
        free(_graph_);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0091_H
