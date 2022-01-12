//
// Created by Fengwei Zhang on 1/12/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0202_H
#define ACWINGSOLUTION_PROBLEM0202_H

#include <iostream>

using namespace std;

class Problem0202 {
    // https://www.acwing.com/solution/content/47979/
private:
    long long Gcd(long long a, long long b) {
        while (b) {
            auto t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    long long Euler(long long n) {
        long long res = n;
        for (long long f = 2; f <= n / f; ++f) {
            if (n % f) {
                continue;
            }
            while (n % f == 0) {
                n /= f;
            }
            res = res / f * (f - 1);
        }
        if (n > 1) {
            res = res / n * (n - 1);
        }
        return res;
    }

    long long SlowMultiply(long long a, long long b, const long long m) {
        long long res = 0;
        while (b) {
            if (b & 1) {
                res = (res + a) % m;
            }
            a = (a + a) % m;
            b >>= 1;
        }
        return res;
    }

    long long QuickPower(long long a, long long p, const long long m) {
        long long res = 1;
        while (p) {
            if (p & 1) {
                res = SlowMultiply(res, a, m);
            }
            a = SlowMultiply(a, a, m);
            p >>= 1;
        }
        return res;
    }

    int main() {
        int t = 1;
        long long l;
        while (true) {
            scanf("%lld", &l);
            if (l == 0) {
                break;
            }
            auto d = Gcd(l, 8);
            auto c = 9 * l / d;
            auto phi = Euler(c);
            long long res = 1e18;
            if (c % 2 == 0 || c % 5 == 0) {
                res = 0;
            } else {
                for (long long f = 1; f <= phi / f; ++f) {
                    if (phi % f) {
                        continue;
                    }
                    if (QuickPower(10, f, c) == 1) {
                        res = min(res, f);
                    }
                    if (QuickPower(10, phi / f, c) == 1) {
                        res = min(res, phi / f);
                    }
                }
            }
            printf("Case %d: %lld\n", t, res);
            ++t;
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0202_H
