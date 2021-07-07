//
// Created by Fengwei Zhang on 2021/7/7.
//

#ifndef ACWINGSOLUTION_PROBLEM1010_H
#define ACWINGSOLUTION_PROBLEM1010_H

#include <iostream>

using namespace std;

class Problem1010 {
public:
    int LIS(const int *a, const int N) {
        auto dp = new int[N];
        int result = 1;
        for (int i = N - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = N - 1; j > i; --j) {
                if (a[j] > a[i]) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        delete[] dp;
        return result;
    }

    int minLISsSet(const int *a, const int N) {
        int count = 0;
        auto LISTail = new int[N];
        for (int i = 0; i < N; ++i) {
            int k = 0;
            while (k < count && LISTail[k] < a[i]) {
                ++k;
            }
            LISTail[k] = a[i];
            if (k == count) {
                ++count;
            }
        }
        delete[] LISTail;
        return count;
    }

    int main() {
        auto a = new int[1000];
        int n = 0;
        while (cin >> a[n]) {
            ++n;
        }
        printf("%d\n", LIS(a, n));
        printf("%d\n", minLISsSet(a, n));
        delete[] a;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1010_H
