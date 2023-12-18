//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0905_H
#define ACWINGSOLUTION_PROBLEM0905_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0905
{
    // 1. 将每个区间按右端点从小到大排序
    // 2. 从前向后依次枚举每个区间：如果当前区间中已经包含点，跳过：否则，选择当前区间的右端点
private:
    struct Range
    {
        int left;
        int right;

        bool operator<(const Range &b) const
        {
            return right < b.right;
        }
    };

    int min_connection(Range *ranges, const int &n)
    {
        int ans = 0;
        int end = -0x7f7f7f7f;
        sort(ranges, ranges + n);
        for (int i = 0; i < n; ++i)
        {
            if (ranges[i].left <= end)
            {
                continue;
            }
            ++ans;
            end = ranges[i].right;
        }
        return ans;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        Range ranges[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &ranges[i].left, &ranges[i].right);
        }
        printf("%d\n", min_connection(ranges, n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0905_H
