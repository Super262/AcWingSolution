//
// Created by Fengwei Zhang on 1/10/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0197_H
#define ACWINGSOLUTION_PROBLEM0197_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0197 {
private:
    int CountPrimes(const int n, int primes[], bool filtered[]) {
        int cnt = 0;
        for (int f = 2; f <= n; ++f) {
            if (!filtered[f]) {
                primes[cnt++] = f;
            }
            for (int i = 0; primes[i] <= n / f; ++i) {
                filtered[primes[i] * f] = true;
                if (f % primes[i] == 0) {
                    break;
                }
            }
        }
        return cnt;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int primes[n + 1];
        bool filtered[n + 1];
        memset(primes, 0, sizeof primes);
        memset(filtered, 0, sizeof filtered);
        auto cnt = CountPrimes(n, primes, filtered);
        for (int i = 0; i < cnt; ++i) {
            auto p = primes[i];
            int s = 0;
            for (int j = n; j > 0; j /= p) {
                s += j / p;
            }
            if (s == 0) {
                continue;
            }
            printf("%d %d\n", p, s);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0197_H
