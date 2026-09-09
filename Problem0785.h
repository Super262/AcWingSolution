//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0785_H
#define ACWINGSOLUTION_PROBLEM0785_H

#include <iostream>

using namespace std;

class Problem0785
{
private:
    // 类似题目：LeetCode 912
    // 这里的实现比LeetCode所用的解法稍快，所以不会在AcWing超时
void my_quick_sort(int *nums, int st, int ed)
{
    if (st >= ed)
        return;

    int p = nums[st + (ed - st + 1) / 2];
    // int p = nums[st + (ed - st) / 2];
    int l = st;
    int r = ed;

    while (l <= r)
    {
        while (nums[l] < p)
            ++l;

        while (nums[r] > p)
            --r;

        if (l <= r)
        {
            swap(nums[l], nums[r]);
            ++l;
            --r;
        }
    }

    my_quick_sort(nums, st, r);
    my_quick_sort(nums, l, ed);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *nums = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &nums[i]);

    my_quick_sort(nums, 0, n - 1);

    for (int i = 0; i < n; ++i)
        printf("%d ", nums[i]);

    printf("\n");
    free(nums);
    return 0;
}
};

#endif // ACWINGSOLUTION_PROBLEM0785_H
