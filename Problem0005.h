//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0005_H
#define ACWINGSOLUTION_PROBLEM0005_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0005
{
private:
    struct Item
    {
        int v;
        int w;
        int s;

        Item()
        {
            v = 0;
            w = 0;
            s = 0;
        }
    };

    int knapsack_max_value(const int &n, const int &v, const Item *items)
    {
        int dp[v + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i)
        {
            auto v = items[i].v;
            auto w = items[i].w;
            auto s = items[i].s;
            for (int factor = 1; factor <= s; factor *= 2)
            {
                for (auto j = v; j >= factor * v; --j)
                {
                    dp[j] = max(dp[j], dp[j - factor * v] + factor * w);
                }
                s -= factor;
            }
            if (s > 0)
            {
                for (auto j = v; j >= s * v; --j)
                {
                    dp[j] = max(dp[j], dp[j - s * v] + s * w);
                }
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
            scanf("%d%d%d", &items[i].v, &items[i].w, &items[i].s);
        }
        printf("%d\n", knapsack_max_value(n, v, items));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0005_H
