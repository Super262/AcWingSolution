//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM1057_H
#define ACWINGSOLUTION_PROBLEM1057_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1057 {
    // 一次交易：有货到无货，完整的一次买入卖出（dp[i][j][1]表示第j此交易刚刚开始，dp[i][j - 1][0]表示第(j - 1)次交易刚刚结束）
    // 滚动数组优化
private:
    int stateMachine(const int items[], const int n, const int k) {
        int dp[2][k + 1][2];
        memset(dp, -0x3f, sizeof dp);
        dp[0][0][0] = 0;
        dp[1][0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i % 2][j][0] = max(dp[(i - 1) % 2][j][0], dp[(i - 1) % 2][j][1] + items[i]);
                dp[i % 2][j][1] = max(dp[(i - 1) % 2][j][1], dp[(i - 1) % 2][j - 1][0] - items[i]);
            }
        }
        int result = 0;
        for (int i = 0; i <= k; ++i) {
            result = max(dp[n % 2][i][0], result);
        }
        return result;
    }

    int main() {
        int n;
        int k;
        scanf("%d%d", &n, &k);
        int items[n + 1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &items[i]);
        }
        printf("%d\n", stateMachine(items, n, k));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1057_H
