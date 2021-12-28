//
// Created by Fengwei Zhang on 2021/7/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0903_H
#define ACWINGSOLUTION_PROBLEM0903_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Problem0903 {
private:
    int Dijkstra(const int st,
                 const int ed,
                 const int n,
                 const int low_l,
                 const int high_l,
                 const vector<int> &level,
                 const vector<vector<int>> &graph) {
        if (st == ed) {
            return 0;
        }
        int dist[n];
        bool selected[n];
        memset(dist, 0x3f, sizeof dist);
        memset(selected, 0, sizeof selected);
        dist[st] = 0;
        for (int k = 1; k <= n; ++k) {
            int close_v = -1;
            for (int v = 0; v < n; ++v) {
                if (selected[v]) {
                    continue;
                }
                if (close_v == -1 || dist[v] < dist[close_v]) {
                    close_v = v;
                }
            }
            if (close_v == -1) {
                break;
            }
            selected[close_v] = true;
            for (int v = 0; v < n; ++v) {
                if (level[v] < low_l || level[v] > high_l) {
                    continue;
                }
                dist[v] = min(dist[v], dist[close_v] + graph[close_v][v]);
            }
        }
        return dist[ed];
    }

    int main() {
        int m, n;
        scanf("%d%d", &m, &n);
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
        vector<int> level(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int p, l, x;
            scanf("%d%d%d", &p, &l, &x);
            graph[0][i] = min(graph[0][i], p);
            level[i] = l;
            while (x--) {
                int j, cost;
                scanf("%d%d", &j, &cost);
                graph[j][i] = min(graph[j][i], cost);
            }
        }
        int result = 0x3f3f3f3f;
        for (int l = level[1] - m; l <= level[1]; ++l) {  // 枚举所有等级区间
            result = min(result, Dijkstra(0, 1, n + 1, l, l + m, level, graph));
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0903_H
