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
    int longest_ascending_subsequence(const int *arr, const int &n)
    {
        int f[n];
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            f[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (arr[j] >= arr[i])
                {
                    continue;
                }
                f[i] = max(f[i], f[j] + 1);
            }
            result = max(result, f[i]);
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
