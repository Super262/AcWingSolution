//
// Created by Fengwei Zhang on 2021/6/13.
//

#ifndef ACWINGSOLUTION_PROBLEM0878_H
#define ACWINGSOLUTION_PROBLEM0878_H

#include <iostream>

using namespace std;

class Problem0878 {
public:
    long long exgcd(const long long a, long long &x, const long long b, long long &y) {
        if (!b) {
            x = 1;
            y = 0;
            return a;
        }
        long long x1, y1, gcd;
        gcd = exgcd(b, x1, a % b, y1);
        x = y1;
        y = x1 - a / b * y1;
        return gcd;
    }

    int main() {
        int n;
        scanf("%d", &n);
        long long a, b, m, gcd;
        long long x, y;
        while (n--) {
            scanf("%lld%lld%lld", &a, &b, &m);
            gcd = exgcd(a, x, m, y);
            if (b % gcd) {
                puts("impossible");
            } else {
                printf("%lld\n", x * (b / gcd) % m);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0878_H
