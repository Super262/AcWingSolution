//
// Created by Fengwei Zhang on 2021/6/26.
//

#ifndef ACWINGSOLUTION_PROBLEM0104_H
#define ACWINGSOLUTION_PROBLEM0104_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0104
{
private:
    long min_distance(int *coordinates, const int &n)
    {
        sort(coordinates, coordinates + n);
        const int mid = n >> 1; // 无论mid偏左或偏右（长度为偶数），结果都是正确的
        long result = 0;
        for (int i = 0; i < n; ++i)
        {
            result += abs(coordinates[i] - coordinates[mid]);
        }
        return result;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        int coordinates[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &coordinates[i]);
        }
        printf("%ld\n", min_distance(coordinates, n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0104_H
