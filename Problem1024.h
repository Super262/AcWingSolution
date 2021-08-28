//
// Created by Fengwei Zhang on 2021/7/9.
//

#ifndef ACWINGSOLUTION_PROBLEM1024_H
#define ACWINGSOLUTION_PROBLEM1024_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1024 {
private:
    const int V = 20001;
    const int N = 30;
    int items[N];
    int dp[V];

    int knapsack(const int n, const int packVolume) {
        for (int i = 0; i < n; ++i) {
            for (int j = packVolume; j >= items[i]; --j) {
                dp[j] = max(dp[j - items[i]] + items[i], dp[j]);
            }
        }
        return dp[packVolume];
    }

    int main() {
        int packVolume, n;
        scanf("%d%d", &packVolume, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &items[i]);
        }
        printf("%d\n", packVolume - knapsack(n, packVolume));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1024_H
