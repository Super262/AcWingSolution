//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM0734_H
#define ACWINGSOLUTION_PROBLEM0734_H

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Stone {
    int s;
    int e;
    int l;

    bool operator<(const Stone &w) const {
        return s * w.l < w.s * l;
    }
};

class Problem0734 {
    // sort将排列数优化为组合数，组合数就可以用背包了，妙啊（找到前后两项间的顺序关系，再排序）！
    // https://www.acwing.com/solution/content/4639/
    // dp[i]是花费时间恰好为i时获取的最大能量
public:
    int knapsackMaxValue(const Stone *stones, const int N, const int packVolume) {
        auto dp = new int[packVolume + 1];
        memset(dp, -1, sizeof(int) * (packVolume + 1));
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = packVolume; j >= stones[i].s; --j) {
                if (dp[j - stones[i].s] == -1) {
                    continue;
                }
                dp[j] = max(dp[j], dp[j - stones[i].s] + max(stones[i].e - (j - stones[i].s) * stones[i].l, 0));
            }
        }
        int result = 0;
        for (int i = 1; i <= packVolume; ++i) {
            result = max(result, dp[i]);
        }
        delete[] dp;
        return result;
    }

    int main() {
        int c;
        scanf("%d", &c);
        for (int i = 1; i <= c; ++i) {
            int N;
            scanf("%d", &N);
            auto stones = new Stone[N];
            int packVolume = 0;
            for (int j = 0; j < N; ++j) {
                scanf("%d%d%d", &stones[j].s, &stones[j].e, &stones[j].l);
                packVolume += stones[j].s;
            }
            sort(stones, stones + N);
            printf("Case #%d: %d\n", i, knapsackMaxValue(stones, N, packVolume));
            delete[] stones;
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0734_H
