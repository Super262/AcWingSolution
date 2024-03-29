//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0854_H
#define ACWINGSOLUTION_PROBLEM0854_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Problem0854
{
private:
    static const int INF = 0x3f3f3f3f;

    vector<vector<int>> floyd(const int &n, const vector<vector<int>> &graph)
    {
        vector<vector<int>> dist(graph);
        for (int i = 1; i <= n; ++i)
        { // 注意：起点和终点相同，距离为0
            dist[i][i] = 0;
        }
        for (int mid = 1; mid <= n; ++mid)
        {
            for (int st = 1; st <= n; ++st)
            {
                for (int ed = 1; ed <= n; ++ed)
                {
                    if (dist[st][mid] == INF || dist[mid][ed] == INF)
                    { // 排除负边的影响，INF恒为0x3f3f3f3f
                        continue;
                    }
                    dist[st][ed] = min(dist[st][ed], dist[st][mid] + dist[mid][ed]);
                }
            }
        }
        return dist;
    }

    int main()
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
        for (int i = 0, x, y, z; i < m; ++i)
        {
            scanf("%d%d%d", &x, &y, &z);
            graph[x][y] = min(graph[x][y], z);
        }
        auto dist = floyd(n, graph);
        for (int i = 0, a, b; i < k; ++i)
        {
            scanf("%d%d", &a, &b);
            if (dist[a][b] == INF)
            {
                printf("impossible\n");
            }
            else
            {
                printf("%d\n", dist[a][b]);
            }
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0854_H
