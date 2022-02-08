//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0002_H
#define ACWINGSOLUTION_PROBLEM0002_H

#include <iostream>

using namespace std;

class Problem0002 {
private:
    struct Item {
        int value;
        int size;
    };

    static const int N = 1010;
    static const int V = 1010;
    int dp[V];
    Item items[N];

    int knapsackMaxValue(const int n, const int v) {
        for (int i = 0; i < n; ++i) {
            for (int j = v; j >= items[i].size; --j) {
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
        printf("%d\n", knapsackMaxValue(n, v));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0002_H
