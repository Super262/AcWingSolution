//
// Created by Fengwei Zhang on 2021/7/15.
//

#ifndef ACWINGSOLUTION_PROBLEM0320_H
#define ACWINGSOLUTION_PROBLEM0320_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0320 {
private:
    const int N = 100;
    int items[2 * N + 1];
    int dp[2 * N + 1][2 * N + 1];

    int rangeModel(const int n) {
        for (int length = 3; length <= n + 1; ++length) {
            for (int start = 1; start + length - 1 <= 2 * n; ++start) {
                int end = start + length - 1;
                for (int mid = start + 1; mid < end; ++mid) {
                    dp[start][end] = max(dp[start][end],
                                         dp[start][mid] + dp[mid][end] + items[start] * items[mid] * items[end]);
                }
            }
        }
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result = max(result, dp[i][i + n]);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &items[i]);
            items[i + n] = items[i];
        }
        printf("%d\n", rangeModel(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0320_H
