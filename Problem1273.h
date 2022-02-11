//
// Created by Fengwei Zhang on 2/10/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1273_H
#define ACWINGSOLUTION_PROBLEM1273_H

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

static const int N = 200010, M = 18;

int dp[N][M];  // dp[i][j]：从i开始长度是2^j的区间中的最大值

void init(const int nums[], int n) {
    for (int j = 0; j < M; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            if (j) {
                dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            } else {
                dp[i][j] = nums[i];
            }
        }
    }
}

int query(int l, int r) {
    auto length = r - l + 1;
    auto k = (int) (log(length) / log(2));
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n + 1];
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nums[i]);
    }
    init(nums, n);
    int m;
    scanf("%d", &m);
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}

#endif //ACWINGSOLUTION_PROBLEM1273_H
