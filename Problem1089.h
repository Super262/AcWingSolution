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
    // dp[i]表示1～i满足要求且第i个被点燃
private:
    const int N = 200002;
    int q[N];
    int dp[N];
    int cost[N];

    int minCost(int n, int m) {
        dp[0] = 0;
        int hh = 0, tt = -1;
        q[++tt] = 0;
        for (int i = 1; i <= n; ++i) {
            while (hh <= tt && i - q[hh] + 1 > m + 1) {
                ++hh;
            }
            dp[i] = cost[i] + dp[q[hh]];
            while (hh <= tt && dp[i] <= dp[q[tt]]) {
                --tt;
            }
            q[++tt] = i;
        }
        int result = 0x7f7f7f7f;
        for (int i = n - m + 1; i <= n; ++i) {
            result = min(dp[i], result);
        }
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &cost[i]);
        }
        printf("%d\n", minCost(n, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1089_H
