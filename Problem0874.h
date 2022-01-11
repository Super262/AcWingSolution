//
// Created by Fengwei Zhang on 2021/6/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0874_H
#define ACWINGSOLUTION_PROBLEM0874_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0874 {
private:
    long long EulerSum(const int &n) {
        int phi[n + 1];
        int primes[n + 1];
        bool filtered[n + 1];
        memset(phi, 0, sizeof phi);
        memset(primes, 0, sizeof primes);
        memset(filtered, 0, sizeof filtered);
        phi[1] = 1;
        int count = 0;
        for (int f = 2; f <= n; ++f) {
            if (!filtered[f]) {
                primes[count++] = f;
                phi[f] = f - 1;
            }
            for (int j = 0; primes[j] <= n / f; ++j) {
                filtered[primes[j] * f] = true;
                if (f % primes[j]) {
                    phi[f * primes[j]] = phi[f] * (primes[j] - 1);
                } else {
                    phi[f * primes[j]] = phi[f] * primes[j];
                    break;
                }
            }
        }
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += phi[i];
        }
        return sum;
    }

    int main() {
        int n;
        scanf("%d", &n);
        printf("%lld\n", EulerSum(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0874_H
