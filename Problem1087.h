//
// Created by Fengwei Zhang on 2021/7/20.
//

#ifndef ACWINGSOLUTION_PROBLEM1087_H
#define ACWINGSOLUTION_PROBLEM1087_H

#include <iostream>

using namespace std;

class Problem1087 {
// https://www.acwing.com/solution/content/27326/
public:
    long long gFunc(const long long i, const long long *s, const long long *dp) {
        if (i == 0) {
            return 0;
        }
        return dp[i - 1] - s[i];
    }

    long long maxSeq(const long long *s, const long long N, const long long K) {
        auto dp = new long long[N + 1];
        dp[0] = 0;
        auto q = new long long[N + 1];
        long long hh = 0, tt = -1;
        q[++tt] = 0;
        for (long long i = 1; i <= N; ++i) {
            while (hh <= tt && q[hh] < i - K) {
                ++hh;
            }
            dp[i] = max(dp[i - 1], gFunc(q[hh], s, dp) + s[i]);
            while (hh <= tt && gFunc(q[tt], s, dp) <= gFunc(i, s, dp)) {
                --tt;
            }
            q[++tt] = i;
        }
        long long result = dp[N];
        delete[] dp;
        delete[] q;
        return result;
    }

    int main() {
        long long n, k;
        scanf("%lld%lld", &n, &k);
        auto s = new long long[n + 1];
        s[0] = 0;
        for (long long i = 1; i <= n; ++i) {
            scanf("%lld", &s[i]);
            s[i] += s[i - 1];
        }
        printf("%lld\n", maxSeq(s, n, k));
        delete[] s;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1087_H
