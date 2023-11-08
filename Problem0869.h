//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0869_H
#define ACWINGSOLUTION_PROBLEM0869_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0869
{
private:
    int get_divisors(const int &n, int *divisors)
    {
        int count = 0;
        for (int f = 1; f <= n / f; ++f)
        {
            if (n % f)
            {
                continue;
            }
            divisors[count++] = f;
            if (f != n / f)
            {
                divisors[count++] = n / f;
            }
        }
        return count;
    }

    int main()
    {
        int m;
        scanf("%d", &m);
        int n;
        int divisors[20000];
        while (m--)
        {
            scanf("%d", &n);
            auto count = get_divisors(n, divisors);
            sort(divisors, divisors + count);
            for (int i = 0; i < count; ++i)
            {
                printf("%d ", divisors[i]);
            }
            printf("\n");
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0869_H
