//
// Created by Fengwei Zhang on 2021/6/14.
//

#ifndef ACWINGSOLUTION_PROBLEM0887_H
#define ACWINGSOLUTION_PROBLEM0887_H

#include <iostream>

using namespace std;

class Problem0887 {
public:
    unsigned int qmi(unsigned int a, unsigned int x, const unsigned int &m) {
        unsigned int result = 1;
        while (x) {
            if (x & 1) {
                result = (unsigned int) ((unsigned long long) result * a % m);
            }
            x >>= 1;
            a = (unsigned int) ((unsigned long long) a * a % m);
        }
        return result;
    }

    unsigned int combinatorialNumber(const unsigned int &n, const unsigned int &m, const unsigned int &p) {
        unsigned int result = 1;
        for (unsigned int i = 1, j = n; i <= m; ++i, --j) {
            result = (unsigned int) ((unsigned long long) result * j % p);
            result = (unsigned int) ((unsigned long long) result * qmi(i, p - 2, p) % p);
        }
        return result;
    }

    unsigned int lucas(const unsigned long long &n, const unsigned long long &m, const unsigned int &p) {
        if (n < p && m < p) {
            return combinatorialNumber((unsigned int) n, (unsigned int) m, p);
        }
        return (unsigned int) ((unsigned long long) combinatorialNumber(n % p, m % p, p) * lucas(n / p, m / p, p) % p);
    }

    int main() {
        int n;
        scanf("%d", &n);
        unsigned long long a, b;
        unsigned int p;
        while (n--) {
            scanf("%lld%lld%d", &a, &b, &p);
            printf("%d\n", lucas(a, b, p));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0887_H
