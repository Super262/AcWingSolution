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
    bool has_matched(int u,
                     int stamp,
                     const vector<vector<int>> &graph,
                     int *friend_from_left,
                     int *right_visited)
    {
        for (const auto &v : graph[u])
        {
            if (right_visited[v] == stamp) // 检查时间戳
                continue;

            right_visited[v] = stamp;
            if (!friend_from_left[v] ||
                has_matched(friend_from_left[v], stamp, 
                            graph, friend_from_left,
                            right_visited))
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
        int *friend_from_left = (int *)calloc(n2 + 1, sizeof(int));
        int *right_visited = (int *)calloc(n2 + 1, sizeof(int));
        int result = 0;

        for (int i = 0, u, v; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            graph[u].emplace_back(v); // 这里我们只建立单向边
        }

        for (int u = 1, stamp = 0; u <= n1; ++u)
        {
            ++stamp;
            if (has_matched(u, stamp, graph,
                            friend_from_left, right_visited))
                ++result;
        }

        printf("%d\n", result);
        free(friend_from_left);
        free(right_visited);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0861_H
