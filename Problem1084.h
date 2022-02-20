//
// Created by Fengwei Zhang on 2021/7/19.
//

#ifndef ACWINGSOLUTION_PROBLEM1084_H
#define ACWINGSOLUTION_PROBLEM1084_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem1084 {
private:
    static const int N = 12, M = 10, P = 100;
    int f[N][M][P];  // f[i][j][k]：i位数、最高位为j，模P为k的所有数的个数
    int p;

    int mod(const int x, const int m) {
        return (x % m + m) % m;
    }

    void init() {
        memset(f, 0, sizeof f);
        for (int i = 0; i < M; ++i) {
            ++f[1][i][mod(i, p)];
        }
        for (int length = 2; length < N; ++length) {
            for (int i = 0; i < M; ++i) {
                for (int k = 0; k < p; ++k) {
                    for (int j = 0; j < M; ++j) {
                        f[length][i][k] += f[length - 1][j][mod(k - i, p)];
                    }
                }
            }
        }
    }

    int dp(int a) {
        if (!a) {
            return 1;
        }
        int digits[N];
        int n = 0;
        while (a) {
            digits[n] = a % M;
            a /= M;
            ++n;
        }
        int result = 0;
        int prefix = 0;
        for (int i = n - 1; i >= 0; --i) {
            int x = digits[i];
            for (int j = 0; j < x; ++j) {
                result += f[i + 1][j][mod(-prefix, p)];
            }
            prefix += x;
            if (!i && !(prefix % p)) {
                ++result;
            }
        }
        return result;
    }

    int main() {
        int a, b;
        while (scanf("%d%d%d", &a, &b, &p) != -1) {
            init();
            printf("%d\n", dp(b) - dp(a - 1));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1084_H
