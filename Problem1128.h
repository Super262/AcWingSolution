//
// Created by Fengwei Zhang on 2021/7/27.
//

#ifndef ACWINGSOLUTION_PROBLEM1128_H
#define ACWINGSOLUTION_PROBLEM1128_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1128 {
public:
    const int N = 100;
    const int INF = 0x7f7f7f7f;
    int dist[N + 1][N + 1];

    void floyd(const int n) {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dist[i][k] == INF || dist[k][j] == INF) {
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int main() {
        memset(dist, 0x7f, sizeof dist);
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            dist[a][b] = w;
            dist[b][a] = w;
        }
        floyd(n);
        int result = -1;
        for (int i = 1; i <= n; ++i) {
            if (dist[1][i] >= INF) {
                result = -1;
                break;
            }
            result = max(result, dist[1][i]);
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1128_H
