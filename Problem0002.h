//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0002_H
#define ACWINGSOLUTION_PROBLEM0002_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0002
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

    int knapsack_max_value(int n, int v, const struct Item *items)
    {
        int *dp = (int *)calloc(v + 1, sizeof(int));

        for (int i = 0; i < n; ++i)
        {
            for (auto j = v; j >= items[i].size; --j)
                dp[j] = max(dp[j], dp[j - items[i].size] + items[i].value);
        }
        
        int result = dp[v];
        
        free(dp);
        return result;
    }

    int main()
    {
        int n, v;
        scanf("%d%d", &n, &v);
        struct Item *items = (Item *)malloc(sizeof(struct Item) * n);

        for (int i = 0; i < n; ++i)
            scanf("%d%d", &items[i].size, &items[i].value);

        printf("%d\n", knapsack_max_value(n, v, items));
        
        free(items);
        return 0;
    }
};
#endif // ACWINGSOLUTION_PROBLEM0002_H
