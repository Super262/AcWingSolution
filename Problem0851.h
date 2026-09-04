//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0851_H
#define ACWINGSOLUTION_PROBLEM0851_H

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Problem0851
{
private:
    bool spfa(int st, int ed, int n, const vector<vector<pair<int, int>>> &graph, int &answer)
    {
        queue<int> q;
        int *dist = (int *)malloc(sizeof(int) * (n + 1));
        bool *in_queue = (bool *)calloc(n + 1, sizeof(bool));
        bool *found = (bool *)calloc(n + 1, sizeof(bool));
        
        dist[st] = 0;
        found[st] = true;
        q.emplace(st);
        in_queue[st] = true;
        
        while (!q.empty())
        {
            int root = q.front();
            q.pop();
            in_queue[root] = false;
    
            for (const pair<int, int> &p : graph[root])
            {
                if (found[p.second])
                {
                    if (dist[p.second] > dist[root] + p.first)
                    {
                        dist[p.second] = dist[root] + p.first;
        
                        if (!in_queue[p.second])
                        {
                            q.emplace(p.second);
                            in_queue[p.second] = true;
                        }
                    }
                }
                else
                {
                    found[p.second] = true;
                    dist[p.second] = dist[root] + p.first;
                    
                    if (!in_queue[p.second])
                    {
                        q.emplace(p.second);
                        in_queue[p.second] = true;
                    }
                }
            }
        }
        
        free(in_queue);
        
        if (found[ed])
        {
            answer = dist[ed];
            free(dist);
            free(found);
            return true;
        }
    
        free(dist);
        free(found);
        return false;
    }
    
    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<pair<int, int>>> graph(n + 1);
        
        for (int i = 0, x, y, z; i < m; ++i)
        {
            scanf("%d%d%d", &x, &y, &z);
            graph[x].emplace_back(z, y);
        }
        
        int answer;
        if (spfa(1, n, n, graph, answer))
            printf("%d\n", answer);
        else
            printf("impossible\n");
    
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0851_H
