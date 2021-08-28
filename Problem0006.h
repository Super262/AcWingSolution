//
// Created by Fengwei Zhang on 2021/7/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0006_H
#define ACWINGSOLUTION_PROBLEM0006_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0006 {
    // https://www.acwing.com/solution/content/6500/
private:
    struct Item {
        int v;
        int w;
        int s;
    };

    Item items[1010];
    const int N = 20010;
    int dq[N];
    int pre[N];
    int dp[N];

    int knapsack(const int kindsNum, const int packVolume) {
        for (int i = 0; i < kindsNum; ++i) {
            memcpy(pre, dp, sizeof(int) * (packVolume + 1));
            auto v = items[i].v;
            auto w = items[i].w;
            auto s = items[i].s;
            for (int r = 0; r < v; ++r) {
                int hh = 0;
                int tt = -1;
                for (int j = r; j <= packVolume; j += v) {
                    while (hh <= tt && dq[hh] < j - s * v) {
                        ++hh;
                    }
                    while (hh <= tt && pre[dq[tt]] - dq[tt] / v * w <= pre[j] - j / v * w) {
                        --tt;
                    }
                    dq[++tt] = j;
                    dp[j] = pre[dq[hh]] + (j - dq[hh]) / v * w;
                }
            }
        }
        return dp[packVolume];
    }

    int main() {
        int kindsNum, packVolume;
        scanf("%d%d", &kindsNum, &packVolume);
        for (int i = 0; i < kindsNum; ++i) {
            scanf("%d%d%d", &items[i].v, &items[i].w, &items[i].s);
        }
        printf("%d\n", knapsack(kindsNum, packVolume));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0006_H
