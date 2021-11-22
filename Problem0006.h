//
// Created by Fengwei Zhang on 2021/7/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0006_H
#define ACWINGSOLUTION_PROBLEM0006_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0006 {
    // https://www.acwing.com/solution/content/6500/
private:
    struct Item {
        int v, w, s;
    };

    int knapsack(Item items[], const int m, const int n) {
        int dp[2][m + 1];
        int q[m + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i) {
            auto v = items[i].v;
            auto w = items[i].w;
            auto s = items[i].s;
            for (int r = 0; r < v; ++r) {
                int hh = 0, tt = -1;
                for (int j = r; j <= m; j += v) {
                    while (hh <= tt && q[hh] < j - s * v) {
                        ++hh;
                    }
                    while (hh <= tt && dp[i % 2][q[tt]] - q[tt] / v * w <= dp[i % 2][j] - j / v * w) {
                        --tt;
                    }
                    q[++tt] = j;
                    dp[(i + 1) % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][q[hh]] + (j - q[hh]) / v * w);
                }
            }
        }
        return dp[n % 2][m];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        Item items[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &items[i].v, &items[i].w, &items[i].s);
        }
        printf("%d\n", knapsack(items, m, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0006_H
