//
// Created by Fengwei Zhang on 2021/6/13.
//

#ifndef ACWINGSOLUTION_PROBLEM0878_H
#define ACWINGSOLUTION_PROBLEM0878_H

#include <iostream>

using namespace std;

class Problem0878 {
    // https://www.acwing.com/solution/content/5937/
    // a*x+m*y=b有解，当且仅当gcd(a,m)整除b
private:
    int ExGcd(const int a, int &x, const int b, int &y) {
        if (!b) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1, gcd;
        gcd = ExGcd(b, x1, a % b, y1);
        x = y1;
        y = x1 - a / b * y1;
        return gcd;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int a, b, m, gcd;
        int x, y;
        while (n--) {
            scanf("%d%d%d", &a, &b, &m);
            gcd = ExGcd(a, x, m, y);
            if (b % gcd) {
                puts("impossible");
            } else {
                printf("%lld\n", (long long) x * (b / gcd) % m);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0878_H
