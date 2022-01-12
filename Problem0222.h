//
// Created by Fengwei Zhang on 1/12/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0222_H
#define ACWINGSOLUTION_PROBLEM0222_H

#include <iostream>
#include <cmath>

using namespace std;

class Problem0222 {
    // https://www.acwing.com/solution/content/24456/
private:
    long long ExGcd(long long a, long long &x, long long b, long long &y) {
        if (!b) {
            x = 1;
            y = 0;
            return a;
        }
        long long x1, y1, gcd;
        gcd = ExGcd(b, x1, a % b, y1);
        x = y1;
        y = x1 - a / b * y1;
        return gcd;
    }

    int main() {
        long long a, b, m, n, l;
        scanf("%lld%lld%lld%lld%lld", &a, &b, &m, &n, &l);
        long long x, y;
        auto d = ExGcd(m - n, x, -l, y);
        if ((b - a) % d) {
            puts("Impossible");
        } else {
            auto t = abs(-l / d);
            printf("%lld\n", ((b - a) / d * x % t + t) % t);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0222_H
