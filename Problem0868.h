//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0868_H
#define ACWINGSOLUTION_PROBLEM0868_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0868
{
private:
    // 时间复杂度：O(n)
    int count_primes(const int &n)
    {
        bool filtered[n + 1];
        int primes[n + 1];
        int p_cnt = 0;
        memset(filtered, 0, sizeof filtered);
        for (int f = 2; f <= n; ++f)
        {
            if (!filtered[f])
            {
                primes[p_cnt++] = f;
            }
            for (int j = 0; j < p_cnt && primes[j] <= n / f; ++j)
            {
                filtered[primes[j] * f] = true;
                if (f % primes[j] == 0)
                {
                    break;
                }
            }
        }
        return p_cnt;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", count_primes(n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0868_H
