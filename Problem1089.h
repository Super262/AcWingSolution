//
// Created by Fengwei Zhang on 2021/7/20.
//

#ifndef ACWINGSOLUTION_PROBLEM1089_H
#define ACWINGSOLUTION_PROBLEM1089_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1089 {
    // https://www.acwing.com/solution/content/27813/
public:
    int minCost(const int *cost, const int N, const int M) {
        auto dp = new int[N + 1];
        auto q = new int[2 * N];
        memset(dp, 0, sizeof(int) * (N + 1));
        memset(q, 0, sizeof(int) * 2 * N);
        dp[0] = 0;
        int hh = 0, tt = 0;  // 队列包含初始元素0
        for (int i = 1; i <= N; ++i) {
            while (hh <= tt && q[hh] < i - M) {
                ++hh;
            }
            dp[i] = dp[q[hh]] + cost[i];
            while (hh <= tt && dp[q[tt]] >= dp[i]) {
                --tt;
            }
            q[++tt] = i;
        }
        delete[] q;
        int result = 0x7f7f7f7f;
        for (int i = N - M + 1; i <= N; ++i) {
            result = min(result, dp[i]);
        }
        delete[] dp;
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        auto cost = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &cost[i]);
        }
        printf("%d\n", minCost(cost, n, m));
        delete[] cost;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1089_H
