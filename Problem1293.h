//
// Created by Fengwei Zhang on 1/8/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1293_H
#define ACWINGSOLUTION_PROBLEM1293_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1293 {
private:
    void GetPrimes(const int n, int primes[], bool filtered[]) {
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
    }

    int main() {
        int n;
        scanf("%d", &n);
        int primes[n + 2];
        bool filtered[n + 2];
        memset(primes, 0, sizeof primes);
        memset(filtered, 0, sizeof filtered);
        GetPrimes(n + 1, primes, filtered);  // 相当于将1～n映射到2～n+1
        if (n <= 2) {
            printf("%d\n", 1);
        } else {
            printf("%d\n", 2);
        }
        for (int i = 2; i <= n + 1; ++i) {
            if (filtered[i]) {
                printf("%d ", 2);
            } else {
                printf("%d ", 1);
            }
        }
        printf("\n");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1293_H
