//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0849_H
#define ACWINGSOLUTION_PROBLEM0849_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0849 {
private:
    const int N = 510;
    int graph[N][N];

    int dijkstra(const int start, const int end, const int n) {
        int dist[n + 1];
        bool selected[n + 1];
        memset(dist, 0x3f, sizeof dist);
        memset(selected, 0, sizeof selected);
        dist[start] = 0;
        for (int k = 0; k < n; ++k) {
            int closestV = -1;
            for (int v = 1; v <= n; ++v) {
                if (selected[v]) {
                    continue;
                }
                if (closestV == -1 || dist[v] < dist[closestV]) {
                    closestV = v;
                }
            }
            if (closestV == -1) {
                return -1;
            }
            selected[closestV] = true;
            for (int v = 1; v <= n; ++v) {
                dist[v] = min(dist[v], dist[closestV] + graph[closestV][v]);
            }
        }
        if (dist[end] == 0x3f3f3f3f) {
            return -1;
        }
        return dist[end];
    }

    int main() {
        memset(graph, 0x3f, sizeof graph);
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            graph[x][y] = min(graph[x][y], w);
        }
        printf("%d\n", dijkstra(1, n, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0849_H
