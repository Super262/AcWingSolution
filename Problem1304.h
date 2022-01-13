//
// Created by Fengwei Zhang on 1/13/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1304_H
#define ACWINGSOLUTION_PROBLEM1304_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1304 {
    // https://www.acwing.com/solution/content/25810/
private:
    static const int N = 4;

    void Multiply(int res[][N], int a[][N], int b[][N], const int m) {
        static int temp[N][N];
        memset(temp, 0, sizeof temp);
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
        int f1[N][N] = {{1, 1, 1, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}};  // 为计算方便，将f1扩展为N*N矩阵
        int a[N][N] = {{0, 1, 0, 0},
                       {1, 1, 1, 0},
                       {0, 0, 1, 1},
                       {0, 0, 0, 1}};
        auto k = n - 1;
        while (k) {
            if (k & 1) {
                Multiply(f1, f1, a, m);
            }
            k >>= 1;
            Multiply(a, a, a, m);
        }
        auto res = (int) ((((long long) n * f1[0][2] - f1[0][3]) % m + m) % m);
        printf("%d\n", res);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1304_H
