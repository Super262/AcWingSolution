//
// Created by Fengwei Zhang on 2021/6/3.
//

#ifndef ACWINGSOLUTION_PROBLEM0802_H
#define ACWINGSOLUTION_PROBLEM0802_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Problem0802 {
public:
    unsigned long getRealIndex(const vector<int> &indices, int index) {
        unsigned long left = 0;
        unsigned long right = indices.size() - 1;
        unsigned long mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (indices[mid] >= index) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right + 1;  // 目标索引从1开始
    }

    int main() {
        unsigned long n, m;
        scanf("%ld%ld", &n, &m);
        vector<int> indices;
        vector<pair<int, int>> addRequests;
        vector<pair<int, int>> queryRequests;
        for (int i = 0; i < n; ++i) {
            int x, c;
            scanf("%d%d", &x, &c);
            addRequests.emplace_back(pair<int, int>(x, c));
            indices.emplace_back(x);
        }
        for (int i = 0; i < m; ++i) {
            int l, r;
            scanf("%d%d", &l, &r);
            queryRequests.emplace_back(pair<int, int>(l, r));
            indices.emplace_back(l);
            indices.emplace_back(r);
        }
        sort(indices.begin(), indices.end());
        indices.erase(unique(indices.begin(), indices.end()), indices.end());
        vector<int> data(indices.size() + 1, 0);
        unsigned long realIndex;
        for (const auto &item:addRequests) {
            realIndex = getRealIndex(indices, item.first);
            data[realIndex] += item.second;
        }
        for (unsigned long i = 1; i < data.size(); ++i) {
            data[i] += data[i - 1];
        }
        unsigned long leftIndex, rightIndex;
        for (const auto &item:queryRequests) {
            leftIndex = getRealIndex(indices, item.first);
            rightIndex = getRealIndex(indices, item.second);
            printf("%d\n", data[rightIndex] - data[leftIndex - 1]);
        }
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0802_H
