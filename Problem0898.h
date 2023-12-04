//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0898_H
#define ACWINGSOLUTION_PROBLEM0898_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0898
{
private:
    int max_path(const vector<vector<int>> &matrix, const int &n)
    {
        const int MIN_VALUE = -0x3f3f3f3f;
        vector<vector<int>> dp(2, vector<int>(n + 1, MIN_VALUE));
        dp[1][1] = matrix[1][1];
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - 1]) + matrix[i][j];
            }
        }
        auto result = MIN_VALUE;
        for (int i = 1; i <= n; ++i)
        {
            result = max(result, dp[n % 2][i]);
        }
        return result;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                scanf("%d", &matrix[i][j]);
            }
        }
        printf("%d\n", max_path(matrix, n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0898_H
