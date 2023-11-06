//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0844_H
#define ACWINGSOLUTION_PROBLEM0844_H

#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

class Problem0844
{
    // 反向BFS：从终点搜索到起点，和正向搜索等价
private:
    int bfs(const int &n, const int &m, const int *matrix)
    {
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {-1, 0, 1, 0};
        bool visited[n * m];
        int result = 0;
        queue<int> q;
        memset(visited, 0, sizeof visited);
        q.emplace(0);
        visited[0] = true;
        while (!q.empty())
        {
            for (auto candidates_num = (int)q.size(); candidates_num > 0; --candidates_num)
            {
                auto root = q.front();
                q.pop();
                if (root / m == n - 1 && root % m == m - 1)
                {
                    return result;
                }
                for (int i = 0; i < 4; ++i)
                {
                    auto next_x = root / m + dx[i];
                    auto next_y = root % m + dy[i];
                    auto next_idx = next_x * m + next_y;
                    if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m ||
                        matrix[next_idx] == 1 || visited[next_idx])
                    {
                        continue;
                    }
                    q.emplace(next_idx);
                    visited[next_idx] = true;
                }
            }
            ++result;
        }
        return 0x7f7f7f7f;
    }

    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int matrix[n * m];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &matrix[i * m + j]);
            }
        }
        printf("%d\n", bfs(n, m, matrix));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0844_H
