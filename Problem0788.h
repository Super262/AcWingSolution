//
// Created by Fengwei Zhang on 2021/5/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0788_H
#define ACWINGSOLUTION_PROBLEM0788_H

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Problem0788
{
    // 注意为避免溢出，返回值的类型为size_t
    // 为便于改造（参考LeetCode 493），拆分归并过程和统计逆序对的过程
private:
    size_t myMergeCount(int *nums, size_t st, size_t ed, int *temp)
    {
        if (st >= ed)
        {
            return 0;
        }
        auto mid = st + (ed - st) / 2;
        auto answer = myMergeCount(nums, st, mid, temp) + myMergeCount(nums, mid + 1, ed, temp);
        auto l = st;
        auto r = mid + 1;
        while (r <= ed)
        { // 统计逆序对
            while (l <= mid && nums[l] <= nums[r])
            {
                ++l;
            }
            answer += mid - l + 1;
            ++r;
        }
        l = st;
        r = mid + 1;
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
        return answer;
    }

    int main()
    {
        size_t n;
        scanf("%llu", &n);
        int *nums = (int *)malloc(n * sizeof(int));
        int *temp = (int *)malloc(n * sizeof(int));
        for (size_t i = 0; i < n; ++i)
        {
            scanf("%d", &nums[i]);
        }
        if (!n)
        {
            printf("0\n");
        }
        printf("%llu\n", myMergeCount(nums, 0, n - 1, temp));
        free(nums);
        free(temp);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0788_H
