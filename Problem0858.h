//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0858_H
#define ACWINGSOLUTION_PROBLEM0858_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0858
{
private:
    bool prim(int *graph, bool *connected, int n, int *answer)
    {
        bool *selected = (bool *)calloc(n + 1, sizeof(bool));
        bool *reachable = (bool *)calloc(n + 1, sizeof(bool));
        int *dist = (int *)malloc(sizeof(int) * (n + 1));
        int temp_result = 0;
    
        /* Start from vertex 1 */
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
                if (!connected[closest_v * (n + 1) + i] || selected[i])
                    continue;
    
                if (!reachable[i])
                {
                    reachable[i] = true;
                    dist[i] = graph[closest_v * (n + 1) + i];
                }
                else
                    dist[i] = min(dist[i], graph[closest_v * (n + 1) + i]);
            }
        }
    
        *answer = temp_result;
    
        free(selected);
        free(reachable);
        free(dist);
        return true;
    }
    
    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        
        /* 用等体积的数组表示（映射）矩阵 */
        int *graph = (int *)malloc((n + 1) * (n + 1) * sizeof(int));
        bool *connected = (bool *)calloc((n + 1) * (n + 1), sizeof(bool));
    
        for (int i = 0, u, v, w; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            if (!connected[u * (n + 1) + v] ||
                !connected[v * (n + 1) + u])
            {
                graph[u * (n + 1) + v] = w;
                graph[v * (n + 1) + u] = w;
                connected[u * (n + 1) + v] = true;
                connected[v * (n + 1) + u] = true;
            }
            else
            {
                graph[u * (n + 1) + v] = min(w, graph[u * (n + 1) + v]);
                graph[v * (n + 1) + u] = graph[u * (n + 1) + v];
            }
        }
    
        int answer;
        if (prim(graph, connected, n, &answer))
            printf("%d\n", answer);
        else
            printf("impossible\n");
            
        free(graph);
        free(connected);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0858_H
