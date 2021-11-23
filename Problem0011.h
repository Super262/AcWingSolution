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
        int pathsNum[m + 1];
        int dp[m + 1];
        memset(pathsNum, 0, sizeof pathsNum);
        memset(dp, 0, sizeof dp);
        pathsNum[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = m; j >= items[i].v; --j) {
                int maxV = max(dp[j], dp[j - items[i].v] + items[i].w);
                long count = 0;
                if (maxV == dp[j]) {
                    count += pathsNum[j];
                    count %= MOD;
                }
                if (maxV == dp[j - items[i].v] + items[i].w) {
                    count += pathsNum[j - items[i].v];
                    count %= MOD;
                }
                dp[j] = maxV;
                pathsNum[j] = (int) count;
            }
        }
        long result = 0;
        int maxV = dp[m];
        for (int i = 0; i <= m; ++i) {
            if (maxV != dp[i]) {
                continue;
            }
            result += pathsNum[i];
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
