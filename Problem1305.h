//
// Created by Fengwei Zhang on 1/13/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1305_H
#define ACWINGSOLUTION_PROBLEM1305_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1305 {
    // https://www.acwing.com/solution/content/46059/
private:
    static const int M = 21;

    void Kmp(const char s[], const int m, int next_start[]) {
        next_start[0] = 0;
        int left = 0;
        int right = 1;
        while (right < m) {
            if (s[left] == s[right]) {
                ++left;
                next_start[right] = left;
                ++right;
            } else if (left) {
                left = next_start[left - 1];
            } else {
                next_start[right] = 0;
                ++right;
            }
        }
    }

    void Multiply(int res[][M], int a[][M], int b[][M], int m, int mod) {
        static int temp[M][M];
        memset(temp, 0, sizeof temp);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < m; ++k) {
                    temp[i][j] = (int) ((temp[i][j] + (long long) a[i][k] * b[k][j]) % mod);
                }
            }
        }
        memcpy(res, temp, sizeof temp);
    }

    void quick_power(int f[][M], int a[][M], int m, int p, int mod) {
        while (p) {
            if (p & 1) {
                Multiply(f, f, a, m, mod);
            }
            Multiply(a, a, a, m, mod);
            p >>= 1;
        }
    }

    int main() {
        int n, m, mod;
        scanf("%d%d%d", &n, &m, &mod);
        char str[m + 1];
        scanf("%s", str);
        int next_start[m + 1];
        Kmp(str, m, next_start);
        int a[M][M];
        memset(a, 0, sizeof a);
        for (int i = 0; i < m; ++i) {
            for (char ch = '0'; ch <= '9'; ++ch) {
                auto k = i;
                while (k && str[k] != ch) {
                    k = next_start[k - 1];
                }
                if (str[k] == ch) {
                    ++k;
                }
                if (k < m) {
                    ++a[i][k];
                }
            }
        }
        int f0[M][M] = {1};
        quick_power(f0, a, m, n, mod);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            res = (int) (((long long) res + f0[0][i]) % mod);
        }
        printf("%d\n", res);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1305_H
