//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0866_H
#define ACWINGSOLUTION_PROBLEM0866_H

#include <iostream>

using namespace std;

class Problem0866
{
private:
    bool is_prime(const int &num)
    {
        if (num < 2)
        {
            return false;
        }
        for (int i = 2; i <= num / i; ++i)
        {
            if (num % i)
            {
                continue;
            }
            return false;
        }
        return true;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        int num;
        while (n--)
        {
            scanf("%d", &num);
            if (is_prime(num))
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0866_H
