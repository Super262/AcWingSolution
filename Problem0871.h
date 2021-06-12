//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0871_H
#define ACWINGSOLUTION_PROBLEM0871_H

#include <iostream>
#include <unordered_map>

using namespace std;

class Problem0871 {
public:
    void getFactorCount(unsigned long n, unordered_map<unsigned long, unsigned long> &factorCount) {
        for (unsigned long f = 2; f <= n / f; ++f) {
            while (n % f == 0) {
                n /= f;
                ++factorCount[f];
            }
        }
        if (n > 1) {
            ++factorCount[n];
        }
    }

    int main() {
        int m;
        scanf("%d", &m);
        unordered_map<unsigned long, unsigned long> factorCount;
        unsigned long n;
        while (m--) {
            scanf("%ld", &n);
            getFactorCount(n, factorCount);
        }
        const unsigned long base = 1e9 + 7;
        unsigned long result = 1;
        for (const auto &p:factorCount) {
            unsigned long temp = 1;
            for (unsigned long k = 0; k < p.second; ++k) {
                temp = temp * p.first + 1;
                temp %= base;
            }
            result *= temp;
            result %= base;
        }
        printf("%ld\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0871_H
