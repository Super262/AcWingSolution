//
// Created by Fengwei Zhang on 2021/7/11.
//

#ifndef ACWINGSOLUTION_PROBLEM1013_H
#define ACWINGSOLUTION_PROBLEM1013_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1013 {
private:
    const int N = 11, M = 16;
    int itemsValue[N][M];
    int dp[N][M];
    int solution[N];

    int knapsack(const int n, const int m) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + itemsValue[i][k]);
                }
            }
        }
        auto currentNum = m;
        for (int i = n; i >= 1; --i) {
            for (int j = currentNum; j >= 0; --j) {
                if (dp[i][currentNum] == dp[i - 1][currentNum - j] + itemsValue[i][j]) {
                    currentNum -= j;
                    solution[i] = j;
                    break;
                }
            }
            if (currentNum == 0) {
                break;
            }
        }
        return dp[n][m];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &itemsValue[i][j]);
            }
        }
        printf("%d\n", knapsack(n, m));
        for (int i = 1; i <= n; ++i) {
            printf("%d %d\n", i, solution[i]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1013_H
