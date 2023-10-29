//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0847_H
#define ACWINGSOLUTION_PROBLEM0847_H

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Problem0847
{
private:
    int bfs(const int root, const int target, const vector<vector<int>> &graph)
    {
        queue<int> q;
        int dist[graph.size()];
        memset(dist, -1, sizeof dist);
        dist[root] = 0;
        q.emplace(root);
        while (!q.empty())
        {
            auto current_level_size = (int)q.size();
            while (current_level_size--)
            {
                auto node = q.front();
                q.pop();
                if (node == target)
                {
                    return dist[node];
                }
                for (const auto &next_v : graph[node])
                {
                    if (dist[next_v] != -1)
                    {
                        continue;
                    }
                    q.emplace(next_v);
                    dist[next_v] = dist[node] + 1;
                }
            }
        }
        return dist[target];
    }

    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1);
        for (int i = 0, a, b; i < m; ++i)
        {
            scanf("%d%d", &a, &b);
            graph[a].emplace_back(b);
        }
        printf("%d\n", bfs(1, n, graph));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0847_H
