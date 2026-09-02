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
    void bfs(int n, const vector<vector<int>> &graph, vector<int> &in_degree, vector<int> &answer)
    {
        queue<int> q;
        for (int i = 1; i <= n; ++i)
        {
            if (!in_degree[i])
                q.emplace(i);
        }
        
        while (!q.empty())
        {
            for (int q_size = (int) q.size(), h; q_size; --q_size)
            {
                h = q.front();
                q.pop();
                answer.emplace_back(h);
                for (const int &v: graph[h])
                {
                    --in_degree[v];
                    if (!in_degree[v])
                        q.emplace(v);
                }
            }
        }
    }
    
    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1);
        vector<int> in_degree(n + 1, 0);
        vector<int> answer;
    
        for (int i = 0, x, y; i < m; ++i)
        {
            scanf("%d%d", &x, &y);
            graph[x].emplace_back(y);
            ++in_degree[y];
        }
    
        answer.reserve(n);
        bfs(n, graph, in_degree, answer);
    
        if ((int)answer.size() == n)
        {
            for (const int &v : answer)
                printf("%d ", v);
            printf("\n");
        }
        else
            printf("-1\n");
    
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0848_H
