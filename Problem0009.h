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
    unsigned int knapsackMaxValue(const unsigned int *quantity,
                                  unsigned int *const *itemValue,
                                  unsigned int *const *itemSize,
                                  const unsigned int kindsNum,
                                  const unsigned int packVolume) {
        auto dp = new unsigned int[packVolume + 1];
        memset(dp, 0, sizeof(unsigned int) * (packVolume + 1));
        for (unsigned int i = 0; i < kindsNum; ++i) {
            for (unsigned int v = packVolume; v > 0; --v) {
                for (unsigned int j = 0; j < quantity[i]; ++j) {
                    if (v < itemSize[i][j]) {
                        continue;
                    }
                    dp[v] = max(dp[v], dp[v - itemSize[i][j]] + itemValue[i][j]);
                }
            }
        }
        auto result = dp[packVolume];
        delete[] dp;
        return result;
    }

    int main() {
        unsigned int n, packVolume;
        scanf("%d%d", &n, &packVolume);
        auto quantity = new unsigned int[n];
        auto itemValue = new unsigned int *[n];
        auto itemSize = new unsigned int *[n];
        unsigned int q, s, v;
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d", &q);
            quantity[i] = q;
            itemValue[i] = new unsigned int[q];
            itemSize[i] = new unsigned int[q];
            for (unsigned int j = 0; j < q; ++j) {
                scanf("%d%d", &s, &v);
                itemSize[i][j] = s;
                itemValue[i][j] = v;
            }
        }
        printf("%d\n", knapsackMaxValue(quantity, itemValue, itemSize, n, packVolume));
        for (unsigned int i = 0; i < n; ++i) {
            delete[] itemValue[i];
            delete[] itemSize[i];
        }
        delete[] quantity;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0009_H
