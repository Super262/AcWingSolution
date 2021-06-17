//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0005_H
#define ACWINGSOLUTION_PROBLEM0005_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Problem0005 {
public:
    unsigned int knapsackMaxValue(const vector<unsigned int> &itemSize,
                                  const vector<unsigned int> &itemValue,
                                  const unsigned int packVolume) {
        auto *dp = new unsigned int[packVolume + 1];
        memset(dp, 0, sizeof(unsigned int) * (packVolume + 1));
        for (unsigned int i = 0; i < itemValue.size(); ++i) {
            for (unsigned int j = packVolume; j >= itemSize[i]; --j) {
                dp[j] = max(dp[j], dp[j - itemSize[i]] + itemValue[i]);
            }
        }
        auto result = dp[packVolume];
        delete[] dp;
        return result;
    }

    int main() {
        unsigned int n, packVolume;
        scanf("%d%d", &n, &packVolume);
        vector<unsigned int> itemSize, itemValue;
        unsigned int factor;
        unsigned int v, w, s;
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d%d%d", &v, &w, &s);
            factor = 1;
            while (factor <= s) {
                itemSize.emplace_back(v * factor);
                itemValue.emplace_back(w * factor);
                s -= factor;
                factor *= 2;
            }
            if (s > 0) {
                itemSize.emplace_back(s * v);
                itemValue.emplace_back(s * w);
            }
        }
        printf("%d\n", knapsackMaxValue(itemSize, itemValue, packVolume));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0005_H
