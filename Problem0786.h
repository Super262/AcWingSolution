//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0786_H
#define ACWINGSOLUTION_PROBLEM0786_H

#include <iostream>

using namespace std;

class Problem0786
{
private:
    void QuickSelect(int *nums, const int &st, const int & ed, const int &k)
    {
        if (st >= ed)
        {
            return;
        }
        auto p = nums[st + (ed - st) / 2];
        auto l = st - 1;
        auto r = ed + 1;
        while (l < r)
        {
            while (nums[++l] < p);
            while (nums[--r] > p);
            if (l < r)
            {
                swap(nums[l], nums[r]);
            }
        }
        if (k <= r - st + 1)
        {
            QuickSelect(nums, st, r, k);
        }
        else
        {
            QuickSelect(nums, r + 1, ed, k - (r - st + 1));
        }
    }

    int main()
    {
        int n;
        int k;
        scanf("%d%d", &n, &k);
        int nums[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &nums[i]);
        }
        QuickSelect(nums, 0, n - 1, k);
        printf("%d\n", nums[k - 1]);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0786_H
