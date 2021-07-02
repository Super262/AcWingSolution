//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0002_H
#define ACWINGSOLUTION_PROBLEM0002_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0002 {
public:
    int knapsackMaxValue(const int *itemSize, const int *itemValue, const int itemsNum, const int packVolume) {
        auto dp = new int[packVolume + 1];
        memset(dp, 0, sizeof(int) * (packVolume + 1));
        for (int i = 0; i < itemsNum; ++i) {
            for (int j = packVolume; j >= itemSize[i]; --j) {
                dp[j] = max(dp[j], dp[j - itemSize[i]] + itemValue[i]);
            }
        }
        int result = dp[packVolume];
        delete[] dp;
        return result;
    }

    int main() {
        int n, v;
        scanf("%d%d", &n, &v);
        auto itemSize = new int[n];
        auto itemValue = new int[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &itemSize[i], &itemValue[i]);
        }
        printf("%d\n", knapsackMaxValue(itemSize, itemValue, n, v));
        delete[] itemSize;
        delete[] itemValue;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0002_H
