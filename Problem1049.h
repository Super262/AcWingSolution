//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM1049_H
#define ACWINGSOLUTION_PROBLEM1049_H

#include <iostream>

using namespace std;

class Problem1049 {
    // 状态机：dp[i][0]表示不盗窃i号房的收益，dp[i][1]表示盗窃i号房的收益
private:
    int stateMachine(const int items[], const int n) {
        int dp[2][2];
        dp[0][0] = 0;
        dp[0][1] = items[0];
        for (int i = 1; i < n; ++i) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1]);
            dp[i % 2][1] = dp[(i - 1) % 2][0] + items[i];
        }
        return max(dp[(n - 1) % 2][0], dp[(n - 1) % 2][1]);
    }

    int main() {
        int t;
        int n;
        int items[100000];
        scanf("%d", &t);
        while (t--) {
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                scanf("%d", &items[i]);
            }
            printf("%d\n", stateMachine(items, n));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1049_H
