//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0868_H
#define ACWINGSOLUTION_PROBLEM0868_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0868 {
public:
    int primesCount(const int n) {
        bool *isNotPrime = new bool[n + 1];
        int *primes = new int[n + 1];
        memset(isNotPrime, 0, (n + 1) * sizeof(bool));
        memset(primes, 0, (n + 1) * sizeof(int));
        int result = 0;
        for (int f = 2; f <= n; ++f) {
            if (!isNotPrime[f]) {
                primes[result++] = f;
            }
            for (int j = 0; primes[j] <= n / f; ++j) {
                isNotPrime[primes[j] * f] = true;
                if (f % primes[j] == 0) {
                    break;
                }
            }
        }
        delete[] isNotPrime;
        delete[] primes;
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        printf("%d", primesCount(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0868_H
