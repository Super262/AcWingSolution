//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0003_H
#define ACWINGSOLUTION_PROBLEM0003_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0003 {
public:
    int knapsackMaxValue(const int *itemsSize, const int *itemsValue, const int itemsNum, const int packVolume) {
        auto dp = new int[packVolume + 1];
        memset(dp, 0, sizeof(int) * (packVolume + 1));
        for (int i = 0; i < itemsNum; ++i) {
            for (int v = itemsSize[i]; v <= packVolume; ++v) {
                dp[v] = max(dp[v], dp[v - itemsSize[i]] + itemsValue[i]);
            }
        }
        int result = dp[packVolume];
        delete[] dp;
        return result;
    }

    int main() {
        int n, v;
        scanf("%d%d", &n, &v);
        auto *itemsSize = new int[n];
        auto *itemsValue = new int[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &itemsSize[i], &itemsValue[i]);
        }
        printf("%d\n", knapsackMaxValue(itemsSize, itemsValue, n, v));
        delete[] itemsSize;
        delete[] itemsValue;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0003_H
