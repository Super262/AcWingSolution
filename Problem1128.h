//
// Created by Fengwei Zhang on 2021/7/27.
//

#ifndef ACWINGSOLUTION_PROBLEM1128_H
#define ACWINGSOLUTION_PROBLEM1128_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1128 {
private:
    const int N = 110;
    int dist[N][N];

    int floyd(const int n) {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int main() {
        memset(dist, 0x3f, sizeof dist);
        int n, m;
        scanf("%d%d", &n, &m);
        int x, y, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            dist[x][y] = dist[y][x] = w;
        }
        floyd(n);
        int result = -1;
        for (int i = 2; i <= n; ++i) {
            if (dist[1][i] == 0x3f3f3f3f) {
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
