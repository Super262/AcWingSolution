//
// Created by Fengwei Zhang on 2021/7/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0278_H
#define ACWINGSOLUTION_PROBLEM0278_H

#include <iostream>

using namespace std;

class Problem0278 {
private:
    int dp[10010];
    int items[100];

    int knapsack(const int n, const int m) {
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = m; j >= items[i]; --j) {
                dp[j] += dp[j - items[i]];
            }
        }
        return dp[m];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &items[i]);
        }
        printf("%d\n", knapsack(n, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0278_H
