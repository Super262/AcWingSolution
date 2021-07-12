//
// Created by Fengwei Zhang on 2021/7/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0007_H
#define ACWINGSOLUTION_PROBLEM0007_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0007 {
public:
    int mixedKnapsack(const int *itemSize,
                      const int *itemValue,
                      const int *itemQuantity,
                      const int N,
                      const int packVolume) {
        auto dp = new int[packVolume + 1];
        memset(dp, 0, sizeof(int) * (packVolume + 1));
        for (int k = 0; k < N; ++k) {
            if (!itemQuantity[k]) {
                for (int j = itemSize[k]; j <= packVolume; ++j) {
                    dp[j] = max(dp[j], dp[j - itemSize[k]] + itemValue[k]);
                }
            } else {
                int s = itemQuantity[k];
                if (s == -1) {
                    s = 1;
                }
                for (int factor = 1; factor <= s; factor *= 2) {
                    for (int j = packVolume; j >= factor * itemSize[k]; --j) {
                        dp[j] = max(dp[j], dp[j - factor * itemSize[k]] + factor * itemValue[k]);
                    }
                    s -= factor;
                }
                if (s) {
                    for (int j = packVolume; j >= s * itemSize[k]; --j) {
                        dp[j] = max(dp[j], dp[j - s * itemSize[k]] + s * itemValue[k]);
                    }
                }
            }
        }
        int result = dp[packVolume];
        delete[] dp;
        return result;
    }

    int main() {
        int N;
        int packVolume;
        scanf("%d%d", &N, &packVolume);
        auto itemSize = new int[N];
        auto itemValue = new int[N];
        auto itemQuantity = new int[N];
        for (int i = 0; i < N; ++i) {
            scanf("%d%d%d", &itemSize[i], &itemValue[i], &itemQuantity[i]);
        }
        printf("%d\n", mixedKnapsack(itemSize, itemValue, itemQuantity, N, packVolume));
        delete[] itemSize;
        delete[] itemQuantity;
        delete[] itemValue;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0007_H
