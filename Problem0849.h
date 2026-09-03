//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0849_H
#define ACWINGSOLUTION_PROBLEM0849_H

#include <iostream>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Problem0849
{
private:
    int dijkstra(int st, int ed, const vector<vector<pair<int, int>>> &graph, int n)
    {
        int *dist = (int *)malloc(sizeof(int) * (n + 1));
        bool *selected = (bool *)calloc(n + 1, sizeof(bool));
        
        for (int i = 1; i <= n; ++i)
        {
            if (i == st)
                dist[st] = 0;
            else
                dist[i] = -1;
        }
        
        for (int k = 0; k < n; ++k)
        {
            int closest_v = -1;
            for (int i = 1; i <= n; ++i)
            {
                if (dist[i] == -1 || selected[i])
                    continue;
                if (closest_v == -1 || dist[i] < dist[closest_v])
                    closest_v = i;
            }
            
            if (closest_v == -1)
                continue;
            
            selected[closest_v] = true;
            for (const pair<int, int> &p : graph[closest_v])
            {
                if (dist[p.second] == -1)
                    dist[p.second] = dist[closest_v] + p.first;
                else
                    dist[p.second] = min(dist[p.second], dist[closest_v] + p.first);
            }
        }
        
        int result = dist[ed];
        free(selected);
        free(dist);
        return result;
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
        printf("%d\n", dijkstra(1, n, graph, n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0849_H
