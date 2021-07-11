//
// Created by Fengwei Zhang on 2021/7/11.
//

#ifndef ACWINGSOLUTION_PROBLEM0426_H
#define ACWINGSOLUTION_PROBLEM0426_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0426 {
public:
    int knapsackMaxValue(const int *itemSize, const int *itemValue, const int itemsNum, const int packVolume) {
        auto dp = new int[packVolume + 1];
        memset(dp, 0, sizeof(int) * (packVolume + 1));
        for (int i = 0; i < itemsNum; ++i) {
            for (int j = packVolume; j >= itemSize[i]; --j) {
                dp[j] = max(dp[j], dp[j - itemSize[i]] + itemValue[i] * itemSize[i]);
            }
        }
        int result = dp[packVolume];
        delete[] dp;
        return result;
    }

    int main() {
        int itemsNum;
        int packVolume;
        scanf("%d%d", &packVolume, &itemsNum);
        auto itemSize = new int[itemsNum + 1];
        auto itemValue = new int[itemsNum + 1];
        for (int i = 0; i < itemsNum; ++i) {
            scanf("%d%d", &itemSize[i], &itemValue[i]);
        }
        printf("%d\n", knapsackMaxValue(itemSize, itemValue, itemsNum, packVolume));
        delete[] itemSize;
        delete[] itemValue;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0426_H
