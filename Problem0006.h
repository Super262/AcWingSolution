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

    Item items[1010];
    const int N = 20010;
    int dp[2][N];  // 滚动数组
    int dq[N];

    int knapsack(const int m, const int n) {
        for (int i = 0; i < n; ++i) {
            auto v = items[i].v;
            auto w = items[i].w;
            auto s = items[i].s;
            for (int r = 0; r < v; ++r) {
                int hh = 0, tt = -1;
                for (int j = r; j <= m; j += v) {
                    while (hh <= tt && dq[hh] < j - s * v) {
                        ++hh;
                    }
                    while (hh <= tt && dp[i % 2][dq[tt]] - dq[tt] / v * w <= dp[i % 2][j] - j / v * w) {
                        --tt;
                    }
                    dq[++tt] = j;
                    dp[(i + 1) % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][dq[hh]] + (j - dq[hh]) / v * w);
                }
            }
        }
        return dp[n % 2][m];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &items[i].v, &items[i].w, &items[i].s);
        }
        printf("%d\n", knapsack(m, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0006_H
