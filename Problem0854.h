//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0854_H
#define ACWINGSOLUTION_PROBLEM0854_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0854 {
public:
    void floyd(int **distance, const int n) {
        // 注意循环顺序：最外层循环的变量一定是中间节点
        // i, j 可以交换层级，k 只在最外层
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (distance[i][k] == 2147483647 || distance[k][j] == 2147483647) {
                        continue;
                    }
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

    int main() {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        auto distance = new int *[n + 1];
        for (int i = 1; i <= n; ++i) {
            distance[i] = new int[n + 1];
            for (int j = 1; j <= n; ++j) {
                distance[i][j] = i == j ? 0 : 2147483647;
            }
        }
        int x, y, z;
        while (m--) {
            scanf("%d%d%d", &x, &y, &z);
            distance[x][y] = min(distance[x][y], z);
        }
        floyd(distance, n);
        while (k--) {
            scanf("%d%d", &x, &y);
            if (distance[x][y] == 2147483647) {
                puts("impossible");
            } else {
                printf("%d\n", distance[x][y]);
            }
        }
        for (int i = 0; i <= n; ++i) {
            delete[] distance[i];
        }
        delete[] distance;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0854_H
