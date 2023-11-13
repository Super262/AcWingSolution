//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0871_H
#define ACWINGSOLUTION_PROBLEM0871_H

#include <iostream>
#include <unordered_map>

using namespace std;

class Problem0871
{
    // 牢记模版：https://www.acwing.com/solution/content/16981/
private:
    void get_factors(int n, unordered_map<int, int> &factor)
    {
        for (int f = 2; f <= n / f; ++f)
        {
            while (n % f == 0)
            {
                n /= f;
                ++factor[f];
            }
        }
        if (n > 1)
        {
            ++factor[n];
        }
    }

    int main()
    {
        int m;
        scanf("%d", &m);
        unordered_map<int, int> factors;
        int n;
        while (m--)
        {
            scanf("%d", &n);
            get_factors(n, factors);
        }
        const int MOD = 1e9 + 7;
        int result = 1;
        for (const auto &p : factors)
        {
            int temp = 1;
            for (int k = 0; k < p.second; ++k)
            {
                temp = (int)(((long long)temp * p.first + 1) % MOD);
            }
            result = (int)((long long)result * temp % MOD);
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0871_H
