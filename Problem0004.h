//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0004_H
#define ACWINGSOLUTION_PROBLEM0004_H

#include <iostream>

using namespace std;

class Problem0004 {
private:
    struct Item {
        int size;
        int value;
        int num;
    };

    const int N = 110;
    const int M = 110;
    Item items[N];
    int dp[N][M];

    int knapsack(const int itemsNum, const int packVolume) {
        for (int i = 1; i <= itemsNum; ++i) {
            for (int j = 1; j <= packVolume; ++j) {
                for (int k = 0; k <= items[i].num && k * items[i].size <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * items[i].size] + k * items[i].value);
                }
            }
        }
        return dp[itemsNum][packVolume];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &items[i].size, &items[i].value, &items[i].num);
        }
        printf("%d\n", knapsack(n, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0004_H
