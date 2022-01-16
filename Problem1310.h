//
// Created by Fengwei Zhang on 1/15/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1310_H
#define ACWINGSOLUTION_PROBLEM1310_H

#include <iostream>

using namespace std;

class Problem1310 {
    // https://www.acwing.com/solution/content/24442/
private:
    long long Gcd(long long a, long long b) {
        while (b) {
            auto t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int main() {
        long long m, n;
        scanf("%lld%lld", &m, &n);
        long long t = (m + 1) * (n + 1);
        long long res = t * (t - 1) * (t - 2) / 6;
        res -= (n + 1) * ((m - 1) * m * (m + 1) / 6);
        res -= (m + 1) * ((n - 1) * n * (n + 1) / 6);
        for (long long i = 1; i <= m; ++i) {
            for (long long j = 1; j <= n; ++j) {
                res -= 2 * (Gcd(i, j) - 1) * (m - i + 1) * (n - j + 1);
            }
        }
        printf("%lld\n", res);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1310_H
