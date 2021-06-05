//
// Created by Fengwei Zhang on 2021/5/31.
//

#ifndef ACWINGSOLUTION_PROBLEM0798_H
#define ACWINGSOLUTION_PROBLEM0798_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0798 {
public:
    void increase(vector <vector<int>> &difference_matrix,
                  const unsigned long &x1,
                  const unsigned long &y1,
                  const unsigned long &x2,
                  const unsigned long &y2,
                  const int &value) {
        difference_matrix[x1][y1] += value;
        difference_matrix[x2 + 1][y1] -= value;
        difference_matrix[x1][y2 + 1] -= value;
        difference_matrix[x2 + 1][y2 + 1] += value;
    }

    int main() {
        unsigned long n, m, q;
        scanf("%ld%ld%ld", &n, &m, &q);

        // 行数至少为n+2，列数至少为m+2；否则，触发越界异常！
        vector <vector<int>> matrix(n + 2, vector<int>(m + 2, 0));
        int t;
        for (unsigned long i = 1; i <= n; ++i) {
            for (unsigned long j = 1; j <= m; ++j) {
                scanf("%d", &t);
                increase(matrix, i, j, i, j, t);
            }
        }
        unsigned long x1, y1, x2, y2;
        for (unsigned long i = 0; i < q; ++i) {
            scanf("%ld%ld%ld%ld%d", &x1, &y1, &x2, &y2, &t);
            increase(matrix, x1, y1, x2, y2, t);
        }
        for (unsigned long i = 1; i <= n; ++i) {
            for (unsigned long j = 1; j <= m; ++j) {
                matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
            }
        }
        for (unsigned long i = 1; i <= n; ++i) {
            for (unsigned long j = 1; j <= m; ++j) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0798_H