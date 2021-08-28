//
// Created by Fengwei Zhang on 2021/7/9.
//

#ifndef ACWINGSOLUTION_PROBLEM1022_H
#define ACWINGSOLUTION_PROBLEM1022_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1022 {
    // 包含2个代价关系的"01背包"问题
private:
    struct Item {
        int v1, v2;
    };

    const int N = 1001, M = 500, K = 100;
    int dp[N][M];
    Item items[K];

    int knapsack(const int n, const int pack1, const int pack2) {
        for (int i = 0; i < n; ++i) {
            for (int j = pack1; j >= items[i].v1; --j) {
                for (int k = pack2 - 1; k >= items[i].v2; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - items[i].v1][k - items[i].v2] + 1);
                }
            }
        }
        return dp[pack1][pack2 - 1];
    }

    int main() {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &items[i].v1, &items[i].v2);
        }
        int result = knapsack(k, n, m);
        int minCost = m - 1;
        while (minCost > 0 && dp[n][minCost - 1] == result) {
            --minCost;
        }
        printf("%d %d\n", result, m - minCost);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1022_H
