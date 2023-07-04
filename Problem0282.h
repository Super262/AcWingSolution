//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0282_H
#define ACWINGSOLUTION_PROBLEM0282_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0282 {
private:
    static const int N = 310;
    int prefix[N];
    int dp[N][N];

    int moveStones(const int n) {
        for (int l = 2; l <= n; ++l) {
            for (int st = 1; st + l - 1 <= n; ++st) {
                const auto ed = st + l - 1;
                dp[st][ed] = 0x7f7f7f7f;
                for (auto mid = st + 1; mid <= ed; ++mid) {
                    dp[st][ed] = min(dp[st][ed], dp[st][mid - 1] + dp[mid][ed] + prefix[ed] - prefix[st - 1]);
                }
            }
        }
        return dp[1][n];
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &prefix[i]);
            prefix[i] += prefix[i - 1];
        }
        printf("%d\n", moveStones(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0282_H
