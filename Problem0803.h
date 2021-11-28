//
// Created by Fengwei Zhang on 2021/6/3.
//

#ifndef ACWINGSOLUTION_PROBLEM0803_H
#define ACWINGSOLUTION_PROBLEM0803_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Problem0803 {
    // 贪心算法：左端点排序
private:
    vector<pair<int, int>> mergeSegments(vector<pair<int, int>> &segments) {
        sort(segments.begin(), segments.end());
        const int invalidValue = -2e9;
        vector<pair<int, int>> result;
        int start = invalidValue;
        int end = invalidValue;
        for (auto &s: segments) {
            if (s.first > end) {
                if (end != invalidValue) {
                    result.emplace_back(pair<int, int>(start, end));
                }
                start = s.first;
                end = s.second;
            } else {
                end = max(end, s.second);
            }
        }
        if (end != invalidValue) {
            result.emplace_back(pair<int, int>(start, end));
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<pair<int, int>> segments(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &segments[i].first, &segments[i].second);
        }
        auto result = mergeSegments(segments);
        printf("%ld", result.size());
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0803_H
