//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0858_H
#define ACWINGSOLUTION_PROBLEM0858_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Problem0858
{
private:
    bool prim(const vector<vector<int>> &graph,
              const vector<vector<bool>> &connected,
              int n,
              int &answer)
    {
        bool *selected = (bool *)calloc(n + 1, sizeof(bool));
        bool *reachable = (bool *)calloc(n + 1, sizeof(bool));
        int *dist = (int *)malloc(sizeof(int) * (n + 1));
        int temp_result = 0;
    
        // Start from vertex 1
        reachable[1] = true;
        dist[1] = 0;
    
        for (int k = 0; k < n; ++k)
        {
            int closest_v = -1;
    
            for (int i = 1; i <= n; ++i)
            {
                if (selected[i] || !reachable[i])
                    continue;
    
                if (closest_v == -1 ||
                    dist[i] < dist[closest_v])
                {
                    closest_v = i;
                }
            }
    
            if (closest_v == -1)
            {
                free(selected);
                free(reachable);
                free(dist);
                return false;
            }
    
            selected[closest_v] = true;
            temp_result += dist[closest_v];
    
            for (int i = 1; i <= n; ++i)
            {
                if (!connected[closest_v][i] || selected[i])
                    continue;
    
                if (!reachable[i])
                {
                    reachable[i] = true;
                    dist[i] = graph[closest_v][i];
                }
                else
                    dist[i] = min(dist[i], graph[closest_v][i]);
            }
        }
    
        answer = temp_result;
    
        free(selected);
        free(reachable);
        free(dist);
        return true;
    }
    
    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
    
        vector<vector<int>> graph(n + 1, vector<int>(n + 1));
        vector<vector<bool>> connected(n + 1, vector<bool>(n + 1, false));
    
        for (int i = 0, u, v, w; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            if (!connected[u][v] || !connected[v][u])
            {
                graph[u][v] = w;
                graph[v][u] = w;
                connected[u][v] = true;
                connected[v][u] = true;
            }
            else
            {
                graph[u][v] = min(w, graph[u][v]);
                graph[v][u] = min(w, graph[v][u]);
            }
        }
    
        int answer;
        if (prim(graph, connected, n, answer))
            printf("%d\n", answer);
        else
            printf("impossible\n");
    
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0858_H
