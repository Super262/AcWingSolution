//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0874_H
#define ACWINGSOLUTION_PROBLEM0874_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0874 {
public:
    unsigned long long eulerSum(const unsigned long long &n) {
        auto *phi = new unsigned long long[n + 1];
        auto *primes = new unsigned long long[n + 1];
        auto *isFiltered = new bool[n + 1];
        memset(phi, 0, (n + 1) * sizeof(unsigned long long));
        memset(primes, 0, (n + 1) * sizeof(unsigned long long));
        memset(isFiltered, 0, (n + 1) * sizeof(bool));
        phi[1] = 1;
        unsigned long long count = 0;
        for (unsigned long long f = 2; f <= n; ++f) {
            if (!isFiltered[f]) {
                primes[count++] = f;
                phi[f] = f - 1;
            }
            for (unsigned long long j = 0; primes[j] <= n / f; ++j) {
                isFiltered[primes[j] * f] = true;
                if (f % primes[j]) {
                    phi[f * primes[j]] = phi[f] * (primes[j] - 1);
                } else {
                    phi[f * primes[j]] = phi[f] * primes[j];
                    break;
                }
            }
        }
        unsigned long long sum = 0;
        for (unsigned long long i = 1; i <= n; ++i) {
            sum += phi[i];
        }
        return sum;
    }

    int main() {
        unsigned long long n;
        scanf("%lld", &n);
        printf("%lld\n", eulerSum(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0874_H
