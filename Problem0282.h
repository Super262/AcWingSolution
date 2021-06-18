//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0282_H
#define ACWINGSOLUTION_PROBLEM0282_H

#include <iostream>

using namespace std;

class Problem0282 {
public:
    unsigned int moveStones(const unsigned int *stones, const unsigned int n) {
        auto prefixSum = new unsigned int[n];
        prefixSum[0] = stones[0];
        for (unsigned int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        auto dp = new unsigned int *[n];
        for (unsigned int i = 0; i < n; ++i) {
            dp[i] = new unsigned int[n];
            for (unsigned int j = 0; j < n; ++j) {
                dp[i][j] = 0x3f3f3f3f;
            }
            dp[i][i] = 0;
        }
        for (unsigned int len = 2; len <= n; ++len) {
            for (unsigned int start = 0; start + len - 1 < n; ++start) {
                for (unsigned int mid = start; mid < start + len - 1; ++mid) {
                    unsigned temp;
                    if (start == 0) {
                        temp = prefixSum[start + len - 1];
                    } else {
                        temp = prefixSum[start + len - 1] - prefixSum[start - 1];
                    }
                    dp[start][start + len - 1] = min(dp[start][start + len - 1],
                                                     dp[start][mid] + dp[mid + 1][start + len - 1] + temp);
                }
            }
        }
        delete[] prefixSum;
        unsigned int result = dp[0][n - 1];
        for (unsigned int i = 0; i < n; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        auto stones = new unsigned int[n];
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d", &stones[i]);
        }
        printf("%d\n", moveStones(stones, n));
        delete[] stones;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0282_H
