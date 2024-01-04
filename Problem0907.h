//
// Created by Fengwei Zhang on 2021/6/25.
//

#ifndef ACWINGSOLUTION_PROBLEM0907_H
#define ACWINGSOLUTION_PROBLEM0907_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0907
{
    // 1. 将所有区间按左端点从小到大排序
    // 2. 从前向后依次枚举每个区间，在所有能覆盖start的区间中，选择右端点最大的区间
    // 3. 将start更新成右端点最大值
private:
    struct Range
    {
        int left;
        int right;

        bool operator<(const Range &b) const
        {
            return left < b.left;
        }
    };

    int min_coverage(int start, const int &end, Range *ranges, const int &n)
    {
        sort(ranges, ranges + n);
        for (int i = 0, max_right, result = 0; i < n;)
        {
            max_right = start - 1;
            while (i < n && ranges[i].left <= start)
            {
                max_right = max(max_right, ranges[i].right);
                ++i;
            }
            if (max_right < start)
            {
                return -1;
            }
            ++result;
            if (max_right >= end)
            {
                return result;
            }
            start = max_right;
        }
        return -1;
    }

    int main()
    {
        int s, t;
        scanf("%d%d", &s, &t);
        int n;
        scanf("%d", &n);
        Range ranges[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &ranges[i].left, &ranges[i].right);
        }
        printf("%d\n", min_coverage(s, t, ranges, n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0907_H
