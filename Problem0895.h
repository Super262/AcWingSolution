//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0895_H
#define ACWINGSOLUTION_PROBLEM0895_H

#include <iostream>

using namespace std;

class Problem0895
{
private:
    int longest_ascending_subsequence(const int *arr, const int n)
    {
        int dp[n];
        for (int i = 0; i < n; ++i)
        {
            dp[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (arr[j] >= arr[i])
                {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            result = max(result, dp[i]);
        }
        return result;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", longest_ascending_subsequence(arr, n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0895_H
