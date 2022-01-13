//
// Created by Fengwei Zhang on 1/12/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1303_H
#define ACWINGSOLUTION_PROBLEM1303_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1303 {
    // https://www.acwing.com/solution/content/25805/
private:
    static const int N = 3;

    void Multiply(int res[N], const int a[N], int b[][N], const int m) {
        int temp[N] = {0};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                temp[i] = (int) ((temp[i] + (long long) a[j] * b[j][i]) % m);
            }
        }
        memcpy(res, temp, sizeof temp);
    }

    void Multiply(int res[][N], int a[][N], int b[][N], const int m) {
        int temp[N][N] = {0};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    temp[i][j] = (int) ((temp[i][j] + (long long) a[i][k] * b[k][j]) % m);
                }
            }
        }
        memcpy(res, temp, sizeof temp);
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int f1[N] = {1, 1, 1};
        int a[N][N] = {{0, 1, 0},
                       {1, 1, 1},
                       {0, 0, 1}};
        --n;
        while (n) {
            if (n & 1) {
                Multiply(f1, f1, a, m);
            }
            Multiply(a, a, a, m);
            n >>= 1;
        }
        printf("%d\n", f1[N - 1]);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1303_H
