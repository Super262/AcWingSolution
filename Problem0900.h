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
        auto dp = new int[sum + 1];
        memset(dp, 0, sizeof(int) * (sum + 1));
        dp[0] = 1;  // 不要忘记初始化！
        for (int s = 1; s <= sum; ++s) {
            for (int num = s; num <= sum; ++num) {
                dp[num] = (dp[num] + dp[num - s]) % 1000000007;
            }
        }
        int result = dp[sum];
        delete[] dp;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        printf("%d\n", combinationsOfSum(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0900_H
