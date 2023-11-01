//
// Created by Fengwei Zhang on 2021/5/31.
//

#ifndef ACWINGSOLUTION_PROBLEM0798_H
#define ACWINGSOLUTION_PROBLEM0798_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0798
{
private:
    void matrixIncrease(vector<vector<int>> &diff, const int &x1, const int &y1, const int &x2, const int &y2, const int &v)
    {
        diff[x1][y1] += v;
        diff[x2 + 1][y1] -= v;
        diff[x1][y2 + 1] -= v;
        diff[x2 + 1][y2 + 1] += v;
    }

    int main()
    {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);

        // 行数至少为n+2，列数至少为m+2；否则，触发越界异常！
        vector<vector<int>> matrix(n + 2, vector<int>(m + 2, 0));
        for (int i = 1, t; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                scanf("%d", &t);
                matrixIncrease(matrix, i, j, i, j, t);
            }
        }
        for (int i = 0, x1, y1, x2, y2, t; i < q; ++i)
        {
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &t);
            matrixIncrease(matrix, x1, y1, x2, y2, t);
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0798_H
