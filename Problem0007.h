//
// Created by Fengwei Zhang on 2021/7/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0007_H
#define ACWINGSOLUTION_PROBLEM0007_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0007 {
private:
    struct Item {
        int v;
        int w;
        int s;
    };

    int knapsack(const Item items[], const int n, const int m) {
        int dp[m + 1];
        int temp[m + 1];
        int q[m + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i) {
            auto v = items[i].v;
            auto w = items[i].w;
            auto s = items[i].s;
            if (s == 0) {
                for (int j = v; j <= m; ++j) {
                    dp[j] = max(dp[j - v] + w, dp[j]);
                }
            } else {
                if (s == -1) {
                    s = 1;
                }
                memcpy(temp, dp, sizeof dp);
                for (int r = 0; r < v; ++r) {
                    int hh = 0;
                    int tt = -1;
                    for (int j = r; j <= m; j += v) {
                        while (hh <= tt && q[hh] < j - s * v) {
                            ++hh;
                        }
                        while (hh <= tt && temp[q[tt]] - q[tt] / v * w <= temp[j] - j / v * w) {
                            --tt;
                        }
                        q[++tt] = j;
                        dp[j] = max(dp[j], temp[q[hh]] + (j - q[hh]) / v * w);
                    }
                }
            }
        }
        return dp[m];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        Item items[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &items[i].v, &items[i].w, &items[i].s);
        }
        printf("%d\n", knapsack(items, n, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0007_H
