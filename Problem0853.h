//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0853_H
#define ACWINGSOLUTION_PROBLEM0853_H

#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

class Problem0853 {
private:
    struct Edge {
        int st, ed, w;
    };

    int bellman_ford(int st, int ed, int n, int k, const vector<Edge> &edges) {
        int dist[n + 1];
        int temp[n + 1];
        memset(dist, 0x3f, sizeof dist);
        memset(temp, 0x3f, sizeof temp);
        dist[st] = 0;
        while (k--) {
            memcpy(temp, dist, sizeof dist);
            for (const auto &e: edges) {
                if (temp[e.st] == 0x3f3f3f3f) {
                    continue;
                }
                dist[e.ed] = min(dist[e.ed], temp[e.st] + e.w);
            }
        }
        return dist[ed];
    }

    int main() {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector<Edge> edges(m);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edges[i].st, &edges[i].ed, &edges[i].w);
        }
        auto res = bellman_ford(1, n, n, k, edges);
        if (res == 0x3f3f3f3f) {
            printf("impossible");
        } else {
            printf("%d\n", res);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0853_H
