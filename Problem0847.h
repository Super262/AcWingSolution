//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0847_H
#define ACWINGSOLUTION_PROBLEM0847_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Problem0847
{
private:
    int bfs(const vector<vector<int>> &graph, int n)
    {
        queue<int> q;
        int current = 0;
        vector<bool> visited(n + 1, false); 
        
        q.emplace(1);
        visited[1] = true;
        
        while (!q.empty())
        {
            int q_size = (int)q.size();
            for (int i = 0; i < q_size; ++i)
            {
                int h = q.front();
                q.pop();
                if (h == n)
                    return current;
                for (const int &v : graph[h])
                {
                    if (visited[v])
                        continue;
                    q.emplace(v);
                    visited[v] = true;
                }
                
            }
            ++current;
        }
        
        return -1;
    }
    
    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1);
        for (int i = 0, x, y; i < m; ++i)
        {
            scanf("%d%d", &x, &y);
            graph[x].emplace_back(y);
        }
        printf("%d", bfs(graph, n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0847_H
