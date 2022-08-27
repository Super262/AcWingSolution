//
// Created by Fengwei Zhang on 2021/6/18.
//

#ifndef ACWINGSOLUTION_PROBLEM0900_H
#define ACWINGSOLUTION_PROBLEM0900_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0900 {
public:
    int combinationsOfSum(const int sum) {
        int dp[sum + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;  // 不要忘记初始化！
        for (int a = 1; a <= sum; ++a) {
            for (auto b = a; b <= sum; ++b) {
                dp[b] = (dp[b] + dp[b - a]) % 1000000007;
            }
        }
        return dp[sum];
    }

    int main() {
        int n;
        scanf("%d", &n);
        printf("%d\n", combinationsOfSum(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0900_H
