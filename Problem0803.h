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
public:
    void mergeSegments(vector<pair<int, int>> &segments) {
        sort(segments.begin(), segments.end());
        const int invalidValue = -2e9;
        vector<pair<int, int>> result;
        int start = invalidValue;
        int end = invalidValue;
        for (auto &s: segments) {
            if (s.first > end) {
                if (start != invalidValue) {
                    result.emplace_back(pair<int, int>(start, end));
                }
                start = s.first;
                end = s.second;
            } else {
                end = max(end, s.second);
            }
        }
        if (start != invalidValue) {
            result.emplace_back(pair<int, int>(start, end));
        }
        segments = result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int l, r;
        vector<pair<int, int>> segments;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d\n", &l, &r);
            segments.emplace_back(pair<int, int>(l, r));
        }
        mergeSegments(segments);
        printf("%ld\n", segments.size());
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0803_H
