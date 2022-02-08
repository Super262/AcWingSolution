//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0003_H
#define ACWINGSOLUTION_PROBLEM0003_H

#include <iostream>

using namespace std;

class Problem0003 {
private:
    struct Item {
        int size;
        int value;
    };

    static const int N = 1010;
    static const int M = 1010;
    Item items[N];
    int dp[M];

    int knapsack(const int v, const int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = items[i].size; j <= v; ++j) {
                dp[j] = max(dp[j], dp[j - items[i].size] + items[i].value);
            }
        }
        return dp[v];
    }

    int main() {
        int n, v;
        scanf("%d%d", &n, &v);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &items[i].size, &items[i].value);
        }
        printf("%d\n", knapsack(v, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0003_H
