//
// Created by Fengwei Zhang on 2021/5/31.
//

#ifndef ACWINGSOLUTION_PROBLEM0795_H
#define ACWINGSOLUTION_PROBLEM0795_H

#include <cstdio>
#include <cstdlib>

class Problem0795
{
private:
    void getPrefixSum(const int *arr, size_t n, int *prefix_sum)
    {
        prefix_sum[0] = 0;
        for (size_t i = 1; i <= n; ++i)
        {
            prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
        }
    }

    int main()
    {
        size_t n, m;
        scanf("%llu%llu", &n, &m);

        int *arr = (int *)malloc(n * sizeof(int));
        int *prefix_sum = (int *)malloc((n + 1) * sizeof(int));

        for (size_t i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }

        getPrefixSum(arr, n, prefix_sum);
        for (size_t i = 0, l, r; i < m; ++i)
        {
            scanf("%llu%llu", &l, &r);
            printf("%d\n", prefix_sum[r] - prefix_sum[l - 1]);
        }

        free(arr);
        free(prefix_sum);

        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0795_H
