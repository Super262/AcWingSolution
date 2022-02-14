//
// Created by Fengwei Zhang on 2021/7/19.
//

#ifndef ACWINGSOLUTION_PROBLEM1084_H
#define ACWINGSOLUTION_PROBLEM1084_H

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Problem1084 {
private:
    static const int N = 11;
    int f[N + 1][10][100];
    int P;

    int mod(const int x, const int m) {
        return (x % m + m) % m;
    }

    void init() {
        memset(f, 0, sizeof f);
        for (int i = 0; i <= 9; ++i) {
            ++f[1][i][mod(i, P)];
        }
        for (int length = 2; length <= N; ++length) {
            for (int i = 0; i <= 9; ++i) {
                for (int k = 0; k < P; ++k) {
                    for (int j = 0; j <= 9; ++j) {
                        f[length][i][k] += f[length - 1][j][mod(k - i, P)];
                    }
                }
            }
        }
    }

    int dp(int a) {
        if (a == 0) {
            return 1;
        }
        vector<int> digits;
        while (a) {
            digits.emplace_back(a % 10);
            a /= 10;
        }
        int result = 0;
        int prefix = 0;
        for (int i = (int) digits.size() - 1; i >= 0; --i) {
            int x = digits[i];
            for (int j = 0; j < x; ++j) {
                result += f[i + 1][j][mod(-prefix, P)];
            }
            prefix += x;
            if (i == 0 && prefix % P == 0) {
                ++result;
            }
        }
        return result;
    }

    int main() {
        int a, b;
        while (scanf("%d%d%d", &a, &b, &P) != -1) {
            init();
            printf("%d\n", dp(b) - dp(a - 1));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1084_H
