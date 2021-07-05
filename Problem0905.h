//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0905_H
#define ACWINGSOLUTION_PROBLEM0905_H

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

class Problem0905 {
public:
    int minConnection(Range *ranges, const int N) {
        sort(ranges, ranges + N);
        int result = 0;
        int rightEnd = -0x7f7f7f7f;
        for (int i = 0; i < N; ++i) {
            if (ranges[i].left <= rightEnd) {
                continue;
            }
            ++result;
            rightEnd = ranges[i].right;
        }
        return result;
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
