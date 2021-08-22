//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0009_H
#define ACWINGSOLUTION_PROBLEM0009_H

#include <iostream>

using namespace std;

class Problem0009 {
private:
    struct Item {
        int size;
        int value;

        Item() {
            size = -1;
            value = 0;
        }
    };

    Item items[110][110];
    int dp[110];

    int knapsack(const int kindsNum, const int packVolume) {
        // 注意这里的循环顺序：组、体积、物品
        for (int i = 0; i < kindsNum; ++i) {
            for (int v = packVolume; v >= 0; --v) {
                for (int j = 0; items[i][j].size != -1; ++j) {
                    if (v < items[i][j].size) {
                        continue;
                    }
                    dp[v] = max(dp[v], dp[v - items[i][j].size] + items[i][j].value);
                }
            }
        }
        return dp[packVolume];
    }

    int main() {
        int n, v;
        scanf("%d%d", &n, &v);
        for (int i = 0; i < n; ++i) {
            int k;
            scanf("%d", &k);
            for (int j = 0; j < k; ++j) {
                int a, b;
                scanf("%d%d", &a, &b);
                items[i][j].size = a;
                items[i][j].value = b;
            }
        }
        printf("%d\n", knapsack(n, v));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0009_H
