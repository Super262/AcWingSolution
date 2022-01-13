//
// Created by Fengwei Zhang on 1/12/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1298_H
#define ACWINGSOLUTION_PROBLEM1298_H

#include <iostream>

using namespace std;

class Problem1298 {
    // https://www.acwing.com/solution/content/47984/
private:
    long long ExGcd(long long a, long long &x, long long b, long long &y) {
        if (!b) {
            x = 1;
            y = 0;
            return a;
        }
        long long x1, y1;
        auto d = ExGcd(b, x1, a % b, y1);
        x = y1;
        y = x1 - a / b * y1;
        return d;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int m[n], a[n];
        long long M = 1;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &m[i], &a[i]);
            M *= m[i];
        }
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            auto Mi = M / m[i];
            long long ti, y;
            ExGcd(Mi, ti, m[i], y);
            res += a[i] * Mi * ti;
        }
        printf("%lld\n", (res % M + M) % M);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1298_H
