//
// Created by Fengwei Zhang on 2021/7/9.
//

#ifndef ACWINGSOLUTION_PROBLEM1024_H
#define ACWINGSOLUTION_PROBLEM1024_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1024 {
public:
    int main() {
        int packVolume;
        int itemsNum;
        scanf("%d%d", &packVolume, &itemsNum);
        auto dp = new int[packVolume + 1];
        memset(dp, 0, sizeof(int) * (packVolume + 1));
        for (int i = 0; i < itemsNum; ++i) {
            int v;
            scanf("%d", &v);
            for (int j = packVolume; j >= v; --j) {
                dp[j] = max(dp[j], dp[j - v] + v);
            }
        }
        printf("%d\n", packVolume - dp[packVolume]);
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1024_H
