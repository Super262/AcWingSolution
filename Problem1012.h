//
// Created by Fengwei Zhang on 2021/7/7.
//

#ifndef ACWINGSOLUTION_PROBLEM1012_H
#define ACWINGSOLUTION_PROBLEM1012_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem1012 {
private:
    static const int N = 5000;
    pair<int, int> city_pairs[N];

    int mostLines(const int n) {
        int dp[n];
        sort(city_pairs, city_pairs + n);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (city_pairs[j].second >= city_pairs[i].second) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &city_pairs[i].first, &city_pairs[i].second);
        }
        printf("%d\n", mostLines(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1012_H
