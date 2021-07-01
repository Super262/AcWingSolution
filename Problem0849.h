//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0849_H
#define ACWINGSOLUTION_PROBLEM0849_H

#include <vector>
#include <iostream>

class Problem0849 {
public:
    int dijkstra(const vector <vector<int>> &graph) {
        const int n = (int) graph.size() - 1;
        vector<int> distance(n + 1, 0x3f3f3f3f);
        vector<bool> visited(n + 1, false);
        distance[1] = 0;  // 不要忘记将起点距离设置为0！
        for (int i = 0; i < n; ++i) {
            int closestNode = -1;
            for (int v = 1; v <= n; ++v) {
                // 下面的判断条件：先判断是否重复访问，再判定距离！
                if (!visited[v] && (closestNode == -1 || distance[v] < distance[closestNode])) {
                    closestNode = v;
                }
            }
            if (closestNode == -1) {
                break;
            }
            visited[closestNode] = true;
            for (int v = 1; v <= n; ++v) {
                distance[v] = min(distance[v], distance[closestNode] + graph[closestNode][v]);
            }
        }
        return distance[n] == 0x3f3f3f3f ? -1 : distance[n];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector <vector<int>> graph(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
        int x, y, z;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &z);
            graph[x][y] = min(graph[x][y], z);
        }
        printf("%d\n", dijkstra(graph));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0849_H
