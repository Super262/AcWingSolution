//
// Created by Fengwei Zhang on 2021/6/16.
//

#ifndef ACWINGSOLUTION_PROBLEM0884_H
#define ACWINGSOLUTION_PROBLEM0884_H

#include <iostream>

using namespace std;

class Problem0884 {
public:
    int gaussXOR(int **matrix, const int n) {
        int column, row, nonZeroRow;
        for (column = row = 0; column < n; ++column) {

            // 1. 找到当前列非0的行
            nonZeroRow = row;
            for (int r = row; r < n; ++r) {
                if (matrix[r][column]) {
                    nonZeroRow = r;
                    break;
                }
            }

            if (!matrix[nonZeroRow][column]) {
                continue;
            }

            // 2. 移动目标行到当前行
            for (int c = column; c <= n; ++c) {
                swap(matrix[nonZeroRow][c], matrix[row][c]);
            }

            // 3. 将当前列的其它行调整为0
            for (int r = row + 1; r < n; ++r) {
                if (!matrix[r][column]) {
                    continue;
                }
                for (int c = n; c >= column; --c) {
                    matrix[r][c] ^= matrix[row][c] & matrix[r][column];
                }
            }
            ++row;
        }
        if (row < n) {
            for (int r = row; r < n; ++r) {
                if (matrix[r][n]) {
                    return 2;
                }
            }
            return 1;
        }

        // 消去X(i+1)～X(n)，求解X(i)
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                matrix[i][n] ^= matrix[i][j] & matrix[j][n];
            }
        }
        return 0;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int **matrix = new int *[n];
        int v;
        for (int i = 0; i < n; ++i) {
            matrix[i] = new int[n + 1];
            for (int j = 0; j <= n; ++j) {
                scanf("%d", &v);
                matrix[i][j] = v;
            }
        }
        int t = gaussXOR(matrix, n);
        if (t == 1) {
            puts("Multiple sets of solutions");
        } else if (t == 2) {
            puts("No solution");
        } else {
            for (int i = 0; i < n; ++i) {
                printf("%d\n", matrix[i][n]);
            }
        }
        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0884_H
