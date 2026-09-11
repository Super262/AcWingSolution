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
        int size, value, num;
    };

    int knapsack_max_value(int n, int v, const struct Item *items)
    {
        int *dp = (int *)calloc(v + 1, sizeof(int));
        int i, j, k, t;

        for (i = 1; i <= n; ++i)
        {
            for (j = v; j; --j)
            {
                for (k = 1; k <= items[i].num && k * items[i].size <= j; ++k)
                {
                    t = dp[j - k * items[i].size] + k * items[i].value;
                    if (t > dp[j])
                        dp[j] = t;
                }
            }
        }
        
        auto answer = dp[v];
        free(dp);
        return answer;
    }

    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);

        struct Item *items = (struct Item *)calloc(n + 1, sizeof(struct Item));

        for (int i = 1; i <= n; ++i)
            scanf("%d%d%d", &items[i].size, &items[i].value, &items[i].num);

        printf("%d\n", knapsack_max_value(n, m, items));

        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0004_H
