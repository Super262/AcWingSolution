//
// Created by Fengwei Zhang on 2021/7/28.
//

#ifndef ACWINGSOLUTION_PROBLEM1126_H
#define ACWINGSOLUTION_PROBLEM1126_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1126 {
public:
    double **graph;

    double dijkstra(const int start, const int end, const int n) {
        auto dist = new double[n + 1];
        auto isSelected = new bool[n + 1];
        memset(dist, 0, sizeof(double) * (n + 1));
        memset(isSelected, 0, sizeof(bool) * (n + 1));
        dist[start] = 1;
        for (int k = 1; k <= n; ++k) {
            int closestNode = -1;
            for (int v = 1; v <= n; ++v) {
                if (!isSelected[v] && (closestNode == -1 || dist[v] > dist[closestNode])) {
                    closestNode = v;
                }
            }
            if (closestNode == -1) {
                break;
            }
            isSelected[closestNode] = true;
            for (int v = 1; v <= n; ++v) {
                dist[v] = max(dist[v], dist[closestNode] * graph[closestNode][v]);
            }
        }
        auto result = dist[end];
        delete[] dist;
        delete[] isSelected;
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        graph = new double *[n + 1];
        for (int i = 1; i <= n; ++i) {
            graph[i] = new double[n + 1];
            memset(graph[i], 0, sizeof(double) * (n + 1));
        }
        for (int i = 0; i < m; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            double z = (100.0 - w) / 100;
            graph[a][b] = max(graph[a][b], z);
            graph[b][a] = max(graph[b][a], z);
        }
        int start, end;
        scanf("%d%d", &start, &end);
        printf("%.8f\n", 100 / dijkstra(start, end, n));
        for (int i = 1; i <= n; ++i) {
            delete[] graph[i];
        }
        delete[] graph;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1126_H
