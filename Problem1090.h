//
// Created by Fengwei Zhang on 2021/7/20.
//

#ifndef ACWINGSOLUTION_PROBLEM1090_H
#define ACWINGSOLUTION_PROBLEM1090_H

#include <iostream>
#include <cstring>

using namespace std;

int q[50001];
int dp[50001];

class Problem1090 {
public:
    bool isValid(const int *cost, const int N, const int maxBlank, const int remainingTime) {
        memset(q, 0, sizeof q);
        memset(dp, 0, sizeof dp);
        int hh = 0, tt = 0;
        for (int i = 1; i <= N; ++i) {
            while (hh <= tt && q[hh] < i - maxBlank - 1) {
                ++hh;
            }
            dp[i] = dp[q[hh]] + cost[i];
            while (hh <= tt && dp[q[tt]] >= dp[i]) {
                --tt;
            }
            q[++tt] = i;
        }
        for (int i = N - maxBlank; i <= N; ++i) {
            if (dp[i] <= remainingTime) {
                return true;
            }
        }
        return false;
    }

    int main() {
        int N, remainingTime;
        scanf("%d%d", &N, &remainingTime);
        auto cost = new int[N + 1];
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &cost[i]);
        }
        int left = 0;
        int right = N;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isValid(cost, N, mid, remainingTime)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        delete[] cost;
        printf("%d\n", left);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1090_H
