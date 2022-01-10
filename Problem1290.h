//
// Created by Fengwei Zhang on 1/10/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1290_H
#define ACWINGSOLUTION_PROBLEM1290_H

#include <iostream>

using namespace std;

class Problem1290 {
    // 容斥原理求状态表示；快速幂计算状态数
private:
    int qpow(int a, long long k, const int m) {
        int res = 1;
        while (k) {
            if (k & 1) {
                res = (int) ((long long) res * a % m);
            }
            a = (int) ((long long) a * a % m);
            k >>= 1;
        }
        return res;
    }

    int main() {
        const int MOD = 100003;
        int m;
        long long n;
        scanf("%d%lld", &m, &n);
        // 注意，qpow(m, n, MOD) - qpow(m - 1, n - 1, MOD)可能为负数！
        printf("%lld\n", (qpow(m, n, MOD) - (long long) m * qpow(m - 1, n - 1, MOD) % MOD + MOD) % MOD);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1290_H
