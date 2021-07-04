//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0282_H
#define ACWINGSOLUTION_PROBLEM0282_H

#include <iostream>

using namespace std;

class Problem0282 {
public:
    int moveStones(const int *stones, const int N) {
        auto prefixSum = new int[N];
        prefixSum[0] = stones[0];
        for (int i = 1; i < N; ++i) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        auto dp = new int*[N];
        for (int i = 0; i < N; ++i) {
            dp[i] = new int[N];
            memset(dp[i], 0x7f, sizeof(int) * N);
            dp[i][i] = 0;
        }
        for (int len = 2; len <= N; ++len) {
            for (int start = 0; start + len - 1 < N; ++start) {
                int end = start + len - 1;
                for (int mid = start; mid < end; ++mid) {
                    int temp;
                    if (start == 0) {
                        temp = prefixSum[end];
                    } else {
                        temp = prefixSum[end] - prefixSum[start - 1];
                    }
                    dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + temp);
                }
            }
        }
        int result = dp[0][N - 1];
        delete[] prefixSum;
        for (int i = 0; i < N; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto stones = new int[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &stones[i]);
        }
        printf("%d\n", moveStones(stones, n));
        delete[] stones;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0282_H
