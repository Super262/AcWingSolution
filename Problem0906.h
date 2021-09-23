//
// Created by Fengwei Zhang on 2021/6/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0906_H
#define ACWINGSOLUTION_PROBLEM0906_H

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Problem0906 {
    // 1. 将所有区间按照左端点从小到大排序
    // 2. 从前向后处理每个区间：判断能否将其放到某个现有的组i中（left > minRight[i]）
    // 3. 如果不存在这样的组，就开设一个新组；如果存在这样的组j，则将其放入并更新minRight[j]
private:
    struct Range {
        int left;
        int right;

        bool operator<(const Range &b) const {
            return left < b.left;
        }
    };

    int minPartition(Range ranges[], const int n) {
        sort(ranges, ranges + n);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; ++i) {
            if (pq.empty()) {
                pq.emplace(ranges[i].right);
                continue;
            }
            if (pq.top() >= ranges[i].left) {
                // 不存在这样的组
                pq.emplace(ranges[i].right);
            } else {
                // 存在这样的组，更新最小值
                pq.pop();
                pq.emplace(ranges[i].right);
            }
        }
        return (int) pq.size();
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto ranges = new Range[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &ranges[i].left, &ranges[i].right);
        }
        printf("%d\n", minPartition(ranges, n));
        delete[] ranges;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0906_H
