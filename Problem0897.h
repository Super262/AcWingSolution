//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0897_H
#define ACWINGSOLUTION_PROBLEM0897_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0897
{
private:
    int longest_common_sequence(const char *s1, const int &l1, const char *s2, const int &l2)
    {
        vector<vector<int>> f(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 1; i <= l1; ++i)
        {
            for (int j = 1; j <= l2; ++j)
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (s1[i] != s2[j])
                {
                    continue;
                }
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        return f[l1][l2];
    }

    int main()
    {
        int l1, l2;
        scanf("%d%d", &l1, &l2);
        char s1[l1 + 2];
        char s2[l2 + 2];
        scanf("%s", s1 + 1);
        scanf("%s", s2 + 1);
        printf("%d\n", longest_common_sequence(s1, l1, s2, l2));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0897_H
