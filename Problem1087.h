//
// Created by Fengwei Zhang on 2021/7/20.
//

#ifndef ACWINGSOLUTION_PROBLEM1087_H
#define ACWINGSOLUTION_PROBLEM1087_H

#include <iostream>

using namespace std;

class Problem1087 {
// https://www.acwing.com/solution/content/27326/
private:
    const int N = 100005;
    long long s[N];
    long long q[N];
    long long dp[N];

    long long gFunc(int i) {
        if (i < 1) {
            return 0;
        }
        return dp[i - 1] - s[i];
    }

    long long maxSeq(int n, int k) {
        int hh = 0, tt = -1;
        q[++tt] = 0;
        for (int i = 1; i <= n; ++i) {
            while (hh <= tt && i - q[hh] + 1 > k + 1) {
                ++hh;
            }
            dp[i] = max(dp[i - 1], gFunc(q[hh]) + s[i]);
            while (hh <= tt && gFunc(q[tt]) <= gFunc(i)) {
                --tt;
            }
            q[++tt] = i;
        }
        return dp[n];
    }

    int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &s[i]);
            s[i] += s[i - 1];
        }
        printf("%lld\n", maxSeq(n, k));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1087_H
