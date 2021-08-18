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

    int dijkstra(const int start, const int n) {
        auto dist = new int[n + 1];
        auto selected = new bool[n + 1];
        memset(dist, 0x7f, sizeof(int) * (n + 1));
        memset(selected, 0, sizeof(bool) * (n + 1));
        dist[start] = 0;
        for (int k = 1; k <= n; ++k) {
            int closestVertex = -1;
            for (int v = 1; v <= n; ++v) {
                if (!selected[v] && (closestVertex == -1 || dist[closestVertex] > dist[v])) {
                    closestVertex = v;
                }
            }
            if (closestVertex == -1) {
                return -1;
            }
            selected[closestVertex] = true;
            for (int v = 1; v <= n; ++v) {
                if (graph[closestVertex][v] == 0x7f7f7f7f) {
                    continue;
                }
                dist[v] = min(dist[v], dist[closestVertex] + graph[closestVertex][v]);
            }
        }
        int result = dist[n];
        delete[] dist;
        delete[] selected;
        return result == 0x7f7f7f7f ? -1 : result;
    }

    int main() {
        memset(graph, 0x7f, sizeof graph);
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            graph[x][y] = min(graph[x][y], w);
        }
        printf("%d\n", dijkstra(1, n));
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0849_H
