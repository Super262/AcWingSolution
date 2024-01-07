//
// Created by Fengwei Zhang on 2021/6/26.
//

#ifndef ACWINGSOLUTION_PROBLEM0913_H
#define ACWINGSOLUTION_PROBLEM0913_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0913
{
private:
    long min_waiting_time(int *arr, const int &n)
    {
        sort(arr, arr + n);
        long result = 0;
        for (int i = 0; i < n; ++i)
        {
            result += (long)arr[i] * (n - i - 1);
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
        printf("%ld\n", min_waiting_time(arr, n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0913_H
