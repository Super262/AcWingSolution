//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0853_H
#define ACWINGSOLUTION_PROBLEM0853_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0853 {
private:
    struct Edge {
        int st, ed, w;
    };

    int bellman_ford(int st, int ed, int n, int k, const Edge edges[], int m) {
        int dist[2][n + 1];
        memset(dist[0], 0x3f, sizeof dist[0]);
        dist[0][st] = 0;
        for (int i = 1; i <= k; ++i) {
            memcpy(dist[i % 2], dist[(i - 1) % 2], sizeof dist[(i - 1) % 2]);
            for (int j = 0; j < m; ++j) {
                const auto &e = edges[j];
                if (dist[(i - 1) % 2][e.st] == 0x3f3f3f3f) {
                    continue;
                }
                dist[i % 2][e.ed] = min(dist[i % 2][e.ed], dist[(i - 1) % 2][e.st] + e.w);
            }
        }
        return dist[k % 2][ed];
    }

    int main() {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        Edge edges[m];
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edges[i].st, &edges[i].ed, &edges[i].w);
        }
        auto res = bellman_ford(1, n, n, k, edges, m);
        if (res == 0x3f3f3f3f) {
            printf("impossible");
        } else {
            printf("%d\n", res);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0853_H
