//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0850_H
#define ACWINGSOLUTION_PROBLEM0850_H

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Problem0850
{
private:
    int dijkstra(int st, int ed, const vector<vector<pair<int, int>>> &graph, int n)
    {        
        /* 小根堆：{v, dist[v]}表示1到v的距离是dist[v] */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        bool *selected = (bool *)calloc(n + 1, sizeof(bool));
        int *dist = (int *)malloc((n + 1) * sizeof(int));
        int result;

        min_heap.emplace(0, st);
        dist[st] = 0;
        for (int i = 2 ; i <= n; ++i)
        {
            if (i != st)
                dist[i] = -1;  /* -1表示“断路” */
        }
        
        while (!min_heap.empty())
        {
            pair<int, int> p = min_heap.top();
            min_heap.pop();
    
            if (selected[p.second])
                continue;
            selected[p.second] = true;
    
            for (const pair<int, int> &np : graph[p.second])
            {
                if (dist[np.second] == -1)
                    dist[np.second] = dist[p.second] + np.first;
                else
                    dist[np.second] = min(dist[np.second], dist[p.second] + np.first);
                min_heap.emplace(dist[np.second], np.second);
            }
        }
        
        result = dist[ed];
        free(dist);
        free(selected);
        return result;
    }
    
    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        
        /* graph[x]中的{z, y}表示从x到y的长度为z的有向边 */
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

#endif // ACWINGSOLUTION_PROBLEM0850_H
