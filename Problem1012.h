//
// Created by Fengwei Zhang on 2021/7/7.
//

#ifndef ACWINGSOLUTION_PROBLEM1012_H
#define ACWINGSOLUTION_PROBLEM1012_H

#include <algorithm>
#include <iostream>

using namespace std;

class Problem1012 {
public:
    int maxConnection(pair<int, int> *a, const int N) {
        sort(a, a + N);
        auto dp = new int[N];
        int result = 0;
        for (int i = 0; i < N; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (a[j].second >= a[i].second) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        delete[] dp;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto a = new pair<int, int>[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].first, &a[i].second);
        }
        printf("%d\n", maxConnection(a, n));
        delete[] a;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1012_H
