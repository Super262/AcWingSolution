//
// Created by Fengwei Zhang on 2021/7/11.
//

#ifndef ACWINGSOLUTION_PROBLEM1013_H
#define ACWINGSOLUTION_PROBLEM1013_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Problem1013 {
    // 求具体方案时，要使用原始的二维数组
private:
    struct Item {
        int v;
        int w;

        Item() {
            v = 0;
            w = 0;
        }
    };

    int knapsack(const vector<vector<Item>> &items, const int n, const int m, int solution[]) {
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j];  // 使用二维数组时，不要忘记这一行！
                for (const auto &it: items[i]) {  // 组内遍历
                    if (j < it.v) {
                        continue;
                    }
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - it.v] + it.w);
                }
            }
        }
        auto current_v = m;
        for (int i = n; i >= 1; --i) {
            for (const auto &it: items[i]) {  // 组内遍历
                if (it.v > current_v || dp[i][current_v] != dp[i - 1][current_v - it.v] + it.w) {
                    continue;
                }
                solution[i] = it.v;
                current_v -= it.v;
                break;
            }
        }
        return dp[n][m];
    }

    int main() {
        int n;
        int m;
        scanf("%d%d", &n, &m);
        int solution[n + 1];
        vector<vector<Item>> items(n + 1, vector<Item>(m + 1, Item()));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                items[i][j].v = j;
                scanf("%d", &items[i][j].w);
            }
        }
        printf("%d\n", knapsack(items, n, m, solution));
        for (int i = 1; i <= n; ++i) {
            printf("%d %d\n", i, solution[i]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1013_H
