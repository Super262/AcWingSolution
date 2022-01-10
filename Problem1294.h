//
// Created by Fengwei Zhang on 1/10/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1294_H
#define ACWINGSOLUTION_PROBLEM1294_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1294 {
    // https://www.acwing.com/solution/content/11665/
private:
    int GetPrimes(const int n, int primes[], bool filtered[]) {
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
        const int MOD = 1000000007;
        int n;
        scanf("%d", &n);
        int primes[n + 1];
        bool filtered[n + 1];
        memset(primes, 0, sizeof primes);
        memset(filtered, 0, sizeof filtered);
        auto cnt = GetPrimes(n, primes, filtered);
        long long res = 1;
        for (int i = 0; i < cnt; ++i) {
            int s = 0;
            for (int j = n; j > 0; j /= primes[i]) {
                s += j / primes[i];
            }
            res *= (2 * s + 1);
            res %= MOD;
        }
        printf("%lld\n", res);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1294_H
