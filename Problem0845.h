//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0845_H
#define ACWINGSOLUTION_PROBLEM0845_H

#include <string>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

class Problem0845
{
private:
    int bfs(const string &start, const string &end)
    {
        queue<string> q;
        unordered_map<string, int> dist;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        dist[start] = 0;
        q.emplace(start);
        while (!q.empty())
        {
            auto node = q.front();
            if (node == end)
            {
                return dist[node];
            }
            q.pop();
            auto placeholder_idx = (int)node.find('x');
            auto current_dist = dist[node];
            for (int i = 0; i < 4; ++i)
            {
                auto next_x = placeholder_idx / 3 + dx[i];
                auto next_y = placeholder_idx % 3 + dy[i];
                if (next_x < 0 || next_x >= 3 || next_y < 0 || next_y >= 3)
                {
                    continue;
                }
                swap(node[next_x * 3 + next_y], node[placeholder_idx]);
                if (dist.find(node) == dist.end())
                {
                    q.emplace(node);
                    dist[node] = current_dist + 1;
                }
                swap(node[next_x * 3 + next_y], node[placeholder_idx]);
            }
        }
        return -1;
    }

    int main()
    {
        string start(9, '\0');
        string end = "12345678x";
        for (int i = 0; i < 9; ++i)
        {
            cin >> start[i];
        }
        printf("%d\n", bfs(start, end));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0845_H
