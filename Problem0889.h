//
// Created by Fengwei Zhang on 2021/6/15.
//

#ifndef ACWINGSOLUTION_PROBLEM0889_H
#define ACWINGSOLUTION_PROBLEM0889_H

#include <iostream>

using namespace std;

class Problem0889 {
public:
    unsigned int qmi(unsigned int a, unsigned int x, const unsigned int mod) {
        unsigned int result = 1;
        while (x) {
            if (x & 1) {
                result = (unsigned int) ((unsigned long long) result * a % mod);
            }
            a = (unsigned int) ((unsigned long long) a * a % mod);
            x >>= 1;
        }
        return result;
    }

    unsigned int catalanNumber(const unsigned int n) {
        // 1 / (n + 1) * C(2 * n, n) = (2 * n)! / (n! * n!) == ((n + 1) * ... * (2 * n)) / n!
        const unsigned mod = 1e9 + 7;
        unsigned int result = 1;
        for (unsigned i = n + 1; i <= 2 * n; ++i) {
            result = (unsigned int) ((unsigned long long) result * i % mod);
        }
        for (unsigned i = 1; i <= n; ++i) {
            result = (unsigned int) ((unsigned long long) result * qmi(i, mod - 2, mod) % mod);
        }
        result = (unsigned int) ((unsigned long long) result * qmi(n + 1, mod - 2, mod) % mod);
        return result;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        printf("%d", catalanNumber(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0889_H
