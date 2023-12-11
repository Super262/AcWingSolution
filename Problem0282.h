//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0282_H
#define ACWINGSOLUTION_PROBLEM0282_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0282
{
private:
    int move_stones(const int *prefix, const int &n)
    {
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
        for (int l = 2; l <= n; ++l)
        {
            for (int st = 1, ed = st + l - 1; ed <= n; ++st, ++ed)
            {
                f[st][ed] = 0x7f7f7f7f;
                for (auto mid = st + 1, all_sum = prefix[ed] - prefix[st - 1]; mid <= ed; ++mid)
                {
                    f[st][ed] = min(f[st][ed], f[st][mid - 1] + f[mid][ed] + all_sum);
                }
            }
        }
        return f[1][n];
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        int prefix[n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &prefix[i]);
            prefix[i] += prefix[i - 1];
        }
        printf("%d\n", move_stones(prefix, n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0282_H
