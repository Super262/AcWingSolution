//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0908_H
#define ACWINGSOLUTION_PROBLEM0908_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0908 {
private:
    struct Range {
        int l;
        int r;

        bool operator<(const Range &b) const {
            return r < b.r;
        }
    };

    unsigned int minConnection(Range *ranges, const unsigned int n) {
        sort(ranges, ranges + n);
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
        Range ranges[n];
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d%d", &ranges[i].l, &ranges[i].r);
        }
        printf("%d\n", minConnection(ranges, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0908_H
