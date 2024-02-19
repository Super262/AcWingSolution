//
// Created by Fengwei Zhang on 2021/6/18.
//

#ifndef ACWINGSOLUTION_PROBLEM0899_H
#define ACWINGSOLUTION_PROBLEM0899_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0899
{
private:
    static const int N = 1000;
    static const int M = 12;
    int f[M][M];
    char strs[N][M];
    char temp[M];

    int edit_distance(const char *s1, const int &l1, const char *s2, const int &l2)
    {
        for (int i = 0; i <= l1; ++i)
        {
            f[i][0] = i;
        }
        for (int i = 0; i <= l2; ++i)
        {
            f[0][i] = i;
        }
        for (int i = 1; i <= l1; ++i)
        {
            for (int j = 1; j <= l2; ++j)
            {
                f[i][j] = l1 + l2 + 1;
                if (s1[i] == s2[j])
                {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                }
                else
                {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
                }
                f[i][j] = min(f[i][j], f[i - 1][j] + 1);
                f[i][j] = min(f[i][j], f[i][j - 1] + 1);
            }
        }
        return f[l1][l2];
    }

    int main()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", strs[i] + 1);
        }
        for (int i = 0, result, max_step; i < m; ++i)
        {
            result = 0;
            scanf("%s%d", temp + 1, &max_step);
            for (int j = 0; j < n; ++j)
            {
                if (edit_distance(strs[j], (int)strlen(strs[j] + 1), temp, (int)strlen(temp + 1)) <= max_step)
                {
                    ++result;
                }
            }
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0899_H
