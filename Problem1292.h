//
// Created by Fengwei Zhang on 1/8/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1292_H
#define ACWINGSOLUTION_PROBLEM1292_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1292 {
private:
    void GetPrimes(const int n, int primes[], bool filtered[]) {
        int cnt = 0;
        for (int f = 2; f <= n; ++f) {
            if (!filtered[f]) {
                primes[cnt++] = f;
            }
            for (int i = 0; primes[i] <= n / f; ++i) {
                filtered[primes[i] * f] = true;
                if (primes[i] % f == 0) {
                    break;
                }
            }
        }
    }

    int main() {
        const int N = 1000000;
        int primes[N + 1];
        bool filtered[N + 1];
        memset(primes, 0, sizeof primes);
        memset(filtered, 0, sizeof filtered);
        GetPrimes(N, primes, filtered);
        int n;
        while (true) {
            scanf("%d", &n);
            if (n == 0) {
                break;
            }
            int idx = 1;  // 从primes[1]开始遍历，因为primes[0]是偶数
            while (true) {
                auto a = primes[idx];
                auto b = n - a;
                ++idx;
                if (!filtered[b]) {
                    printf("%d = %d + %d\n", n, a, b);
                    break;
                }
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1292_H
