//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0005_H
#define ACWINGSOLUTION_PROBLEM0005_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0005 {
private:
    struct Item {
        int v;
        int w;
        int s;
    };

    int knapsack(Item items[], const int &n, const int &m) {
        int dp[m + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i) {
            auto v = items[i].v;
            auto w = items[i].w;
            auto s = items[i].s;
            for (int factor = 1; factor <= s; factor *= 2) {
                for (auto j = m; j >= factor * v; --j) {
                    dp[j] = max(dp[j], dp[j - factor * v] + factor * w);
                }
                s -= factor;
            }
            if (s > 0) {
                for (auto j = m; j >= s * v; --j) {
                    dp[j] = max(dp[j], dp[j - s * v] + s * w);
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

#endif //ACWINGSOLUTION_PROBLEM0005_H
