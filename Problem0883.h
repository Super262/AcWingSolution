//
// Created by Fengwei Zhang on 2021/6/13.
//

#ifndef ACWINGSOLUTION_PROBLEM0883_H
#define ACWINGSOLUTION_PROBLEM0883_H

#include <iostream>
#include <cmath>

using namespace std;

class Problem0883 {
public:
    int gauss(double **matrix, const int n) {
        const double minDouble = 1e-6;
        int column, row;
        for (column = 0, row = 0; column < n; ++column) {

            // 1. 寻找当前列的最大值
            int maximalRow = row;
            for (int i = row; i < n; ++i) {
                if (abs(matrix[i][column]) > abs(matrix[maximalRow][column])) {
                    maximalRow = i;
                }
            }

            if (abs(matrix[maximalRow][column]) <= minDouble) {
                continue;
            }

            // 2. 将最大值所在的行调整到当前行
            for (int i = column; i <= n; ++i) {
                swap(matrix[maximalRow][i], matrix[row][i]);
            }

            // 3. 设置当前行的首元素为"1"（从后向前，保证操作的正确性，避免基准值——首元素被提前更改）
            for (int i = n; i >= column; --i) {
                matrix[row][i] /= matrix[row][column];
            }

            // 4. 将下面所有行（row+1开始）的当前列（column）设置为0
            for (int i = row + 1; i < n; ++i) {
                if (abs(matrix[i][column]) <= minDouble) {
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
                if (abs(matrix[i][n]) > minDouble) {
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
        return 0;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto **matrix = new double *[n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new double[n + 1];
            for (int j = 0; j <= n; ++j) {
                scanf("%lf", &matrix[i][j]);
            }
        }
        int t = gauss(matrix, n);
        if (t == 1) {
            puts("Infinite group solutions");
        } else if (t == 2) {
            puts("No solution");
        } else {
            for (int i = 0; i < n; ++i) {
                printf("%.2lf\n", matrix[i][n]);
            }
        }
        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0883_H
