//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM0734_H
#define ACWINGSOLUTION_PROBLEM0734_H

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem0734 {
    // sort将排列数优化为组合数，组合数就可以用背包了，妙啊（找到前后两项间的顺序关系，再排序）！
    // https://www.acwing.com/solution/content/4639/
    // dp[i]是花费时间恰好为i时获取的最大能量
private:
    struct Stone {
        int s, e, l;

        bool operator<(const Stone &b) const {
            return s * b.l < b.s * l;
        }
    };

    static const int N = 100;
    int dp[N * N + 10];
    Stone stones[N + 10];

    int knapsack(const int m, const int n) {
        sort(stones + 1, stones + n + 1);
        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = m; j >= stones[i].s; --j) {
                if (dp[j - stones[i].s] == -1) {
                    continue;
                }
                dp[j] = max(dp[j], dp[j - stones[i].s] + max(0, stones[i].e - (j - stones[i].s) * stones[i].l));
            }
        }
        int result = 0;
        for (int i = 0; i <= m; ++i) {
            result = max(result, dp[i]);
        }
        return result;
    }

    int main() {
        int t;
        scanf("%d", &t);
        for (int k = 1; k <= t; ++k) {
            int m = 0, n;
            scanf("%d", &n);
            for (int i = 1; i <= n; ++i) {
                scanf("%d%d%d", &stones[i].s, &stones[i].e, &stones[i].l);
                m += stones[i].s;
            }
            printf("Case #%d: %d\n", k, knapsack(m, n));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0734_H
