//
// Created by Fengwei Zhang on 12/23/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1134_H
#define ACWINGSOLUTION_PROBLEM1134_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Problem1134 {
    // 可以基于BFS或Dijkstra（依照拓扑顺序搜索，距离一旦确定，不会再变化），不能使用SPFA或Bellman-Ford
private:
    vector<int> bfs(int st, const vector<vector<int>> &graph) {
        vector<int> dist(graph.size(), 0x3f3f3f3f);
        vector<int> count(graph.size(), 0);
        queue<int> q;
        dist[st] = 0;
        count[st] = 1;
        q.emplace(st);
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            for (const auto &nv: graph[root]) {
                if (dist[nv] > dist[root] + 1) {
                    count[nv] = count[root];
                    dist[nv] = dist[root] + 1;
                    q.emplace(nv);
                } else if (dist[nv] == dist[root] + 1) {
                    count[nv] = (count[root] + count[nv]) % 100003;
                }
            }
        }
        return count;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        auto result = bfs(1, graph);
        for (int v = 1; v <= n; ++v) {
            printf("%d\n", result[v]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1134_H
