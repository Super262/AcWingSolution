//
// Created by Fengwei Zhang on 2021/7/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0903_H
#define ACWINGSOLUTION_PROBLEM0903_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0903 {
public:
    const int N = 101;
    int graph[N][N];
    int level[N];
    int dist[N];
    bool visited[N];
    const int INF = 0x7f7f7f7f;

    int dijkstra(const int lowestLevel, const int highestLevel, const int n) {
        memset(visited, 0, sizeof(int) * (n + 1));
        memset(dist, 0x7f, sizeof(int) * (n + 1));
        dist[0] = 0;
        for (int k = 1; k <= n + 1; ++k) {
            int closestNode = -1;
            for (int v = 0; v <= n; ++v) {
                if (!visited[v] && (closestNode == -1 || dist[v] < dist[closestNode])) {
                    closestNode = v;
                }
            }
            if (closestNode == -1) {
                break;
            }
            visited[closestNode] = true;
            for (int v = 0; v <= n; ++v) {
                if (level[v] < lowestLevel || level[v] > highestLevel || graph[closestNode][v] == INF) {
                    continue;
                }
                dist[v] = min(dist[v], dist[closestNode] + graph[closestNode][v]);
            }
        }
        return dist[1];
    }

    int main() {
        memset(graph, 0x7f, sizeof graph);
        int m, n;
        scanf("%d%d", &m, &n);
        for (int i = 0; i <= n; ++i) {
            graph[i][i] = 0;
        }
        for (int idx = 1; idx <= n; ++idx) {
            int p, l, x;
            scanf("%d%d%d", &p, &l, &x);
            graph[0][idx] = min(graph[0][idx], p);
            level[idx] = l;
            while (x--) {
                int id, cost;
                scanf("%d%d", &id, &cost);
                graph[id][idx] = min(graph[id][idx], cost);
            }
        }
        int result = INF;
        for (int l = level[1] - m; l <= level[1]; ++l) {
            result = min(result, dijkstra(l, l + m, n));
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0903_H
