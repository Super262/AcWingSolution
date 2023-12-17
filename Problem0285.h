//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0285_H
#define ACWINGSOLUTION_PROBLEM0285_H

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Problem0285
{
private:
    // f[u][0]：所有从以u为根的子树中选择，但不选择u的方案
    // f[u][1]：所有从以u为根的子树中选择，选择u的方案
    void dfs(const int &u, const vector<vector<int>> &graph, vector<vector<int>> &f, const int *happiness)
    {
        f[u][1] = happiness[u];
        for (const auto &v : graph[u])
        {
            dfs(v, graph, f, happiness);
            f[u][1] += f[v][0];
            f[u][0] += max(f[v][0], f[v][1]);
        }
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        int happiness[n + 1];
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &happiness[i]);
        }
        vector<vector<int>> graph(n + 1);
        bool has_father[n + 1];
        memset(has_father, 0, sizeof has_father);
        for (int i = 0, a, b; i < n - 1; ++i)
        {
            scanf("%d%d", &a, &b);
            graph[b].emplace_back(a); // 单向边：上司->职员
            has_father[a] = true;
        }
        int root = 1;
        while (has_father[root])
        {
            ++root;
        }
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        dfs(root, graph, f, happiness);
        printf("%d\n", max(f[root][0], f[root][1]));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0285_H
