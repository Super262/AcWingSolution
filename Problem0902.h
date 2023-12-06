//
// Created by Fengwei Zhang on 2021/6/18.
//

#ifndef ACWINGSOLUTION_PROBLEM0902_H
#define ACWINGSOLUTION_PROBLEM0902_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0902
{
private:
    int edit_distance(const char *s1, const int &l1, const char *s2, const int &l2)
    {
        vector<vector<int>> f(l1 + 1, vector<int>(l2 + 1, 0));
        // 不要忘记初始化操作
        for (int i = 0; i <= l2; ++i)
        {
            f[0][i] = i;
        }
        for (int i = 0; i <= l1; ++i)
        {
            f[i][0] = i;
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
                f[i][j] = min(f[i][j], f[i][j - 1] + 1);
                f[i][j] = min(f[i][j], f[i - 1][j] + 1);
            }
        }
        return f[l1][l2];
    }

    int main()
    {
        int l1, l2;
        scanf("%d", &l1);
        char s1[l1 + 2];
        scanf("%s", s1 + 1);
        scanf("%d", &l2);
        char s2[l2 + 2];
        scanf("%s", s2 + 1);
        printf("%d\n", edit_distance(s1, l1, s2, l2));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0902_H
