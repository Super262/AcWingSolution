//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM1049_H
#define ACWINGSOLUTION_PROBLEM1049_H

#include <iostream>

using namespace std;

class Problem1049 {
private:
    int dp[2][2];  // 滚动数组优化
    int items[100010];

    int stateMachine(const int n) {
        dp[0][0] = 0;
        dp[0][1] = -1;
        for (int i = 1; i <= n; ++i) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0]);
            dp[i % 2][1] = dp[(i - 1) % 2][0] + items[i];
        }
        return max(dp[n % 2][0], dp[n % 2][1]);
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n;
            scanf("%d", &n);
            for (int i = 1; i <= n; ++i) {
                scanf("%d", &items[i]);
            }
            printf("%d\n", stateMachine(n));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1049_H
