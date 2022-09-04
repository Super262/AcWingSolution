//
// Created by Fengwei Zhang on 2021/7/20.
//

#ifndef ACWINGSOLUTION_PROBLEM1090_H
#define ACWINGSOLUTION_PROBLEM1090_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1090 {
private:
    static const int N = 50010;
    int q[N];
    int cost[N];
    int dp[N];

    bool canFinish(const int n, const int blank, const int timeLimit) {
        int hh = 0, tt = -1;
        memset(dp, 0, sizeof dp);
        q[++tt] = 0;
        for (int i = 1; i <= n; ++i) {
            while (hh <= tt && i - q[hh] + 1 > blank + 2) {
                ++hh;
            }
            dp[i] = dp[q[hh]] + cost[i];
            while (hh <= tt && dp[i] <= dp[q[tt]]) {
                --tt;
            }
            q[++tt] = i;
        }
        for (int i = n - blank; i <= n; ++i) {
            if (dp[i] <= timeLimit) {
                return true;
            }
        }
        return false;
    }

    int findMaxBlank(const int n, const int timeLimit) {
        int left = 0;
        int right = n;
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (canFinish(n, mid, timeLimit)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int main() {
        int n, timeLimit;
        scanf("%d%d", &n, &timeLimit);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &cost[i]);
        }
        printf("%d\n", findMaxBlank(n, timeLimit));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1090_H
