//
// Created by Fengwei Zhang on 1/11/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0220_H
#define ACWINGSOLUTION_PROBLEM0220_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem220 {
    // https://www.acwing.com/solution/content/12261/
private:
    int Euler(const int n, int primes[], bool filtered[], int phi[]) {
        int p_cnt = 0;
        phi[1] = 1;
        for (int f = 2; f <= n; ++f) {
            if (!filtered[f]) {
                primes[p_cnt++] = f;
                phi[f] = f - 1;
            }
            for (int i = 0; primes[i] <= n / f && i < p_cnt; ++i) {
                filtered[f * primes[i]] = true;
                if (f % primes[i]) {
                    phi[primes[i] * f] = phi[f] * (primes[i] - 1);
                } else {
                    phi[primes[i] * f] = phi[f] * primes[i];
                    break;
                }
            }
        }
        return p_cnt;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int primes[n + 1];
        int phi[n + 1];
        bool filtered[n + 1];
        long long prefix[n + 1];
        memset(primes, 0, sizeof primes);
        memset(phi, 0, sizeof phi);
        memset(filtered, 0, sizeof filtered);
        memset(prefix, 0, sizeof prefix);
        auto p_cnt = Euler(n, primes, filtered, phi);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + phi[i];
        }
        long long res = 0;
        for (int i = 0; i < p_cnt; ++i) {
            // 1.质数p>=2，所以应计算prefix[f] - prefix[1]
            // 2.不要忘记x==y可能成立，所以在最后加1
            res += 2 * (prefix[n / primes[i]] - prefix[1]) + 1;
        }
        printf("%lld\n", res);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0220_H
