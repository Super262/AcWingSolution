//
// Created by Fengwei Zhang on 2021/7/7.
//

#ifndef ACWINGSOLUTION_PROBLEM1012_H
#define ACWINGSOLUTION_PROBLEM1012_H

#include <algorithm>
#include <iostream>

using namespace std;

class Problem1012 {
private:
    const int N = 5000;
    pair<int, int> cityPairs[N];
    int dp[N];

    int mostLines(const int n) {
        sort(cityPairs, cityPairs + n);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (cityPairs[j].second >= cityPairs[i].second) {
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
            scanf("%d%d", &cityPairs[i].first, &cityPairs[i].second);
        }
        printf("%d\n", mostLines(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1012_H
