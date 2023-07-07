//
// Created by Fengwei Zhang on 2021/6/25.
//

#ifndef ACWINGSOLUTION_PROBLEM0907_H
#define ACWINGSOLUTION_PROBLEM0907_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0907 {
    // 1. 将所有区间按左端点从小到大排序
    // 2. 从前向后依次枚举每个区间，在所有能覆盖start的区间中，选择右端点最大的区间
    // 3. 将start更新成右端点最大值
private:
    struct Range {
        int left;
        int right;

        bool operator<(const Range &b) const {
            return left < b.left;
        }
    };

    int minCoverage(int start, const int end, Range ranges[], const int n) {
        sort(ranges, ranges + n);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            auto maxRight = start - 1;
            auto j = i;
            while (j < n && ranges[j].left <= start) {
                maxRight = max(maxRight, ranges[j].right);
                ++j;
            }
            if (maxRight < start) {
                return -1;
            }
            ++result;
            if (maxRight >= end) {
                return result;
            }
            start = maxRight;
            i = j - 1;
        }
        return -1;
    }

    int main() {
        int s, t;
        scanf("%d%d", &s, &t);
        int n;
        scanf("%d", &n);
        Range ranges[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &ranges[i].left, &ranges[i].right);
        }
        printf("%d\n", minCoverage(s, t, ranges, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0907_H
