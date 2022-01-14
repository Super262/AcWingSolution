//
// Created by Fengwei Zhang on 2021/6/13.
//

#ifndef ACWINGSOLUTION_PROBLEM0883_H
#define ACWINGSOLUTION_PROBLEM0883_H

#include <iostream>
#include <cmath>

using namespace std;

class Problem0883 {
private:
    static const int N = 101;

    int Gauss(double matrix[][N], const int n) {
        const double min_value = 1e-6;
        int column, row;
        for (column = 0, row = 0; column < n; ++column) {
            // 1. 寻找当前列的最大值
            int max_row = row;
            for (int i = row; i < n; ++i) {
                if (abs(matrix[i][column]) > abs(matrix[max_row][column])) {
                    max_row = i;
                }
            }
            if (abs(matrix[max_row][column]) <= min_value) {
                continue;
            }

            // 2. 将最大值所在的行调整到当前行
            for (int i = column; i <= n; ++i) {
                swap(matrix[max_row][i], matrix[row][i]);
            }

            // 3. 设置当前行的首元素为"1"（从后向前，保证操作的正确性，避免基准值——首元素被提前更改）
            for (int i = n; i >= column; --i) {
                matrix[row][i] /= matrix[row][column];
            }

            // 4. 将下面所有行（row+1开始）的当前列（column）设置为0
            for (int i = row + 1; i < n; ++i) {
                if (abs(matrix[i][column]) <= min_value) {
                    continue;
                }

                // 从尾向头操作
                for (int j = n; j >= column; --j) {
                    matrix[i][j] -= matrix[row][j] * matrix[i][column];
                }
            }
            ++row;
        }
        if (row < n) {
            for (int i = row; i < n; ++i) {
                if (abs(matrix[i][n]) > min_value) {
                    return 2;  // 方程组无解
                }
            }
            return 1;   // 方程组有无穷多组解
        }

        // 消元，求解X1～Xn
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                matrix[i][n] -= matrix[i][j] * matrix[j][n];
            }
        }

        // 去掉输出 -0.00 的情况
        for (int i = 0; i < n; ++i) {
            if (abs(matrix[i][n]) < min_value) {
                matrix[i][n] = 0;
            }
        }

        return 0;
    }

    int main() {
        int n;
        scanf("%d", &n);
        double matrix[n][N];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                scanf("%lf", &matrix[i][j]);
            }
        }
        int t = Gauss(matrix, n);
        if (t == 1) {
            puts("Infinite group solutions");
        } else if (t == 2) {
            puts("No solution");
        } else {
            for (int i = 0; i < n; ++i) {
                printf("%.2lf\n", matrix[i][n]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0883_H
