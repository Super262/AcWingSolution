//
// Created by Fengwei Zhang on 2021/7/10.
//

#ifndef ACWINGSOLUTION_PROBLEM1023_H
#define ACWINGSOLUTION_PROBLEM1023_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1023 {
public:
    int main() {
        const int price[4]{10, 20, 50, 100};
        int n;
        scanf("%d", &n);
        int dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (const int &p: price) {
            for (int j = p; j <= n; ++j) {
                dp[j] += dp[j - p];
            }
        }
        printf("%d\n", dp[n]);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1023_H
