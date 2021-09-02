//
// Created by Fengwei Zhang on 2021/7/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0007_H
#define ACWINGSOLUTION_PROBLEM0007_H

#include <iostream>

using namespace std;

class Problem0007 {
private:
    struct Item {
        int v, w, s;
    };

    const int N = 1010;
    int dp[N];
    Item items[N];

    int knapsack(const int m, const int n) {
        for (int i = 0; i < n; ++i) {
            auto v = items[i].v;
            auto w = items[i].w;
            auto s = items[i].s;
            if (s == 0) {
                for (int j = v; j <= m; ++j) {
                    dp[j] = max(dp[j], dp[j - v] + w);
                }
            } else {
                if (s == -1) {
                    s = 1;
                }
                for (int factor = 1; factor <= s; factor *= 2) {
                    for (int j = m; j >= factor * v; --j) {
                        dp[j] = max(dp[j], dp[j - factor * v] + factor * w);
                    }
                    s -= factor;
                }
                if (s > 0) {
                    for (int j = m; j >= s * v; --j) {
                        dp[j] = max(dp[j], dp[j - s * v] + s * w);
                    }
                }
            }
        }
        return dp[m];
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

#endif //ACWINGSOLUTION_PROBLEM0007_H
