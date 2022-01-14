//
// Created by Fengwei Zhang on 2021/6/14.
//

#ifndef ACWINGSOLUTION_PROBLEM0886_H
#define ACWINGSOLUTION_PROBLEM0886_H

#include <iostream>

using namespace std;

class Problem0886 {
private:
    int QuickPower(int a, int x, const int m) {
        int result = 1;
        while (x) {
            if (x & 1) {
                result = (int) ((long long) result * a % m);
            }
            x >>= 1;
            a = (int) ((long long) a * a % m);
        }
        return result;
    }

    int main() {
        const int N = 100000;
        const int M = 1e9 + 7;
        int fact[N + 1];
        int in_fact[N + 1];
        fact[0] = in_fact[0] = 1;
        for (int i = 1; i <= N; ++i) {
            fact[i] = (int) ((long long) fact[i - 1] * i % M);
            // 求解阶乘的乘法逆元
            in_fact[i] = (int) ((long long) in_fact[i - 1] * QuickPower(i, M - 2, M) % M);
        }
        int n, a, b;
        scanf("%d", &n);
        while (n--) {
            scanf("%d%d", &a, &b);
            printf("%d\n", (int) ((long long) fact[a] * in_fact[b] % M * in_fact[a - b] % M));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0886_H
