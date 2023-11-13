//
// Created by Fengwei Zhang on 1/15/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1312_H
#define ACWINGSOLUTION_PROBLEM1312_H

#include <iostream>

using namespace std;

class Problem1312 {
    // 隔板法：https://www.acwing.com/solution/content/24670/
private:
    const int MOD = 1000003;

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

    int Combination(int n, int m) {
        if (n < m) {
            return 0;
        }
        int up = 1, down = 1;
        for (int i = n, j = 1; j <= m; --i, ++j) {
            up = (int) ((long long) up * i % MOD);
            down = (int) ((long long) down * j % MOD);
        }
        return (int) ((long long) up * quick_power(down, MOD - 2) % MOD);
    }

    int Lucas(int n, int m) {
        if (n < MOD && m < MOD) {
            return Combination(n, m);
        }
        return (int) ((long long) Combination(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD) % MOD);
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n, l, r;
            scanf("%d%d%d", &n, &l, &r);
            printf("%d\n", ((Lucas(r - l + n + 1, n) - 1) % MOD + MOD) % MOD);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1312_H
