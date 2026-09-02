//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0846_H
#define ACWINGSOLUTION_PROBLEM0846_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Problem0846
{
private:
    int dfs(int root, int n, const vector<vector<int>> &graph, vector<bool> &visited, int &answer)
    {
        /*
        ** 第1步：标记当前节点
        ** 树是无向图（双向边），如果忘记这步，会造成无限搜索。
        */
        visited[root] = true;
        
        int max_comp = 0;
        int comp_size;
        int nodes_count = 1;
        
        for (const int &v : graph[root])
        {
            if (visited[v])
                continue;
            comp_size = dfs(v, n, graph, visited, answer);
            max_comp = max(max_comp, comp_size);
            nodes_count += comp_size;
        }
        
        max_comp = max(n - nodes_count, max_comp);
        answer = min(answer, max_comp);
        
        return nodes_count;
    }
    
    int main()
    {
        int n;
        scanf("%d", &n);
        vector<vector<int>> graph(n + 1);
        vector<bool> visited(n + 1, false);
        int answer = n;
    
        for (int i = 1, x, y; i < n; ++i)
        {
            scanf("%d%d", &x, &y);
            graph[x].emplace_back(y);
            graph[y].emplace_back(x);
        }
    
        dfs(n, n, graph, visited, answer);
        printf("%d\n", answer);
    
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0846_H
