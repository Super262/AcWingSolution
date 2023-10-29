//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0858_H
#define ACWINGSOLUTION_PROBLEM0858_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Problem0858
{
private:
    static const int INF = 0x3f3f3f3f;

    int prim(const int &n, const vector<vector<int>> &graph)
    {
        int result = 0;
        int dist[n + 1];
        bool selected[n + 1];
        memset(dist, 0x3f, sizeof dist);
        memset(selected, 0, sizeof selected);
        for (int k = 1; k <= n; ++k)
        {
            int closest_v = -1;
            for (int v = 1; v <= n; ++v)
            {
                if (selected[v])
                {
                    continue;
                }
                if (closest_v == -1 || dist[closest_v] >= dist[v])
                {
                    closest_v = v;
                }
            }
            if (closest_v == -1)
            { // 不要忘记这个判断
                return INF;
            }
            if (k > 1 && dist[closest_v] == INF)
            { // 不要忘记这个判断
                return INF;
            }
            selected[closest_v] = true;
            if (k > 1)
            {
                result += dist[closest_v];
            }
            for (int v = 1; v <= n; ++v)
            {
                dist[v] = min(dist[v], graph[closest_v][v]);
            }
        }
        return result;
    }

    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
        for (int i = 0, u, v, w; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            graph[u][v] = min(graph[u][v], w);
            graph[v][u] = min(graph[v][u], w);
        }
        const auto &result = prim(n, graph);
        if (result == INF)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0858_H
