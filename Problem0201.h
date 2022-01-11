//
// Created by Fengwei Zhang on 1/11/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0201_H
#define ACWINGSOLUTION_PROBLEM0201_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0201 {
    // https://www.acwing.com/solution/content/1053/
private:
    void Euler(const int n, int phi[], int primes[], bool filtered[]) {
        phi[1] = 1;
        int p_cnt = 0;
        for (int f = 2; f <= n; ++f) {
            if (!filtered[f]) {
                primes[p_cnt++] = f;
                phi[f] = f - 1;
            }
            for (int i = 0; primes[i] <= n / f; ++i) {
                filtered[primes[i] * f] = true;
                if (f % primes[i]) {
                    phi[f * primes[i]] = phi[f] * (primes[i] - 1);
                } else {
                    phi[f * primes[i]] = phi[f] * primes[i];
                    break;
                }
            }
        }
    }

    int main() {
        const int N = 1000;
        int primes[N + 1];
        int phi[N + 1];
        bool filtered[N + 1];
        int t;
        scanf("%d", &t);
        for (int k = 1; k <= t; ++k) {
            memset(primes, 0, sizeof primes);
            memset(phi, 0, sizeof phi);
            memset(filtered, 0, sizeof filtered);
            int n;
            scanf("%d", &n);
            Euler(n, phi, primes, filtered);
            int answer = 0;
            for (int i = 2; i <= n; ++i) {
                answer += 2 * phi[i];
            }
            answer += 3;  // 不要忘记3个特殊点：(1, 0)，(1, 1)，(0, 1)
            printf("%d %d %d\n", k, n, answer);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0201_H
