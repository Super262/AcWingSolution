//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0009_H
#define ACWINGSOLUTION_PROBLEM0009_H

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Problem0009
{
private:
    struct Item
    {
        int size;
        int value;

        Item()
        {
            size = -1;
            value = 0;
        }
    };

    int knapsack_max_value(const int &n, const int &v, const vector<vector<Item>> &items)
    {
        // dp[i][j]表示只从前i组物品中选，总体积不大于j的所有选法，
        // 所以注意这里的循环顺序：组、体积、物品
        int dp[v + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i)
        {
            for (auto j = v; j >= 0; --j)
            {
                for (const auto &item : items[i])
                {
                    if (j < item.size)
                    {
                        continue;
                    }
                    dp[j] = max(dp[j], dp[j - item.size] + item.value);
                }
            }
        }
        return dp[v];
    }

    int main()
    {
        int n, v;
        scanf("%d%d", &n, &v);
        vector<vector<Item>> items(n);
        for (int i = 0, k; i < n; ++i)
        {
            scanf("%d", &k);
            items[i].resize(k);
            for (const auto &item : items[i])
            {
                scanf("%d%d", &item.size, &item.value);
            }
        }
        printf("%d\n", knapsack_max_value(n, v, items));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0009_H
