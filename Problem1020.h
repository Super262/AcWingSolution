//
// Created by Fengwei Zhang on 2021/7/9.
//

#ifndef ACWINGSOLUTION_PROBLEM1020_H
#define ACWINGSOLUTION_PROBLEM1020_H

#include <iostream>
#include <cstring>

using namespace std;

// https://www.acwing.com/solution/content/6485/

class Problem1020 {
public:
    int main() {
        const int M = 21;
        const int N = 79;
        auto dp = new int *[M + 1];
        for (int i = 0; i <= M; ++i) {
            dp[i] = new int[N + 1];
            memset(dp[i], -1, sizeof(int) * (N + 1));
        }
        dp[0][0] = 0;
        int m, n, k;
        scanf("%d%d%d", &m, &n, &k);
        for (int d = 0; d < k; ++d) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            for (int i = M; i >= 0; --i) {
                for (int j = N; j >= 0; --j) {
                    // “01背包”的改进：物品体积可以超过背包容量
                    int preI = max(i - a, 0);
                    int preJ = max(j - b, 0);
                    if (dp[preI][preJ] == -1) {
                        continue;
                    }
                    if (dp[i][j] == -1) {
                        dp[i][j] = dp[preI][preJ] + c;
                    } else {
                        dp[i][j] = min(dp[i][j], dp[preI][preJ] + c);
                    }
                }
            }
        }
        int result = 0x7f7f7f7f;
        for (int i = M; i >= m; --i) {
            for (int j = N; j >= n; --j) {
                if (dp[i][j] == -1) {
                    continue;
                }
                result = min(dp[i][j], result);
            }
        }
        printf("%d\n", result);
        for (int i = 0; i <= M; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1020_H
