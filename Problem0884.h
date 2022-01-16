//
// Created by Fengwei Zhang on 2021/6/16.
//

#ifndef ACWINGSOLUTION_PROBLEM0884_H
#define ACWINGSOLUTION_PROBLEM0884_H

#include <iostream>

using namespace std;

class Problem0884 {
private:
    static const int N = 101;

    int GaussXOR(int matrix[][N], const int n, const int m) {
        int column, row, non_zero_row;
        for (column = row = 0; column < m - 1; ++column) {

            // 1. 找到当前列非0的行
            non_zero_row = row;
            for (int r = row; r < n; ++r) {
                if (matrix[r][column]) {
                    non_zero_row = r;
                    break;
                }
            }

            if (!matrix[non_zero_row][column]) {
                continue;
            }

            // 2. 移动目标行到当前行
            for (int c = column; c < m; ++c) {
                swap(matrix[non_zero_row][c], matrix[row][c]);
            }

            // 3. 将当前列的其它行调整为0
            for (int r = row + 1; r < n; ++r) {
                if (!matrix[r][column]) {
                    continue;
                }
                for (int c = m - 1; c >= column; --c) {
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
            for (int j = i + 1; j < m - 1; ++j) {
                matrix[i][m - 1] ^= matrix[i][j] & matrix[j][m - 1];
            }
        }
        return 0;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int matrix[n][N];
        auto m = n + 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int v;
                scanf("%d", &v);
                matrix[i][j] = v;
            }
        }
        auto t = GaussXOR(matrix, n, m);
        if (t == 1) {
            puts("Multiple sets of solutions");
        } else if (t == 2) {
            puts("No solution");
        } else {
            for (int i = 0; i < n; ++i) {
                printf("%d\n", matrix[i][m - 1]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0884_H
