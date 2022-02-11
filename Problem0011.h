//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM0011_H
#define ACWINGSOLUTION_PROBLEM0011_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0011 {
private:
    struct Item {
        int v, w;

        Item() {
            v = 0;
            w = 0;
        }
    };

    int knapsack(Item items[], const int m, const int n) {
        const int MOD = 1000000007;
        int counter[m + 1];
        int dp[m + 1];
        memset(counter, 0, sizeof counter);
        memset(dp, 0, sizeof dp);
        counter[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = m; j >= items[i].v; --j) {
                auto maximal = max(dp[j], dp[j - items[i].v] + items[i].w);
                long count = 0;
                if (maximal == dp[j]) {
                    count += counter[j];
                    count %= MOD;
                }
                if (maximal == dp[j - items[i].v] + items[i].w) {
                    count += counter[j - items[i].v];
                    count %= MOD;
                }
                dp[j] = maximal;
                counter[j] = (int) count;
            }
        }
        long result = 0;
        auto maximal = dp[m];
        for (int i = 0; i <= m; ++i) {
            if (maximal != dp[i]) {
                continue;
            }
            result += counter[i];
            result %= MOD;
        }
        return (int) result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        Item items[n + 1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &items[i].v, &items[i].w);
        }
        printf("%d\n", knapsack(items, m, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0011_H
