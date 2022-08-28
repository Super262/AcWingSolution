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

    static const int N = 1001, M = 500, K = 100;
    int dp[N][M];
    Item items[K];

    int knapsack(const int n, const int m1, const int m2) {
        for (int i = 0; i < n; ++i) {
            for (int j = m1; j >= items[i].v1; --j) {
                for (int k = m2 - 1; k >= items[i].v2; --k) {  // 注意细节：剩余的体力值必须大于1
                    dp[j][k] = max(dp[j][k], dp[j - items[i].v1][k - items[i].v2] + 1);
                }
            }
        }
        return dp[m1][m2 - 1];
    }

    int main() {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &items[i].v1, &items[i].v2);
        }
        int result = knapsack(k, n, m);
        // 牢记以下求解过程
        int min_cost = m - 1;
        while (min_cost - 1 >= 0 && dp[n][min_cost - 1] == result) {
            --min_cost;
        }
        printf("%d %d\n", result, m - min_cost);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1022_H
