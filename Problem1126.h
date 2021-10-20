//
// Created by Fengwei Zhang on 2021/7/28.
//

#ifndef ACWINGSOLUTION_PROBLEM1126_H
#define ACWINGSOLUTION_PROBLEM1126_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1126 {  // 算法正确性证明：将边的权重的乘运算转换为对数的加运算
private:
    double graph[2010][2010];

    double dijkstra(const int &start, const int &end, const int &n) {
        double dist[n + 1];
        bool selected[n + 1];
        memset(dist, 0, sizeof dist);
        memset(selected, 0, sizeof selected);
        dist[start] = 1;
        for (int k = 0; k < n; ++k) {
            auto closeV = -1;
            for (int v = 1; v <= n; ++v) {
                if (selected[v]) {
                    continue;
                }
                if (closeV == -1 || dist[v] > dist[closeV]) {
                    closeV = v;
                }
            }
            if (closeV == -1) {
                return 0;
            }
            selected[closeV] = true;
            for (int v = 1; v <= n; ++v) {
                dist[v] = max(dist[v], dist[closeV] * graph[closeV][v]);
            }
        }
        return dist[end];
    }

    int main() {
        memset(graph, 0, sizeof graph);
        int n, m;
        scanf("%d%d", &n, &m);
        int x, y, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            double t = (100.0 - w) / 100.0;
            graph[x][y] = max(graph[x][y], t);
            graph[y][x] = max(graph[y][x], t);
        }
        int s, e;
        scanf("%d%d", &s, &e);
        printf("%.8lf\n", 100.0 / dijkstra(s, e, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1126_H
