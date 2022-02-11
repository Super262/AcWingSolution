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
    int knapsack(const int items[], const int n) {
        int m = 0;
        for (int i = 0; i < n; ++i) {  // 取最大值作为背包的容积
            m = max(m, items[i]);
        }
        int dp[m + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;  // 初始化
        for (int i = 0; i < n; ++i) {
            for (int j = items[i]; j <= m; ++j) {
                dp[j] += dp[j - items[i]];  // 统计每一项有几种组成方式
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[items[i]] != 1) {  // 统计只能由自身组成的项的个数
                continue;
            }
            ++result;
        }
        return result;
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n;
            scanf("%d", &n);
            int items[n];
            for (int i = 0; i < n; ++i) {
                scanf("%d", &items[i]);
            }
            printf("%d\n", knapsack(items, n));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0532_H
