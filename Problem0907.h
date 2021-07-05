//
// Created by Fengwei Zhang on 2021/6/25.
//

#ifndef ACWINGSOLUTION_PROBLEM0907_H
#define ACWINGSOLUTION_PROBLEM0907_H

#include <iostream>
#include <algorithm>

using namespace std;

struct Range {
    int left;
    int right;

    bool operator<(const Range &b) const {
        return left < b.left;
    }
};

class Problem0907 {
public:
    int minCover(int start, const int end, Range *ranges, const int N) {
        if (!ranges) {
            return -1;
        }
        sort(ranges, ranges + N);
        int result = 0;
        for (int i = 0; i < N; ++i) {
            int maxRight = -0x7f7f7f7f;
            int j = i;
            while (j < N && ranges[j].left <= start) {
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
        int start, end, n;
        scanf("%d%d%d", &start, &end, &n);
        auto ranges = new Range[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &ranges[i].left, &ranges[i].right);
        }
        printf("%d\n", minCover(start, end, ranges, n));
        delete[] ranges;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0907_H
