//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0908_H
#define ACWINGSOLUTION_PROBLEM0908_H

#include <iostream>
#include <algorithm>

using namespace std;

struct Range {
    int l;
    int r;

    bool operator<(const Range &b) const {
        return r < b.r;
    }
};

class Problem0908 {
public:
    unsigned int minConnection(const Range *ranges, const unsigned int n) {
        unsigned int result = 0;
        int rightEnd = -1e9 - 1;
        for (unsigned int i = 0; i < n; ++i) {
            if (ranges[i].l <= rightEnd) {
                continue;
            }
            rightEnd = ranges[i].r;
            ++result;
        }
        return result;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        auto ranges = new Range[n];
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d%d", &ranges[i].l, &ranges[i].r);
        }
        sort(ranges, ranges + n);
        printf("%d\n", minConnection(ranges, n));
        delete[] ranges;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0908_H
