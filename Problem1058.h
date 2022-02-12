//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM1058_H
#define ACWINGSOLUTION_PROBLEM1058_H

#include <iostream>

using namespace std;

class Problem1058 {
    // 状态机（最大收益）：dp[i][1]（手中有货），dp[i][2]（手中无货的第1天），dp[i][0]（手中无货的第2天及以后）
private:
    int stateMachine(const int items[], const int n) {
        int dp[2][3];
        memset(dp, -0x3f, sizeof dp);
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][2], dp[(i - 1) % 2][0]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][0] - items[i], dp[(i - 1) % 2][1]);
            dp[i % 2][2] = dp[(i - 1) % 2][1] + items[i];
        }
        return max(dp[n % 2][0], dp[n % 2][2]);
    }

    int main() {
        int n;
        scanf("%d", &n);
        int items[n + 1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &items[i]);
        }
        printf("%d\n", stateMachine(items, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1058_H
