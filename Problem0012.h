//
// Created by Fengwei Zhang on 2021/7/11.
//

#ifndef ACWINGSOLUTION_PROBLEM0012_H
#define ACWINGSOLUTION_PROBLEM0012_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0012 {
    // https://www.acwing.com/solution/content/2687/
private:
    struct Item {
        int v, w;
    };

    const int N = 1002;
    int dp[N][N];
    Item items[N];

    void knapsack(const int n, const int packVolume) {
        for (auto i = n; i >= 1; --i) {
            for (int j = 0; j <= packVolume; ++j) {
                dp[i][j] = dp[i + 1][j];
                if (j < items[i].v) {
                    continue;
                }
                dp[i][j] = max(dp[i][j], dp[i + 1][j - items[i].v] + items[i].w);
            }
        }
        auto currentV = packVolume;
        for (int i = 1; i <= n; ++i) {
            if (currentV < items[i].v || dp[i][currentV] != dp[i + 1][currentV - items[i].v] + items[i].w) {
                continue;
            }
            printf("%d ", i);
            currentV -= items[i].v;
        }
        printf("\n");
    }

    int main() {
        int n, packVolume;
        scanf("%d%d", &n, &packVolume);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &items[i].v, &items[i].w);
        }
        knapsack(n, packVolume);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0012_H
