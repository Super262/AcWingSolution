//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0905_H
#define ACWINGSOLUTION_PROBLEM0905_H

#include <iostream>
#include <algorithm>

using namespace std;

struct Range {
    int left;
    int right;

    bool operator<(const Range &b) const {
        return right < b.right;
    }
};

class Problem0905 {
    // 1. 将每个区间按右端点从小到大排序
    // 2. 从前向后依次枚举每个区间：如果当前区间中已经包含点，跳过：否则，选择当前区间的右端点
public:
    int minConnection(Range *ranges, const int N) {
        sort(ranges, ranges + N);
        int ans = 0;
        int end = -0x7f7f7f7f;
        for (int i = 0; i < N; ++i) {
            if (ranges[i].left <= end) {
                continue;
            }
            ++ans;
            end = ranges[i].right;
        }
        return ans;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto ranges = new Range[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &ranges[i].left, &ranges[i].right);
        }
        printf("%d\n", minConnection(ranges, n));
        delete[] ranges;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0905_H
