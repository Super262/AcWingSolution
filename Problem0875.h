//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0875_H
#define ACWINGSOLUTION_PROBLEM0875_H

#include <iostream>

using namespace std;

class Problem0875
{
private:
    int quick_power(int a, int b, const int &p)
    {
        int result = 1;
        while (b)
        {
            if (b & 1)
            {
                result = (int)((long long)result * a % p);
            }
            b >>= 1;
            a = (int)((long long)a * a % p);
        }
        return result;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        int a, b, p;
        while (n--)
        {
            scanf("%d%d%d", &a, &b, &p);
            printf("%d\n", quick_power(a, b, p));
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0875_H
