//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0003_H
#define ACWINGSOLUTION_PROBLEM0003_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0003
{
private:
    struct Item
    {
        int value;
        int size;

        Item()
        {
            value = 0;
            size = 0;
        }
    };

    int knapsack_max_value(const int &n, const int &v, const Item *items)
    {
        int dp[v + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i)
        {
            for (auto j = items[i].size; j <= v; ++j)
            {
                dp[j] = max(dp[j], dp[j - items[i].size] + items[i].value);
            }
        }
        return dp[v];
    }

    int main()
    {
        int n, v;
        scanf("%d%d", &n, &v);
        Item items[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &items[i].size, &items[i].value);
        }
        printf("%d\n", knapsack_max_value(n, v, items));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0003_H
