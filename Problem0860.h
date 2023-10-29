//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0860_H
#define ACWINGSOLUTION_PROBLEM0860_H

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Problem0860
{
private:
    bool dfs(int u, int val, vector<int> &color, const vector<vector<int>> &graph)
    {
        color[u] = val;
        for (const auto &v : graph[u])
        {
            if (color[v] == val)
            {
                return false;
            }
            if (!color[v] && !dfs(v, 3 - val, color, graph))
            {
                return false;
            }
        }
        return true;
    }

    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1);
        vector<int> color(n + 1, 0);
        for (int i = 0, u, v; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (color[i])
            {
                continue;
            }
            if (!dfs(i, 1, color, graph))
            {
                printf("No\n");
                return 0;
            }
        }
        printf("Yes\n");
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0860_H
