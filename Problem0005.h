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
    int knapsackMaxValue(const vector<int> &itemSize, const vector<int> &itemValue, const int packVolume) {
        auto dp = new int[packVolume + 1];
        memset(dp, 0, sizeof(int) * (packVolume + 1));
        for (int i = 0; i < itemValue.size(); ++i) {
            for (int v = packVolume; v >= itemSize[i]; --v) {
                dp[v] = max(dp[v], dp[v - itemSize[i]] + itemValue[i]);
            }
        }
        int result = dp[packVolume];
        delete[] dp;
        return result;
    }

    int main() {
        int n, packVolume;
        scanf("%d%d", &n, &packVolume);
        vector<int> itemSize;
        vector<int> itemValue;
        int v, w, s;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &v, &w, &s);
            int factor = 1;
            while (factor <= s) {
                itemSize.emplace_back(factor * v);
                itemValue.emplace_back(factor * w);
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
