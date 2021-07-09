//
// Created by Fengwei Zhang on 2021/7/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0423_H
#define ACWINGSOLUTION_PROBLEM0423_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0423 {
public:
    int main() {
        int itemsNum;
        int packVolume;
        scanf("%d%d", &packVolume, &itemsNum);
        auto dp = new int[packVolume + 1];
        memset(dp, 0, sizeof(int) * (packVolume + 1));
        for (int i = 0; i < itemsNum; ++i) {
            int v, w;
            scanf("%d%d", &v, &w);
            for (int j = packVolume; j >= v; --j) {
                dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
        printf("%d\n", dp[packVolume]);
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0423_H
