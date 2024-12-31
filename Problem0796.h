//
// Created by Fengwei Zhang on 2021/5/31.
//

#ifndef ACWINGSOLUTION_PROBLEM0796_H
#define ACWINGSOLUTION_PROBLEM0796_H

#include <cstdio>
#include <cstdlib>

class Problem0796
{
private:
    void getPrefixSum(int **matrix, size_t n, size_t m, int **prefix_sum)
    {
        for (size_t i = 1; i <= n; ++i)
        {
            for (size_t j = 1; j <= m; ++j)
            {
                prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int main()
    {
        size_t n, m, q;
        scanf("%llu%llu%llu", &n, &m, &q);

        int **matrix = (int **)malloc(n * sizeof(int *));
        for (size_t i = 0; i < n; ++i)
        {
            matrix[i] = (int *)malloc(m * sizeof(int));
            for (size_t j = 0; j < m; ++j)
            {
                scanf("%d", &matrix[i][j]);
            }
        }

        int **prefix_sum = (int **)malloc((n + 1) * sizeof(int *));
        for (size_t i = 0; i < n + 1; ++i)
        {
            // 将prefix_sum第0行和第0列所有元素初始化为0
            if (i)
            {
                prefix_sum[i] = (int *)malloc((m + 1) * sizeof(int));
                prefix_sum[i][0] = 0;
            }
            else
            {
                prefix_sum[i] = (int *)calloc(m + 1, sizeof(int));
            }
        }

        getPrefixSum(matrix, n, m, prefix_sum);

        for (size_t i = 0, x1, y1, x2, y2; i < q; ++i)
        {
            scanf("%llu%llu%llu%llu", &x1, &y1, &x2, &y2);
            printf("%d\n", prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] - prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1]);
        }

        for (size_t i = 0; i < n; ++i)
        {
            free(matrix[i]);
        }
        free(matrix);

        for (size_t i = 0; i < n + 1; ++i)
        {
            free(prefix_sum[i]);
        }
        free(prefix_sum);

        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0796_H
