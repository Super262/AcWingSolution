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
        int v, w, s;
    };

    int knapsack_max_value(int n, int m, const struct Item *items)
    {
        int *dp = (int *)calloc(m + 1, sizeof(int));
        int i, v, w, s, factor, j, t, answer;
        
        for (i = 0; i < n; ++i)
        {
            s = items[i].s;

            for (factor = 1; factor <= s; factor *= 2)
            {
                v = items[i].v * factor;
                w = items[i].w * factor;

                for (j = m; j >= v; --j)
                {
                    t = dp[j - v] + w;
                    if (t > dp[j])
                        dp[j] = t;
                    
                }

                s -= factor;
            }

            if (s)
            {
                v = items[i].v * s;
                w = items[i].w * s;

                for (j = m; j >= v; --j)
                {
                    t = dp[j - v] + w;
                    if (t > dp[j])
                        dp[j] = t;
                }
            }
        }
        
        answer = dp[m];
        free(dp);
        return answer;
    }

    int main()
    {
        int n, v;
        scanf("%d%d", &n, &v);

        struct Item *items = (struct Item *)calloc(n, sizeof(struct Item));
        for (int i = 0; i < n; ++i)
            scanf("%d%d%d", &items[i].v, &items[i].w, &items[i].s);

        printf("%d\n", knapsack_max_value(n, v, items));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0005_H
