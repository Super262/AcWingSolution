//
// Created by Fengwei Zhang on 2021/6/15.
//

#ifndef ACWINGSOLUTION_PROBLEM0889_H
#define ACWINGSOLUTION_PROBLEM0889_H

#include <iostream>

using namespace std;

class Problem0889 {
private:
    int QuickPower(int a, int x, const int mod) {
        int result = 1;
        while (x) {
            if (x & 1) {
                result = (int) ((long long) result * a % mod);
            }
            a = (int) ((long long) a * a % mod);
            x >>= 1;
        }
        return result;
    }

    int Catalan(const int n) {
        // 1 / (n + 1) * C(2 * n, n) = (2 * n)! / (n! * n!) == ((n + 1) * ... * (2 * n)) / n!
        const int mod = 1e9 + 7;
        int result = 1;
        for (auto i = n + 1; i <= 2 * n; ++i) {
            result = (int) ((long long) result * i % mod);
        }
        for (int i = 1; i <= n; ++i) {
            result = (int) ((long long) result * QuickPower(i, mod - 2, mod) % mod);
        }
        result = (int) ((long long) result * QuickPower(n + 1, mod - 2, mod) % mod);
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        printf("%d", Catalan(n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0889_H
