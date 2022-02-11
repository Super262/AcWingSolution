//
// Created by Fengwei Zhang on 2021/7/11.
//

#ifndef ACWINGSOLUTION_PROBLEM0426_H
#define ACWINGSOLUTION_PROBLEM0426_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0426 {
private:
    int knapsackMaxValue(const int item_size[], const int item_value[], const int n, const int m) {
        int dp[m + 1];
        memset(dp, 0, sizeof(int) * (m + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = m; j >= item_size[i]; --j) {
                dp[j] = max(dp[j], dp[j - item_size[i]] + item_value[i] * item_size[i]);
            }
        }
        return dp[m];
    }

    int main() {
        int n;
        int m;
        scanf("%d%d", &m, &n);
        int item_size[n + 1];
        int item_value[n + 1];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &item_size[i], &item_value[i]);
        }
        printf("%d\n", knapsackMaxValue(item_size, item_value, n, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0426_H
