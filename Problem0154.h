//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0154_H
#define ACWINGSOLUTION_PROBLEM0154_H

#include <iostream>

class Problem0154
{
private:
    void print_max(const int &n, const int &k, const int *a, int *dq)
    {
        int hh = 0, tt = -1;
        for (int i = 0; i < n; ++i)
        {
            while (hh <= tt && i - dq[hh] + 1 > k)
            {
                ++hh;
            }
            while (hh <= tt && a[i] >= a[dq[tt]])
            {
                --tt;
            }
            dq[++tt] = i;
            if (i + 1 >= k)
            {
                printf("%d ", a[dq[hh]]);
            }
        }
        printf("\n");
    }

    void print_min(const int &n, const int &k, const int *a, int *dq)
    {
        int hh = 0, tt = -1;
        for (int i = 0; i < n; ++i)
        {
            while (hh <= tt && i - dq[hh] + 1 > k)
            {
                ++hh;
            }
            while (hh <= tt && a[i] <= a[dq[tt]])
            {
                --tt;
            }
            dq[++tt] = i;
            if (i + 1 >= k)
            {
                printf("%d ", a[dq[hh]]);
            }
        }
        printf("\n");
    }

    int main()
    {
        int n, k;
        scanf("%d%d", &n, &k);
        int a[n];
        int dq[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        print_min(n, k, a, dq);
        print_max(n, k, a, dq);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0154_H
