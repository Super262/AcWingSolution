//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0789_H
#define ACWINGSOLUTION_PROBLEM0789_H

#include <cstdio>
#include <cstdlib>

class Problem0789
{
private:
    void getRangeForElement(const int *nums, const size_t &n, const int &element)
    {
        size_t l = 0;
        auto r = n - 1;
        size_t mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] >= element)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (nums[r] != element)
        {
            printf("-1 -1\n");
            return;
        }
        printf("%llu ", r);
        l = 0;
        r = n - 1;
        while (l < r)
        {
            mid = l + (r - l + 1) / 2;
            if (nums[mid] <= element)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (nums[l] != element)
        {
            printf("-1 -1\n");
            return;
        }
        printf("%llu\n", l);
    }

    int main()
    {
        size_t n;
        size_t k;
        scanf("%llu%llu", &n, &k);

        int *nums = (int *)malloc(n * sizeof(int));
        for (size_t i = 0; i < n; ++i)
        {
            scanf("%d", &nums[i]);
        }

        int temp;
        for (size_t i = 0; i < k; ++i)
        {
            scanf("%d", &temp);
            getRangeForElement(nums, n, temp);
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0789_H
