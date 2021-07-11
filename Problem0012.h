//
// Created by Fengwei Zhang on 2021/7/11.
//

#ifndef ACWINGSOLUTION_PROBLEM0012_H
#define ACWINGSOLUTION_PROBLEM0012_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0012 {
public:
    void printSolution(const int *itemSize, const int *itemValue, const int itemsNum, const int packVolume) {
        auto dp = new int *[itemsNum + 2];
        for (int i = 1; i <= itemsNum + 1; ++i) {
            dp[i] = new int[packVolume + 1];
            memset(dp[i], 0, sizeof(int) * (packVolume + 1));
        }
        for (int i = itemsNum; i >= 1; --i) {
            for (int j = 0; j <= packVolume; ++j) {
                dp[i][j] = dp[i + 1][j];
                if (j < itemSize[i]) {
                    continue;
                }
                dp[i][j] = max(dp[i][j], dp[i + 1][j - itemSize[i]] + itemValue[i]);
            }
        }
        int currentV = packVolume;
        for (int i = 1; i <= itemsNum; ++i) {
            if (currentV < itemSize[i] || dp[i][currentV] != dp[i + 1][currentV - itemSize[i]] + itemValue[i]) {
                continue;
            }
            printf("%d ", i);
            currentV -= itemSize[i];
        }
        printf("\n");
        for (int i = 0; i <= itemsNum + 1; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
    }

    int main() {
        int itemsNum;
        int packVolume;
        scanf("%d%d", &itemsNum, &packVolume);
        auto itemSize = new int[itemsNum + 1];
        auto itemValue = new int[itemsNum + 1];
        for (int i = 1; i <= itemsNum; ++i) {
            scanf("%d", &itemSize[i]);
            scanf("%d", &itemValue[i]);
        }
        printSolution(itemSize, itemValue, itemsNum, packVolume);
        delete[] itemSize;
        delete[] itemValue;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0012_H
