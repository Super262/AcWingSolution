//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0787_H
#define ACWINGSOLUTION_PROBLEM0787_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0787
{
private:
    void merge_sort(int *nums, int st, int ed, int *temp)
    {
        if (st >= ed)
        {
            return;
        }
        auto mid = st + (ed - st) / 2;
        merge_sort(nums, st, mid, temp);
        merge_sort(nums, mid + 1, ed, temp);
        auto l = st;
        auto r = mid + 1;
        auto t = st;
        while (l <= mid && r <= ed)
        {
            if (nums[l] <= nums[r])
            {
                temp[t] = nums[l];
                ++l;
            }
            else
            {
                temp[t] = nums[r];
                ++r;
            }
            ++t;
        }
        while (l <= mid)
        {
            temp[t] = nums[l];
            ++l;
            ++t;
        }
        while (r <= ed)
        {
            temp[t] = nums[r];
            ++r;
            ++t;
        }
        memcpy(nums + st, temp + st, (ed - st + 1) * sizeof(int));
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        int nums[n];
        int temp[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &nums[i]);
        }
        merge_sort(nums, 0, n - 1, temp);
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", nums[i]);
        }
        printf("\n");
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0787_H
