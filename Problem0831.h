//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0831_H
#define ACWINGSOLUTION_PROBLEM0831_H

#include <iostream>

class Problem0831
{
private:
    void build_fail(const char *p, int *fail, const int &n)
    {
        fail[0] = 0;
        int l = 0;
        int r = 1;
        while (r < n)
        {
            if (p[l] == p[r])
            {
                ++l;
                fail[r] = l;
                ++r;
            }
            else if (l)
            {
                l = fail[l - 1];
            }
            else
            {
                fail[r] = 0;
                ++r;
            }
        }
    }

    void kmp(const char *s, const int &sl, const char *p, const int &pl)
    {
        int fail[pl];
        build_fail(p, fail, pl);
        int si = 0;
        int pi = 0;
        while (si < sl)
        {
            if (s[si] == p[pi])
            {
                ++si;
                ++pi;
            }
            else if (pi)
            {
                pi = fail[pi - 1];
            }
            else
            {
                ++si;
            }
            if (pi == pl)
            {
                printf("%d ", si - pl);
                pi = fail[pi - 1];
            }
        }
        printf("\n");
    }

    int main()
    {
        int pl;
        scanf("%d", &pl);
        char p[pl + 1];
        scanf("%s", p);
        int sl;
        scanf("%d", &sl);
        char s[sl + 1];
        scanf("%s", s);
        kmp(s, sl, p, pl);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0831_H
