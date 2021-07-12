//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM0011_H
#define ACWINGSOLUTION_PROBLEM0011_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0011 {
public:
    int solutionsCount(const int *itemSize, const int *itemValue, const int N, const int packVolume) {
        const int MOD = 1000000007;
        auto dp = new int[packVolume + 1];
        auto pathsNum = new int[packVolume + 1];
        memset(dp, 0, sizeof(int) * (packVolume + 1));
        memset(pathsNum, 0, sizeof(int) * (packVolume + 1));
        dp[0] = 0;
        pathsNum[0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = packVolume; j >= itemSize[i]; --j) {
                int maxValue = max(dp[j], dp[j - itemSize[i]] + itemValue[i]);
                int count = 0;
                if (maxValue == dp[j]) {
                    count += pathsNum[j];
                    count %= MOD;
                }
                if (maxValue == dp[j - itemSize[i]] + itemValue[i]) {
                    count += pathsNum[j - itemSize[i]];
                    count %= MOD;
                }
                dp[j] = maxValue;
                pathsNum[j] = count;
            }
        }
        int result = 0;
        int maxValue = 0;
        for (int i = 0; i <= packVolume; ++i) {
            maxValue = max(maxValue, dp[i]);
        }
        for (int i = 0; i <= packVolume; ++i) {
            if (maxValue != dp[i]) {
                continue;
            }
            result += pathsNum[i];
            result %= MOD;
        }
        delete[] dp;
        delete[] pathsNum;
        return result;
    }

    int main() {
        int N, packVolume;
        scanf("%d%d", &N, &packVolume);
        auto *itemSize = new int[N];
        auto *itemValue = new int[N];
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &itemSize[i], &itemValue[i]);
        }
        printf("%d\n", solutionsCount(itemSize, itemValue, N, packVolume));
        delete[] itemValue;
        delete[] itemSize;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0011_H
