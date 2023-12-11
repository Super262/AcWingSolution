//
// Created by Fengwei Zhang on 2021/6/18.
//

#ifndef ACWINGSOLUTION_PROBLEM0900_H
#define ACWINGSOLUTION_PROBLEM0900_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0900
{
    // 类似“完全背包”问题
private:
    int count_division(const int &n)
    {
        int f[n + 1];
        memset(f, 0, sizeof f);
        f[0] = 1; // 不要忘记初始化！
        for (int a = 1; a <= n; ++a)
        {
            for (auto b = a; b <= n; ++b)
            {
                f[b] = (f[b] + f[b - a]) % 1000000007;
            }
        }
        return f[n];
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", count_division(n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0900_H
