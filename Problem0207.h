//
// Created by Fengwei Zhang on 1/16/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0207_H
#define ACWINGSOLUTION_PROBLEM0207_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0207 {
    // https://www.acwing.com/solution/content/48342/
private:
    static const int N = 15;

    int Gauss(double a[][N], int n, int m) {
        const double zero_value = 1e-6;
        int row, column;
        for (row = 1, column = 1; column <= m - 1; ++column) {
            auto max_row = row;
            for (auto i = row; i <= n; ++i) {
                if (abs(a[i][column]) > abs(a[max_row][column])) {
                    max_row = i;
                }
            }
            if (abs(a[max_row][column]) <= zero_value) {
                continue;
            }
            for (auto i = column; i <= m; ++i) {
                swap(a[max_row][i], a[row][i]);
            }
            for (auto i = m; i >= column; --i) {
                a[row][i] /= a[row][column];
            }
            for (auto i = row + 1; i <= n; ++i) {
                for (int j = m; j >= column; --j) {
                    a[i][j] -= a[i][column] * a[row][j];
                }
            }
            ++row;
        }
        if (row <= n) {
            for (auto i = row; i <= n; ++i) {
                if (a[i][m] > zero_value) {
                    return 2;
                }
            }
            return 1;
        }
        for (auto i = n - 1; i >= 1; --i) {
            for (auto j = i + 1; j <= m - 1; ++j) {
                a[i][m] -= a[i][j] * a[j][m];
            }
        }
        for (auto i = n; i >= 1; --i) {
            if (a[i][m] <= zero_value) {
                a[i][m] = 0;
            }
        }
        return 0;
    }

    int main() {
        int n;
        scanf("%d", &n);
        double a[n + 1][N];
        double b[n + 1][N];
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%lf", &a[i][j]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                b[i][j] = 2 * (a[i][j] - a[0][j]);
                b[i][n + 1] += a[i][j] * a[i][j] - a[0][j] * a[0][j];
            }
        }
        Gauss(b, n, n + 1);
        for (int i = 1; i <= n; ++i) {
            printf("%.3lf ", b[i][n + 1]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0207_H
