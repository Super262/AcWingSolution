//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0861_H
#define ACWINGSOLUTION_PROBLEM0861_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Problem0861
{
private:
    bool has_matched(const int &u, const vector<vector<int>> &graph, int *friend_from_left, bool *right_visited)
    {
        for (const auto &v : graph[u])
        {
            if (right_visited[v])
            {
                continue;
            }
            right_visited[v] = true;
            if (friend_from_left[v] == 0 || has_matched(friend_from_left[v], graph, friend_from_left, right_visited))
            {
                friend_from_left[v] = u;
                return true;
            }
        }
        return false;
    }

    int main()
    {
        int n1, n2, m;
        scanf("%d%d%d", &n1, &n2, &m);
        vector<vector<int>> graph(n1 + 1);
        for (int i = 0, u, v; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            graph[u].emplace_back(v); // 这里我们只建立单向边
        }
        int friend_from_left[n2 + 1];
        bool right_visited[n2 + 1];
        int result = 0;
        memset(friend_from_left, 0, sizeof friend_from_left);
        for (int u = 1; u <= n1; ++u)
        {
            memset(right_visited, 0, sizeof right_visited);
            if (has_matched(u, graph, friend_from_left, right_visited))
            {
                ++result;
            }
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0861_H
