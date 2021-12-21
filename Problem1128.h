//
// Created by Fengwei Zhang on 2021/7/27.
//

#ifndef ACWINGSOLUTION_PROBLEM1128_H
#define ACWINGSOLUTION_PROBLEM1128_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Problem1128 {
private:
    int floyd(const int n, vector<vector<int>> &dist) {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
        int x, y, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            dist[x][y] = dist[y][x] = w;
        }
        floyd(n, dist);
        int result = -1;
        for (int end = 2; end <= n; ++end) {  // 注意：end不等于起点
            if (dist[1][end] == 0x3f3f3f3f) {
                result = -1;
                break;
            }
            result = max(result, dist[1][end]);
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1128_H
