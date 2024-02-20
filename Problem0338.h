//
// Created by Fengwei Zhang on 2/13/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0338_H
#define ACWINGSOLUTION_PROBLEM0338_H

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Problem0338
{
    // 经典思路，必须牢记：https://www.acwing.com/solution/content/33672/
    // f[i][j][u]：长度为i、最高位为j的数拥有u的个数
    // 同时掌握记忆化搜索的方式，将前缀信息记录在状态转移的参数中：https://www.acwing.com/solution/content/6570/
private:
    static const int N = 11; // 输入数字的最大长度为N-1
    static const int M = 10; // 输入数字每位最大值为M-1
    int f[N][M][M];

    void init()
    {
        for (int i = 0; i < M; ++i)
        {
            f[1][i][i] = 1;
        }
        for (int l = 2; l < N; ++l)
        {
            for (int j = 0; j < M; ++j)
            {
                for (int u = 0; u < M; ++u)
                {
                    if (u == j)
                    {
                        f[l][j][u] += (int)pow(M, l - 1);
                    }
                    for (int k = 0; k < M; ++k)
                    {
                        f[l][j][u] += f[l - 1][k][u];
                    }
                }
            }
        }
    }

    int dp(int n, const int &u)
    {
        if (n < M)
        {
            return n >= u ? 1 : 0;
        }
        int digits[N];
        int length = 0;
        while (n)
        {
            digits[length] = n % M;
            n /= M;
            ++length;
        }
        int ans = 0;
        int prefix = 0;
        for (auto i = length - 1; i >= 0; --i)
        { // 统计小于和等于n的“length位数“含u的个数
            auto x = digits[i];
            for (int j = (i == length - 1 ? 1 : 0); j < x; ++j)
            { // 统计x及后面（右侧低位）部分含u的情况，最高位忽略前导0
                ans += f[i + 1][j][u];
            }
            ans += prefix * x * (int)pow(M, i); // 统计x前面（左侧高位）部分含u的情况
            if (x == u)
            {
                ++prefix;
            }
            if (!i)
            {
                ans += prefix;
            }
        }
        for (int l = 1; l < length; ++l)
        { // 统计小于n的“非length位数“含u的个数
            for (int j = (l != 1 ? 1 : 0); j < M; ++j)
            { // 最高位忽略前导0
                ans += f[l][j][u];
            }
        }
        return ans;
    }

    int main()
    {
        init();
        int l, r;
        while (true)
        {
            scanf("%d%d", &l, &r);
            if (!l && !r)
            {
                return 0;
            }
            if (l > r)
            { // 特殊情况
                swap(l, r);
            }
            for (int u = 0; u < M; ++u)
            {
                printf("%d ", dp(r, u) - dp(l - 1, u));
            }
            printf("\n");
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0338_H
