//
// Created by Fengwei Zhang on 10/30/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0097_H
#define ACWINGSOLUTION_PROBLEM0097_H

#include <iostream>
#include <unordered_map>

using namespace std;

class Problem0097 {
private:
    const int MOD = 9901;

    unordered_map<int, int> getPrimeFactors(int n) {
        unordered_map<int, int> factors;
        for (int f = 2; f <= n / f; ++f) {
            while (n % f == 0) {
                ++factors[f];
                n /= f;
            }
        }
        if (n > 1) {
            ++factors[n];
        }
        return factors;
    }

    int quickExp(int a, int x) {
        int result = 1;
        while (x) {
            if (x & 1) {
                result = (int) ((long long) result * a % MOD);
            }
            a = (int) ((long long) a * a % MOD);
            x >>= 1;
        }
        return result;
    }

    int sumOfGeoSeq(const int &p, const int &k) {  // 求解等比数列（1 + ... + p ^ (k - 1)）的和
        if (k == 1) {
            return 1;
        }
        if (k % 2 == 0) {
            return ((int))((long long) (quickExp(p, k / 2) + 1) * sumOfGeoSeq(p, k / 2) % MOD);
        }
        return (quickExp(p, k - 1) + sumOfGeoSeq(p, k - 1)) % MOD;
    }

    int main() {
        int a, b;
        scanf("%d%d", &a, &b);
        auto primes = getPrimeFactors(a);
        int res = 1;
        for (auto it: primes) {
            auto p = it.first;
            auto k = it.second * b;
            res = (int) ((long long) res * sumOfGeoSeq(p, k + 1) % MOD);
        }
        if (a == 0) {
            res = 0;
        }
        printf("%d\n", res);
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0097_H
