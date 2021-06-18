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
    unsigned int combinationsOfSum(const unsigned int sum) {
        auto dp = new unsigned int[sum + 1];
        memset(dp, 0, sizeof(unsigned int) * (sum + 1));
        dp[0] = 1;
        for (unsigned int s = 1; s <= sum; ++s) {
            for (unsigned int num = s; num <= sum; ++num) {
                dp[num] = (dp[num] + dp[num - s]) % (1000000007);
            }
        }
        unsigned int result = dp[sum];
        delete[] dp;
        return result;
    }

    int main() {
        unsigned int sum;
        scanf("%d", &sum);
        printf("%d\n", combinationsOfSum(sum));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0900_H
