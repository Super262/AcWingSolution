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
    // “01背包”的改进：dp[i][j]表示氧气至少为i、氮气至少为j时的最小重量
    // 非法状态的值是0x3f3f3f3f
private:
    struct Item {
        int ox, ni, w;
    };

    int knapsack(Item items[], const int m, const int n, const int k) {
        int dp[m + 1][n + 1];
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;
        for (int d = 0; d < k; ++d) {
            for (int i = m; i >= 0; --i) {
                for (int j = n; j >= 0; --j) {
                    auto preI = max(0, i - items[d].ox);
                    auto preJ = max(0, j - items[d].ni);
                    dp[i][j] = min(dp[i][j], dp[preI][preJ] + items[d].w);
                }
            }
        }
        return dp[m][n];
    }

    int main() {
        int m, n, k;
        scanf("%d%d%d", &m, &n, &k);
        Item items[k];
        for (int i = 0; i < k; ++i) {
            scanf("%d%d%d", &items[i].ox, &items[i].ni, &items[i].w);
        }
        printf("%d\n", knapsack(items, m, n, k));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1020_H
