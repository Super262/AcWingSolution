//
// Created by Fengwei Zhang on 2021/7/20.
//

#ifndef ACWINGSOLUTION_PROBLEM1091_H
#define ACWINGSOLUTION_PROBLEM1091_H

#include <iostream>

using namespace std;

class Problem1091 {
    // https://www.acwing.com/solution/content/12800/
private:
    static const int N = 1010;
    int q[N];
    int matrix[N][N];

    void getMaxInRow(const int row[], int maxs[], const int n, const int k) {
        // maxs[i]是以row[i]结尾的窗口中的最大值
        int hh = 0, tt = -1;
        for (int i = 1; i <= n; ++i) {
            while (hh <= tt && i - q[hh] + 1 > k) {
                ++hh;
            }
            while (hh <= tt && row[i] >= row[q[tt]]) {
                --tt;
            }
            q[++tt] = i;
            maxs[i] = row[q[hh]];
        }
    }

    void getMinInRow(const int row[], int mins[], const int n, const int k) {
        // mins[i]是以row[i]结尾的窗口中的最小值
        int hh = 0, tt = -1;
        for (int i = 1; i <= n; ++i) {
            while (hh <= tt && i - q[hh] + 1 > k) {
                ++hh;
            }
            while (hh <= tt && row[i] <= row[q[tt]]) {
                --tt;
            }
            q[++tt] = i;
            mins[i] = row[q[hh]];
        }
    }

    int minSquare(const int a, const int b, const int k) {
        int row_win_maxs[a + 1][b + 1];
        int row_win_mins[a + 1][b + 1];
        for (int i = 1; i <= a; ++i) {
            getMaxInRow(matrix[i], row_win_maxs[i], b, k);
            getMinInRow(matrix[i], row_win_mins[i], b, k);
        }
        int col_win_maxs[a + 1];
        int col_win_mins[a + 1];
        int temp[a + 1];
        int result = 0x7f7f7f7f;
        for (int j = k; j <= b; ++j) {
            for (int i = 1; i <= a; ++i) {
                temp[i] = row_win_maxs[i][j];
            }
            getMaxInRow(temp, col_win_maxs, a, k);
            for (int i = 1; i <= a; ++i) {
                temp[i] = row_win_mins[i][j];
            }
            getMinInRow(temp, col_win_mins, a, k);
            for (int i = k; i <= a; ++i) {
                result = min(result, col_win_maxs[i] - col_win_mins[i]);
            }
        }
        return result;
    }

    int main() {
        int a, b, n;
        scanf("%d%d%d", &a, &b, &n);
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }
        printf("%d\n", minSquare(a, b, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1091_H
