//
// Created by Fengwei Zhang on 2021/5/31.
//

#ifndef ACWINGSOLUTION_PROBLEM0796_H
#define ACWINGSOLUTION_PROBLEM0796_H

#include <vector>
#include <iostream>

using namespace std;


class Problem0796 {
public:
    vector<vector<int>> getPrefixSum(const vector<vector<int>> &matrix) {
        vector<vector<int>> result(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (unsigned long i = 1; i < result.size(); ++i) {
            for (unsigned long j = 1; j < result[0].size(); ++j) {
                result[i][j] = result[i - 1][j] + result[i][j - 1] - result[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        return result;
    }

    int main() {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (unsigned long i = 0; i < n; ++i) {
            for (unsigned long j = 0; j < m; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }
        vector<vector<int>> prefixSum = getPrefixSum(matrix);
        int x1, y1, x2, y2;
        for (int i = 0; i < q; ++i) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            printf("%d\n",
                   prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0796_H
