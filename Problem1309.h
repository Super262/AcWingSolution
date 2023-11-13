//
// Created by Fengwei Zhang on 1/15/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1309_H
#define ACWINGSOLUTION_PROBLEM1309_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1309 {
    // https://www.acwing.com/solution/content/24436/
private:
    const int MOD = 100003;  // 是质数，可以使用费马定理
    const int N = 2010;

    int quick_power(int a, int x) {
        int res = 1;
        while (x) {
            if (x & 1) {
                res = (int) ((long long) res * a % MOD);
            }
            a = (int) ((long long) a * a % MOD);
            x >>= 1;
        }
        return res;
    }

    void Initialize(int fact[], int in_fact[]) {
        fact[0] = 1;
        in_fact[0] = 1;
        for (int i = 1; i < N; ++i) {
            fact[i] = (int) ((long long) fact[i - 1] * i % MOD);
            in_fact[i] = (int) ((long long) in_fact[i - 1] * quick_power(i, MOD - 2) % MOD);
        }
    }

    int Combination(int n, int m, const int fact[], const int in_fact[]) {
        if (n < m) {
            return 0;
        }
        return (int) ((long long) fact[n] * in_fact[m] % MOD * in_fact[n - m] % MOD);
    }

    int Permutation(int n, int m, const int fact[], const int in_fact[]) {
        if (n < m) {
            return 0;
        }
        return (int) ((long long) fact[n] * in_fact[n - m] % MOD);
    }

    int main() {
        int fact[N];
        int in_fact[N];
        Initialize(fact, in_fact);
        int a, b, c, d, k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        int res = 0;
        for (int i = 0; i <= k; ++i) {
            res = (int) ((res + ((long long) Combination(b, i, fact, in_fact) *
                                 Permutation(a, i, fact, in_fact) % MOD *
                                 Combination(d, k - i, fact, in_fact) % MOD *
                                 Permutation(a + c - i, k - i, fact, in_fact) % MOD)) % MOD);
        }
        printf("%d\n", res);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1309_H
