//
// Created by Fengwei Zhang on 2021/7/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0300_H
#define ACWINGSOLUTION_PROBLEM0300_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0300 {
    // https://www.acwing.com/solution/content/13391/
    // f[i]=min{ (f[j] + sumT[i] * (sumC[i] - sumC[j]) + S * (sumC[N] - sumC[j]) }
public:
    int minCost(const int *sumT, const int *sumC, const int N, const int s) {
        auto dp = new int[N + 1];
        memset(dp, 0x7f, sizeof(int) * (N + 1));
        dp[0] = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = min(dp[i], dp[j] + sumT[i] * (sumC[i] - sumC[j]) + s * (sumC[N] - sumC[j]));
            }
        }
        int result = dp[N];
        delete[] dp;
        return result;
    }

    int main() {
        int n, s;
        scanf("%d%d", &n, &s);
        auto sumC = new int[n + 1];
        auto sumT = new int[n + 1];
        memset(sumC, 0, sizeof(int) * (n + 1));
        memset(sumT, 0, sizeof(int) * (n + 1));
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &sumT[i], &sumC[i]);
            sumT[i] += sumT[i - 1];
            sumC[i] += sumC[i - 1];
        }
        printf("%d\n", minCost(sumT, sumC, n, s));
        delete[] sumT;
        delete[] sumC;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0300_H
