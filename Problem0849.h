//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0849_H
#define ACWINGSOLUTION_PROBLEM0849_H

#include <vector>
#include <iostream>

class Problem0849 {
public:
    int dijkstra(const vector <vector<int>> &graph, const int n) {
        vector<int> distance(n + 1, 0x3f3f3f3f);
        vector<bool> visited(n + 1, false);
        distance[1] = 0;
        for (int k = 0; k < n; ++k) {
            int closestNode = -1;
            for (int node = 1; node <= n; ++node) {
                if (!visited[node] && (closestNode == -1 || distance[closestNode] > distance[node])) {
                    closestNode = node;
                }
            }
            visited[closestNode] = true;
            for (int node = 1; node <= n; ++node) {
                distance[node] = min(distance[node], distance[closestNode] + graph[closestNode][node]);
            }
        }
        return distance[n] == 0x3f3f3f3f ? -1 : distance[n];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector <vector<int>> graph(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
        int x, y, z;
        while (m--) {
            scanf("%d%d%d", &x, &y, &z);
            graph[x][y] = min(graph[x][y], z);
        }
        printf("%d\n", dijkstra(graph, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0849_H
