//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0852_H
#define ACWINGSOLUTION_PROBLEM0852_H

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Problem0852
{
    // 1. 虚拟源点
    // 2. 最短路径经过的边数大于等于n，有负环
private:
    bool spfa(int n, const vector<vector<pair<int, int>>> &graph)
    {
        queue<int> q;
        int *dist = (int *)malloc(sizeof(int) * (n + 1));
        int *counter = (int *)malloc(sizeof(int) * (n + 1));
        bool *in_queue = (bool *)malloc(sizeof(bool) * (n + 1));
        bool answer = false;
        
        /* 初始化虚拟原点：所有点入队；所有路径初始长度为0、边数为1 */
        for (int i = 1; i <= n; ++i)
        {
            dist[i] = 0;
            counter[i] = 1;
            q.emplace(i);
            in_queue[i] = true;
        }
        
        while (!q.empty())
        {
            int root = q.front();
            q.pop();
            in_queue[root] = false;
    
            for (const pair<int, int> &p : graph[root])
            {
                if (dist[p.second] > dist[root] + p.first)
                {
                    /* 发现负环：前序路径边数为n */
                    if (counter[root] == n)
                    {
                        answer = true;
                        break;
                    }
    
                    dist[p.second] = dist[root] + p.first;
                    counter[p.second] = counter[root] + 1;
    
                    if (!in_queue[p.second])
                    {
                        q.emplace(p.second);
                        in_queue[p.second] = true;
                    }
                }
            }
            
            if (answer)
                break;
        }
        
        free(in_queue);
        free(counter);
        free(dist);
        return answer;
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

        if (spfa(n, graph))
            printf("Yes\n");
        else
            printf("No\n");
    
        return 0;
}
};

#endif // ACWINGSOLUTION_PROBLEM0852_H
