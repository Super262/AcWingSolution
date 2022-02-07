//
// Created by Fengwei Zhang on 2021/7/7.
//

#ifndef ACWINGSOLUTION_PROBLEM1017_H
#define ACWINGSOLUTION_PROBLEM1017_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1017 {
private:
    static const int N = 101;
    int height[N];

    int maxRange(const int n) {
        int dp[n];
        int result = 0;
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;  // 在每次计算前，都要把当前dp初始化为1
            for (int j = 0; j < i; ++j) {
                if (height[j] >= height[i]) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;  // 在每次计算前，都要把当前dp初始化为1
            for (int j = n - 1; j > i; --j) {
                if (height[j] >= height[i]) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        return result;
    }

    int main() {
        int k;
        scanf("%d", &k);
        while (k--) {
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                scanf("%d", &height[i]);
            }
            printf("%d\n", maxRange(n));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1017_H
