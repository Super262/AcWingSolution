//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0004_H
#define ACWINGSOLUTION_PROBLEM0004_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0004 {
public:
    unsigned int knapsackMaxValue(const unsigned int *size,
                                  const unsigned int *value,
                                  const unsigned int *quantity,
                                  const unsigned int kindsNum,
                                  const unsigned int packVolume) {
        auto dp = new unsigned int *[kindsNum + 1];
        for (unsigned int i = 0; i <= kindsNum; ++i) {
            dp[i] = new unsigned int[packVolume + 1];
            memset(dp[i], 0, sizeof(unsigned int) * (packVolume + 1));
        }
        for (unsigned int i = 1; i <= kindsNum; ++i) {
            for (unsigned int v = 0; v <= packVolume; ++v) {
                for (unsigned int k = 0; k <= quantity[i] && k * size[i] <= v; ++k) {
                    dp[i][v] = max(dp[i][v], dp[i - 1][v - k * size[i]] + k * value[i]);
                }
            }
        }
        unsigned int result = dp[kindsNum][packVolume];
        for (unsigned int i = 0; i <= kindsNum; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        unsigned int kindsNum, packVolume;
        scanf("%d%d", &kindsNum, &packVolume);
        auto size = new unsigned int[kindsNum + 1];
        auto value = new unsigned int[kindsNum + 1];
        auto quantity = new unsigned int[kindsNum + 1];
        for (unsigned int i = 1; i <= kindsNum; ++i) {
            scanf("%d%d%d", &size[i], &value[i], &quantity[i]);
        }
        printf("%d\n", knapsackMaxValue(size, value, quantity, kindsNum, packVolume));
        delete[] size;
        delete[] value;
        delete[] quantity;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0004_H
