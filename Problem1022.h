//
// Created by Fengwei Zhang on 2021/7/9.
//

#ifndef ACWINGSOLUTION_PROBLEM1022_H
#define ACWINGSOLUTION_PROBLEM1022_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1022 {
public:
    int main() {
        int ballsNum, strength, kidsNum;
        scanf("%d%d%d", &ballsNum, &strength, &kidsNum);
        auto dp = new int *[ballsNum + 1];
        for (int i = 0; i <= ballsNum; ++i) {
            dp[i] = new int[strength];
            memset(dp[i], 0, sizeof(int) * strength);
        }
        for (int i = 0; i < kidsNum; ++i) {
            int b, s;
            scanf("%d%d", &b, &s);
            for (int ballsCost = ballsNum; ballsCost >= b; --ballsCost) {
                // 皮卡丘体力值必须大于0，消耗最多为 (strength - 1)
                for (int strengthCost = strength - 1; strengthCost >= s; --strengthCost) {
                    dp[ballsCost][strengthCost] = max(dp[ballsCost][strengthCost],
                                                      dp[ballsCost - b][strengthCost - s] + 1);
                }
            }
        }
        printf("%d ", dp[ballsNum][strength - 1]);
        int minStrengthCost = strength - 1;
        while (minStrengthCost > 0 && dp[ballsNum][minStrengthCost - 1] == dp[ballsNum][strength - 1]) {
            --minStrengthCost;
        }
        printf("%d\n", strength - minStrengthCost);
        for (int i = 0; i <= ballsNum; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1022_H
