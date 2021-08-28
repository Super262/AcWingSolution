//
// Created by Fengwei Zhang on 2021/7/9.
//

#ifndef ACWINGSOLUTION_PROBLEM1020_H
#define ACWINGSOLUTION_PROBLEM1020_H

#include <iostream>
#include <cstring>

using namespace std;

// https://www.acwing.com/solution/content/6485/

class Problem1020 {
    // “01背包”的改进：物品体积可以超过背包容量
    // 非法状态的值是0x3f3f3f3f
private:
    struct Item {
        int ox, ni, w;
    };

    const int M = 22, N = 80, K = 1000;
    int dp[M][N];  // dp[i][j]代表氧的容量不少于i、氮的容量不少于j时的最小重量
    Item items[K];

    int knapsack(const int m, const int n, const int k) {
        const int INF = 0x3f3f3f3f;
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;
        for (int d = 0; d < k; ++d) {
            for (int i = M - 1; i >= 0; --i) {
                for (int j = N - 1; j >= 0; --j) {
                    auto preI = max(i - items[d].ox, 0);
                    auto preJ = max(j - items[d].ni, 0);
                    dp[i][j] = min(dp[i][j], dp[preI][preJ] + items[d].w);
                }
            }
        }
        int result = INF;
        for (int i = M - 1; i >= m; --i) {
            for (int j = N - 1; j >= n; --j) {
                result = min(result, dp[i][j]);
            }
        }
        return result;
    }

    int main() {
        int m, n, k;
        scanf("%d%d%d", &m, &n, &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d%d", &items[i].ox, &items[i].ni, &items[i].w);
        }
        printf("%d\n", knapsack(m, n, k));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1020_H
