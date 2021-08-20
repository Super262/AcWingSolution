//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0854_H
#define ACWINGSOLUTION_PROBLEM0854_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0854 {
private:
    const int N = 210;
    const int INF = 0x7f7f7f7f;
    int dist[N][N];

    void floyd(const int n) {
        // 注意循环顺序：最外层循环的变量一定是中间节点
        // i, j 可以交换层级，k 只在最外层
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
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; ++i) {
            dist[i][i] = 0;
        }
        int a, b, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &w);
            dist[a][b] = min(dist[a][b], w);
        }
        floyd(n);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &a, &b);
            if (dist[a][b] == INF) {
                printf("impossible\n");
            } else {
                printf("%d\n", dist[a][b]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0854_H
