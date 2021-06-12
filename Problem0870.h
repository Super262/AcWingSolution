//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0870_H
#define ACWINGSOLUTION_PROBLEM0870_H

#include <iostream>
#include <unordered_map>

using namespace std;

class Problem0870 {
public:
    void getFactorsCount(unsigned long n, unordered_map<unsigned long, unsigned long> &primeCount) {
        for (unsigned long f = 2; f <= n / f; ++f) {
            while (n % f == 0) {
                n /= f;
                ++primeCount[f];
            }
        }
        if (n > 1) {
            ++primeCount[n];
        }
    }

    int main() {
        int m;
        scanf("%d", &m);
        unsigned long n;
        unordered_map<unsigned long, unsigned long> primeCount;
        while (m--) {
            scanf("%ld", &n);
            getFactorsCount(n, primeCount);
        }
        unsigned long result = 1;
        const unsigned long base = 1e9 + 7;
        for (const auto &p:primeCount) {
            result *= p.second + 1;
            result %= base;
        }
        printf("%ld\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0870_H
