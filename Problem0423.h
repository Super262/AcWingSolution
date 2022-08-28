//
// Created by Fengwei Zhang on 2021/7/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0423_H
#define ACWINGSOLUTION_PROBLEM0423_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0423 {
private:
    struct Item {
        int v, w;
    };

    int dp[1010];
    Item items[110];

    int knapsack(const int n, const int v) {
        for (int i = 0; i < n; ++i) {
            for (int j = v; j >= items[i].v; --j) {
                dp[j] = max(dp[j], dp[j - items[i].v] + items[i].w);
            }
        }
        return dp[v];
    }

    int main() {
        int packVolume, n;
        scanf("%d%d", &packVolume, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &items[i].v, &items[i].w);
        }
        printf("%d\n", knapsack(n, packVolume));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0423_H
