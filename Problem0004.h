//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0004_H
#define ACWINGSOLUTION_PROBLEM0004_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0004
{
private:
    struct Item
    {
        int size;
        int value;
        int num;

        Item()
        {
            value = 0;
            size = 0;
            num = 0;
        }
    };

    int knapsack_max_value(const int &n, const int &v, const Item *items)
    {
        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; ++i)
        {
            dp[i] = new int[v + 1];
            memset(dp[i], 0, sizeof(int) * (v + 1));
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= v; ++j)
            {
                for (int k = 0; k <= items[i].num && k * items[i].size <= j; ++k)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * items[i].size] + k * items[i].value);
                }
            }
        }
        auto answer = dp[n][v];
        for (int i = 0; i <= n; ++i)
        {
            delete[] dp[i];
        }
        delete[] dp;
        return answer;
    }

    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        Item items[n];
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d%d", &items[i].size, &items[i].value, &items[i].num);
        }
        printf("%d\n", knapsack_max_value(n, m, items));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0004_H
