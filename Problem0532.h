//
// Created by Fengwei Zhang on 2021/7/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0532_H
#define ACWINGSOLUTION_PROBLEM0532_H

#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

class Problem0532 {
private:
    int dp[25010];
    int items[110];

    int knapsack(const int n) {
        // 转化为完全背包问题
        memset(dp, 0, sizeof dp);
        sort(items, items + n);
        int result = 0;
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            if (dp[items[i]] == 0) {
                ++result;
            }
            for (int j = items[i]; j <= items[n - 1]; ++j) {
                dp[j] += dp[j - items[i]];
            }
        }
        return result;
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                scanf("%d", &items[i]);
            }
            printf("%d\n", knapsack(n));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0532_H
