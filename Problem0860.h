//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0860_H
#define ACWINGSOLUTION_PROBLEM0860_H

#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

class Problem0860
{
private:
    bool bfs(int u,
             int *color,
             const vector<vector<int>> &graph)
    {
        queue<int> q;
        
        color[u] = 1;
        q.emplace(u);
        
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            
            for (const auto &v : graph[u])
            {
                if (color[v] &&
                    color[v] == color[u])
                    return false;
    
                if (!color[v])
                {
                    color[v] = 3 - color[u];
                    q.emplace(v);
                }
            }
        }

        return true;
    }

    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1);
        int *color = (int *)calloc(n + 1, sizeof(int));
        
        for (int i = 0, u, v; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }

        for (int i = 1; i <= n; ++i)
        {
            if (color[i])
                continue;

            if (!bfs(i, color, graph))
            {
                printf("No\n");
                free(color);
                return 0;
            }
        }

        printf("Yes\n");
        free(color);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0860_H
