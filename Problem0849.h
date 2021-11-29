//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0849_H
#define ACWINGSOLUTION_PROBLEM0849_H

#include <iostream>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Problem0849 {
private:
    int dijkstra(int st, int ed, const int n, const vector<vector<int>> &graph) {
        int dist[n + 1];
        bool selected[n + 1];
        memset(dist, 0x3f, sizeof dist);
        memset(selected, 0, sizeof selected);
        dist[st] = 0;
        for (int k = 1; k <= n; ++k) {
            int closestV = -1;
            for (int v = 1; v <= n; ++v) {
                if (selected[v]) {
                    continue;
                }
                if (closestV == -1 || dist[closestV] > dist[v]) {
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
        if (dist[ed] == 0x3f3f3f3f) {
            return -1;
        }
        return dist[ed];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
        int u, v, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            graph[u][v] = min(graph[u][v], w);
        }
        printf("%d\n", dijkstra(1, n, n, graph));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0849_H
