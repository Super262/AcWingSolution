//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0848_H
#define ACWINGSOLUTION_PROBLEM0848_H

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Problem0848
{
private:
    vector<int> bfs(const int n, const vector<vector<int>> &graph, int *in_degree)
    {
        queue<int> q;
        vector<int> ans;
        for (int i = 1; i <= n; ++i)
        {
            if (in_degree[i])
            {
                continue;
            }
            q.emplace(i);
        }
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            ans.emplace_back(t);
            for (const auto &v : graph[t])
            {
                --in_degree[v];
                if (in_degree[v])
                {
                    continue;
                }
                q.emplace(v);
            }
        }
        return ans;
    }

    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1);
        int in_degree[n + 1];
        memset(in_degree, 0, sizeof in_degree);
        for (int i = 0, u, v; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            graph[u].emplace_back(v);
            ++in_degree[v];
        }
        auto ans = bfs(n, graph, in_degree);
        if (ans.size() != n)
        {
            printf("-1\n");
            return 0;
        }
        for (const auto &x : ans)
        {
            printf("%d ", x);
        }
        printf("\n");
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0848_H
