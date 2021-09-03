//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM1058_H
#define ACWINGSOLUTION_PROBLEM1058_H

#include <iostream>

using namespace std;

class Problem1058 {
    // 状态机（最大收益）：dp[i][0]（手中有货），dp[i][1]（手中无货的第1天），dp[i][2]（手中无货的第2天及以后）
private:
    int items[100010];
    int dp[2][3];

    int stateMachine(const int n) {
        memset(dp, -0x3f, sizeof dp);
        dp[0][2] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][2] - items[i]);
            dp[i % 2][1] = dp[(i - 1) % 2][0] + items[i];
            dp[i % 2][2] = max(dp[(i - 1) % 2][2], dp[(i - 1) % 2][1]);
        }
        return max(dp[n % 2][1], dp[n % 2][2]);
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &items[i]);
        }
        printf("%d\n", stateMachine(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1058_H
