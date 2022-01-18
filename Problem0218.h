//
// Created by Fengwei Zhang on 1/17/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0218_H
#define ACWINGSOLUTION_PROBLEM0218_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Problem0218 {
    // https://www.acwing.com/solution/content/26204/
private:
    static const int N = 14, K = 5;
    const int INF = 0x3f3f3f3f;
    const double zero_value = 1e-6;

    double GetExpectation(int a, int b, int c, int d, int x, int y, int ta, int tb, int tc, int td,
                          double f[N][N][N][N][K][K]) {
        auto &val = f[a][b][c][d][x][y];
        if (val >= zero_value) {
            return val;
        }
        auto as = a + (x == 0) + (y == 0);
        auto bs = b + (x == 1) + (y == 1);
        auto cs = c + (x == 2) + (y == 2);
        auto ds = d + (x == 3) + (y == 3);
        if (as >= ta && bs >= tb && cs >= tc && ds >= td) {
            val = 0;
            return val;
        }
        auto remains = 4 * (N - 1) + 2 - (a + b + c + d + (x != 4) + (y != 4));
        if (remains <= 0) {
            val = INF;
            return val;
        }
        val = 1;  // 不要忘记赋初值1
        if (a < N - 1) {
            val += ((double) N - 1 - a) / remains * GetExpectation(a + 1, b, c, d, x, y, ta, tb, tc, td, f);
        }
        if (b < N - 1) {
            val += ((double) N - 1 - b) / remains * GetExpectation(a, b + 1, c, d, x, y, ta, tb, tc, td, f);
        }
        if (c < N - 1) {
            val += ((double) N - 1 - c) / remains * GetExpectation(a, b, c + 1, d, x, y, ta, tb, tc, td, f);
        }
        if (d < N - 1) {
            val += ((double) N - 1 - d) / remains * GetExpectation(a, b, c, d + 1, x, y, ta, tb, tc, td, f);
        }
        if (x == 4) {
            double t = INF;
            for (int i = 0; i < K - 1; ++i) {
                t = min(t, 1.0 / remains * GetExpectation(a, b, c, d, i, y, ta, tb, tc, td, f));
            }
            val += t;
        }
        if (y == 4) {
            double t = INF;
            for (int i = 0; i < K - 1; ++i) {
                t = min(t, 1.0 / remains * GetExpectation(a, b, c, d, x, i, ta, tb, tc, td, f));
            }
            val += t;
        }
        return val;
    }

    int main() {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        double f[N][N][N][N][K][K];
        memset(f, -1, sizeof f);
        auto res = GetExpectation(0, 0, 0, 0, 4, 4, a, b, c, d, f);
        if (res > INF / 2.0) {
            printf("%.3lf\n", -1.0);
        } else {
            printf("%.3lf\n", res);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0218_H
