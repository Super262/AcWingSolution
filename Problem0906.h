//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0906_H
#define ACWINGSOLUTION_PROBLEM0906_H

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Range {
    int left;
    int right;

    bool operator<(const Range &b) const {
        return left < b.left;
    }
};

class Problem0906 {
public:
    unsigned int minPartition(Range *ranges, const unsigned int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(ranges, ranges + n);
        for (unsigned int i = 0; i < n; ++i) {
            if (!pq.empty() && pq.top() < ranges[i].left) {
                pq.pop();
            }
            pq.emplace(ranges[i].right);
        }
        return pq.size();
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        auto ranges = new Range[n];
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d%d", &ranges[i].left, &ranges[i].right);
        }
        printf("%d\n", minPartition(ranges, n));
        delete[] ranges;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0906_H
