//
// Created by Fengwei Zhang on 2021/7/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0903_H
#define ACWINGSOLUTION_PROBLEM0903_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0903 {
private:
    const int N = 101;
    int graph[N][N];
    int level[N];

    int dijkstra(const int lowestLevel, const int highestLevel, const int start, const int end, const int n) {
        bool selected[n + 1];
        int dist[n + 1];
        memset(selected, 0, sizeof selected);
        memset(dist, 0x3f, sizeof dist);
        dist[start] = 0;
        for (int k = 1; k <= n + 1; ++k) {
            int closestNode = -1;
            for (int v = 0; v <= n; ++v) {
                if (!selected[v] && (closestNode == -1 || dist[v] < dist[closestNode])) {
                    closestNode = v;
                }
            }
            if (closestNode == -1) {
                break;
            }
            selected[closestNode] = true;
            for (int v = 0; v <= n; ++v) {
                if (level[v] < lowestLevel || level[v] > highestLevel) {
                    continue;
                }
                dist[v] = min(dist[v], dist[closestNode] + graph[closestNode][v]);
            }
        }
        return dist[end];
    }

    int main() {
        memset(graph, 0x3f, sizeof graph);
        int m, n;
        scanf("%d%d", &m, &n);
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
        int result = 0x3f3f3f3f;
        for (int l = level[1] - m; l <= level[1]; ++l) {
            result = min(result, dijkstra(l, l + m, 0, 1, n));
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0903_H
