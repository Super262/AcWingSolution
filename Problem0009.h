//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0009_H
#define ACWINGSOLUTION_PROBLEM0009_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0009 {
public:
    int knapsackMaxValue(int **itemSize, int **itemValue, const int *itemsQuantity, const int kindsNum, const int packVolume) {
        auto dp = new int[packVolume + 1];
        memset(dp, 0, sizeof(int) * (packVolume + 1));
        for (int i = 0; i < kindsNum; ++i) {
            for (int v = packVolume; v > 0; --v) {
                for (int j = 0; j < itemsQuantity[i]; ++j) {
                    if (v < itemSize[i][j]) {
                        continue;
                    }
                    dp[v] = max(dp[v], dp[v - itemSize[i][j]] + itemValue[i][j]);
                }
            }
        }
        int result = dp[packVolume];
        delete[] dp;
        return result;
    }

    int main() {
        int kindsNum, packVolume;
        scanf("%d%d", &kindsNum, &packVolume);
        auto itemSize = new int*[kindsNum];
        auto itemValue = new int*[kindsNum];
        auto itemsQuantity = new int[kindsNum];
        for (int i = 0; i < kindsNum; ++i) {
            scanf("%d", &itemsQuantity[i]);
            itemSize[i] = new int[itemsQuantity[i]];
            itemValue[i] = new int[itemsQuantity[i]];
            for (int j = 0; j < itemsQuantity[i]; ++j) {
                scanf("%d%d", &itemSize[i][j], &itemValue[i][j]);
            }
        }
        printf("%d\n", knapsackMaxValue(itemSize, itemValue, itemsQuantity, kindsNum, packVolume));
        delete[] itemsQuantity;
        for (int i = 0; i < kindsNum; ++i) {
            delete[] itemSize[i];
            delete[] itemValue[i];
        }
        delete[] itemSize;
        delete[] itemValue;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0009_H
