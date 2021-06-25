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
    int getMinCover(Range *ranges, const unsigned int n, int start, const int end) {
        if (n == 0) {
            return -1;
        }
        sort(ranges, ranges + n);
        int result = 0;
        for (unsigned int i = 0; i < n; ++i) {
            unsigned int currentIdx = i;
            int maxRight = -2e9;
            while (currentIdx < n && ranges[currentIdx].left <= start) {
                maxRight = max(maxRight, ranges[currentIdx].right);
                ++currentIdx;
            }
            if (maxRight < start) {
                return -1;
            }
            ++result;
            if (maxRight >= end) {
                return result;
            }
            start = maxRight;
            i = currentIdx - 1;
        }
        return -1;
    }

    int main() {
        int start;
        int end;
        scanf("%d%d", &start, &end);
        unsigned int n;
        scanf("%d", &n);
        auto ranges = new Range[n];
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d%d", &ranges[i].left, &ranges[i].right);
        }
        printf("%d\n", getMinCover(ranges, n, start, end));
        delete[] ranges;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0907_H
