//
// Created by Fengwei Zhang on 2021/7/11.
//

#ifndef ACWINGSOLUTION_PROBLEM1021_H
#define ACWINGSOLUTION_PROBLEM1021_H

#include <iostream>

class Problem1021 {
private:
    static const int N = 15, M = 3010;
    int items[N];
    long long dp[M];

    // 注意：函数返回值可能超过int的表示范围
    long long knapsack(const int n, const int m) {
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (auto j = items[i]; j <= m; ++j) {
                dp[j] += dp[j - items[i]];
            }
        }
        return dp[m];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &items[i]);
        }
        printf("%lld\n", knapsack(n, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1021_H
