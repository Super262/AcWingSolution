//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0003_H
#define ACWINGSOLUTION_PROBLEM0003_H

#include <iostream>

using namespace std;

class Problem0003 {
private:
    struct Item {
        int size;
        int value;
    };

    const int N = 1010;
    const int M = 1010;
    Item items[N];
    int dp[M];

    int knapsack(const int packVolume, const int itemsNum) {
        for (int i = 0; i < itemsNum; ++i) {
            for (int j = items[i].size; j <= packVolume; ++j) {
                dp[j] = max(dp[j], dp[j - items[i].size] + items[i].value);
            }
        }
        return dp[packVolume];
    }

    int main() {
        int n, v;
        scanf("%d%d", &n, &v);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &items[i].size, &items[i].value);
        }
        printf("%d\n", knapsack(v, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0003_H
