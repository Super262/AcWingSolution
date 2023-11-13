//
// Created by Fengwei Zhang on 1/16/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1316_H
#define ACWINGSOLUTION_PROBLEM1316_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1316 {
    // https://www.acwing.com/solution/content/26267/
private:
    int GetPrimes(int n, int primes[], bool filtered[]) {
        int cnt = 0;
        for (int f = 2; f <= n; ++f) {
            if (!filtered[f]) {
                primes[cnt++] = f;
            }
            for (int i = 0; i < cnt && primes[i] <= n / f; ++i) {
                filtered[f * primes[i]] = true;
                if (f % primes[i] == 0) {
                    break;
                }
            }
        }
        return cnt;
    }

    int quick_power(int a, int x, int m) {
        int res = 1;
        while (x) {
            if (x & 1) {
                res = (int) ((long long) res * a % m);
            }
            a = (int) ((long long) a * a % m);
            x >>= 1;
        }
        return res;
    }

    int GetPower(int n, int p) {
        int s = 0;
        while (n) {
            s += n / p;
            n /= p;
        }
        return s;
    }

    int Combination(int a, int b, const int primes[], int p_cnt, int m) {
        if (b > a) {
            return 0;
        }
        int res = 1;
        for (int i = 0; i < p_cnt; ++i) {
            auto p = primes[i];
            auto s = GetPower(a, p) - GetPower(a - b, p) - GetPower(b, p);
            res = (int) ((long long) res * quick_power(p, s, m) % m);
        }
        return res;
    }

    int main() {
        int n, p;
        scanf("%d%d", &n, &p);
        int primes[2 * n + 1];
        bool filtered[2 * n + 1];
        memset(filtered, 0, sizeof filtered);
        auto p_cnt = GetPrimes(n * 2, primes, filtered);
        printf("%d\n", (Combination(2 * n, n, primes, p_cnt, p) - Combination(2 * n, n - 1, primes, p_cnt, p) + p) % p);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1316_H
