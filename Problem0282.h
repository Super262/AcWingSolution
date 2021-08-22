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
    const int N = 310;
    int prefixSum[N];
    int dp[N][N];

    int moveStones(const int n) {
        for (int length = 2; length <= n; ++length) {
            for (int start = 1; start <= n - length + 1; ++start) {
                const int end = start + length - 1;
                dp[start][end] = 0x7f7f7f7f;
                for (int mid = start + 1; mid <= end; ++mid) {
                    dp[start][end] = min(dp[start][end],
                                         dp[start][mid - 1] + dp[mid][end] + prefixSum[end] - prefixSum[start - 1]);
                }
            }
        }
        return dp[1][n];
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &prefixSum[i]);
            prefixSum[i] += prefixSum[i - 1];
        }
        printf("%d\n", moveStones(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0282_H
