//
// Created by Fengwei Zhang on 10/31/21.
//

#ifndef ACWINGSOLUTION_PROBLEM3068_H
#define ACWINGSOLUTION_PROBLEM3068_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Problem3068 {
private:
    long long segArea(const int &s,
                      const int &e,
                      const pair<int, int> leftBottom[],
                      const pair<int, int> rightTop[],
                      const int &n) {
        vector<pair<int, int>> ySegs;
        for (int i = 0; i < n; ++i) {
            if (leftBottom[i].first > s || rightTop[i].first < e) {
                continue;
            }
            ySegs.emplace_back(pair<int, int>(leftBottom[i].second, rightTop[i].second));
        }
        if (ySegs.empty()) {
            return 0;
        }
        sort(ySegs.begin(), ySegs.end());
        int st = ySegs[0].first;
        int ed = ySegs[0].second;
        long long result = 0;
        for (int i = 1; i < (int) ySegs.size(); ++i) {
            if (ySegs[i].first <= ed) {
                ed = max(ed, ySegs[i].second);
            } else {
                result += ed - st;
                st = ySegs[i].first;
                ed = ySegs[i].second;
            }
        }
        result += ed - st;
        return result * (e - s);
    }

    int main() {
        int n;
        scanf("%d", &n);
        pair<int, int> leftBottom[n];
        pair<int, int> rightTop[n];
        vector<int> xs;
        for (int i = 0; i < n; ++i) {
            auto &lb = leftBottom[i];
            auto &rt = rightTop[i];
            scanf("%d%d%d%d", &lb.first, &lb.second, &rt.first, &rt.second);
            xs.emplace_back(lb.first);
            xs.emplace_back(rt.first);
        }
        sort(xs.begin(), xs.end());
        long long result = 0;
        for (int i = 0; i + 1 < (int) xs.size(); ++i) {
            if (xs[i] == xs[i + 1]) {
                continue;
            }
            result += segArea(xs[i], xs[i + 1], leftBottom, rightTop, n);
        }
        printf("%lld\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM3068_H
