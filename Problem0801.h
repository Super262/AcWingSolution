//
// Created by Fengwei Zhang on 2021/6/1.
//

#ifndef ACWINGSOLUTION_PROBLEM0801_H
#define ACWINGSOLUTION_PROBLEM0801_H

#include <iostream>

using namespace std;

class Problem0801
{
private:
    int low_bit(const int x)
    {
        return x & (-x);
    }

    int count_ones(int x)
    {
        int result = 0;
        while (x > 0)
        {
            x -= low_bit(x);
            ++result;
        }
        return result;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        for (int i = 1, x; i <= n; ++i)
        {
            scanf("%d", &x);
            printf("%d ", count_ones(x));
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0801_H
