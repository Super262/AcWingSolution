//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0853_H
#define ACWINGSOLUTION_PROBLEM0853_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0853
{
private:
    struct Edge
    {
        int st, ed, w;
    };

    int bellman_ford(const int &st, const int &ed, const int &n, const int &k,
                     const Edge *edges, const int &m)
    {
        int dist[n + 1];
        int temp[n + 1];
        memset(dist, 0x3f, sizeof dist);
        dist[st] = 0;
        for (int i = 1; i <= k; ++i)
        {
            memcpy(temp, dist, sizeof temp);
            for (int j = 0; j < m; ++j)
            {
                const auto &e = edges[j];
                if (temp[e.st] == 0x3f3f3f3f)
                {
                    continue;
                }
                dist[e.ed] = min(dist[e.ed], temp[e.st] + e.w);
            }
        }
        return dist[ed];
    }

    int main()
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        Edge edges[m];
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &edges[i].st, &edges[i].ed, &edges[i].w);
        }
        auto ans = bellman_ford(1, n, n, k, edges, m);
        if (ans == 0x3f3f3f3f)
        {
            printf("impossible");
        }
        else
        {
            printf("%d\n", ans);
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0853_H
