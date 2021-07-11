//
// Created by Fengwei Zhang on 2021/7/11.
//

#ifndef ACWINGSOLUTION_PROBLEM1021_H
#define ACWINGSOLUTION_PROBLEM1021_H

#include <iostream>
#include <cstring>

class Problem1021 {
public:
    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        auto dp = new long long[m + 1];
        memset(dp, 0, sizeof(int) * (m + 1));
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int v;
            scanf("%d", &v);
            for (int j = v; j <= m; ++j) {
                dp[j] += dp[j - v];
            }
        }
        printf("%lld\n", dp[m]);
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1021_H
