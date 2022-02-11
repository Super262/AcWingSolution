//
// Created by Fengwei Zhang on 2021/7/10.
//

#ifndef ACWINGSOLUTION_PROBLEM1019_H
#define ACWINGSOLUTION_PROBLEM1019_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1019 {
private:
    struct Item {
        int v, w, s;
    };

    static const int M = 500, N = 6001;
    Item items[M];
    int dp[N];
    int pre[N];
    int dq[N];

    int knapsack(const int m, const int n) {
        for (int i = 0; i < m; ++i) {
            memcpy(pre, dp, sizeof dp);
            auto v = items[i].v;
            auto w = items[i].w;
            auto s = items[i].s;
            for (int r = 0; r < v; ++r) {
                int hh = 0, tt = -1;
                for (int j = r; j <= n; j += v) {
                    while (hh <= tt && dq[hh] < j - s * v) {
                        ++hh;
                    }
                    while (hh <= tt && pre[dq[tt]] - dq[tt] / v * w <= pre[j] - j / v * w) {
                        --tt;
                    }
                    dq[++tt] = j;
                    dp[j] = max(dp[j], pre[dq[hh]] + (j - dq[hh]) / v * w);
                }
            }
        }
        return dp[n];
    }

    int main() {
        int m, n;
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &items[i].v, &items[i].w, &items[i].s);
        }
        printf("%d\n", knapsack(m, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1019_H
