//
// Created by Fengwei Zhang on 2021/7/10.
//

#ifndef ACWINGSOLUTION_PROBLEM1019_H
#define ACWINGSOLUTION_PROBLEM1019_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1019 {
public:
    int knapsackMaxValue(const int *itemSize,
                         const int *itemValue,
                         const int *itemQuantity,
                         const int itemsNum,
                         const int packVolume) {
        int dq[10000];
        auto dp = new int[packVolume + 1];
        auto pre = new int[packVolume + 1];
        memset(dp, 0, sizeof(int) * (packVolume + 1));
        for (int i = 0; i < itemsNum; ++i) {
            memcpy(pre, dp, sizeof(int) * (packVolume + 1));
            const int v = itemSize[i];
            const int w = itemValue[i];
            const int s = itemQuantity[i];
            for (int j = 0; j < v; ++j) {
                int dqHead = 0;
                int dqTail = -1;
                for (int k = j; k <= packVolume; k += v) {
                    while (dqHead <= dqTail && dq[dqHead] < k - s * v) {
                        ++dqHead;
                    }
                    while (dqHead <= dqTail && pre[dq[dqTail]] - (dq[dqTail] - j) / v * w <= pre[k] - (k - j) / v * w) {
                        --dqTail;
                    }
                    if (dqHead <= dqTail) {
                        dp[k] = pre[dq[dqHead]] + (k - dq[dqHead]) / v * w;
                    }
                    dq[++dqTail] = k;
                }
            }
        }
        int result = dp[packVolume];
        delete[] dp;
        return result;
    }

    int main() {
        int itemsNum;
        int packVolume;
        scanf("%d%d", &itemsNum, &packVolume);
        auto itemSize = new int[itemsNum];
        auto itemValue = new int[itemsNum];
        auto itemQuantity = new int[itemsNum];
        for (int i = 0; i < itemsNum; ++i) {
            scanf("%d%d%d", &itemSize[i], &itemValue[i], &itemQuantity[i]);
        }
        printf("%d\n", knapsackMaxValue(itemSize, itemValue, itemQuantity, itemsNum, packVolume));
        delete[] itemSize;
        delete[] itemQuantity;
        delete[] itemValue;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1019_H
