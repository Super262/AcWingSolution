//
// Created by Fengwei Zhang on 1/16/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0208_H
#define ACWINGSOLUTION_PROBLEM0208_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0208 {
    // https://www.acwing.com/solution/content/1087/
private:
    static const int N = 35;

    int Gauss(int a[][N], const int n, const int m) {
        int row, column;
        for (row = 1, column = 1; column <= m - 1; ++column) {
            auto max_row = row;
            for (auto i = row; i <= n; ++i) {
                if (a[i][column]) {
                    max_row = i;
                    break;
                }
            }
            if (!a[max_row][column]) {
                continue;
            }
            for (auto i = column; i <= m; ++i) {
                swap(a[row][i], a[max_row][i]);
            }
            for (auto i = row + 1; i <= n; ++i) {
                for (auto j = m; j >= column; --j) {
                    a[i][j] ^= a[i][column] & a[row][j];
                }
            }
            ++row;
        }
        if (row <= n) {
            int res = 1;
            for (auto i = row; i <= n; ++i) {
                if (a[i][m]) {
                    return 0;
                }
                res *= 2;
            }
            return res;
        }
        for (auto i = n - 1; i >= 1; --i) {
            for (auto j = i + 1; j <= m; ++j) {
                a[i][m] ^= a[i][j] & a[j][m];
            }
        }
        return 1;
    }

    int main() {
        int a[N][N];
        int k;
        scanf("%d", &k);
        while (k--) {
            memset(a, 0, sizeof a);
            int n;
            scanf("%d", &n);
            auto m = n + 1;
            for (int i = 1; i <= n; ++i) {
                scanf("%d", &a[i][m]);
            }
            for (int i = 1; i <= n; ++i) {
                int t;
                scanf("%d", &t);
                a[i][m] ^= t;
                a[i][i] = 1;
            }
            int x, y;
            while (true) {
                scanf("%d%d", &x, &y);
                if (x == 0 && y == 0) {
                    break;
                }
                a[y][x] = 1;
            }
            auto t = Gauss(a, n, m);
            if (t == 0) {
                puts("Oh,it's impossible~!!");
            } else {
                printf("%d\n", t);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0208_H
