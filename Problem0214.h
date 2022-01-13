//
// Created by Fengwei Zhang on 1/12/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0214_H
#define ACWINGSOLUTION_PROBLEM0214_H

#include <iostream>

using namespace std;

class Problem0214 {
    // https://www.acwing.com/solution/content/25966/
private:
    long long QuickPower(long long a, long long p, const long long m) {
        long long res = 1;
        while (p) {
            if (p & 1) {
                res = res * a % m;
            }
            a = a * a % m;
            p >>= 1;
        }
        return res;
    }

    long long Comb(const long long a, const long long b, const long long inverse_denominator, const long long m) {
        if (a < b) {
            return 0;
        }
        long long molecular = 1;
        for (auto i = a; i > a - b; --i) {
            molecular = i % m * molecular % m;
        }
        return molecular * inverse_denominator % m;
    }

    int main() {
        const int MOD = 1e9 + 7;
        long long n, m;
        scanf("%lld%lld", &n, &m);
        long long box[n];
        for (long long i = 0; i < n; ++i) {
            scanf("%lld", &box[i]);
        }
        long long inverse_denominator = 1;
        for (long long i = 1; i <= n - 1; ++i) {
            inverse_denominator = i * inverse_denominator % MOD;
        }
        inverse_denominator = QuickPower(inverse_denominator, MOD - 2, MOD);
        long long res = 0;
        for (int s = 0; s < (1 << n); ++s) {
            auto a = m + n - 1;
            auto b = n - 1;
            int sign = 1;
            for (int i = 0; i < n; ++i) {
                if (((s >> i) & 1) == 0) {
                    continue;
                }
                sign *= -1;
                a -= box[i] + 1;
            }
            res = (res + Comb(a, b, inverse_denominator, MOD) * sign) % MOD;
        }
        res = (res + MOD) % MOD;
        printf("%lld\n", res);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0214_H
