//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0843_H
#define ACWINGSOLUTION_PROBLEM0843_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0843 {
public:
    void dfs(const int column,
             const int n,
             vector<vector<char>> &graph,
             vector<bool> &rowUsed,
             vector<bool> &diagonal1Used,
             vector<bool> &diagonal2Used) {
        if (column > n) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    printf("%c", graph[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            return;
        }
        for (int row = 1; row <= n; ++row) {
            if (rowUsed[row] || diagonal1Used[column - row + n] || diagonal2Used[column + row] ||
                graph[row][column] == 'Q') {
                continue;
            }
            rowUsed[row] = true;
            diagonal1Used[column - row + n] = true;
            diagonal2Used[column + row] = true;
            graph[row][column] = 'Q';
            dfs(column + 1, n, graph, rowUsed, diagonal1Used, diagonal2Used);
            rowUsed[row] = false;
            diagonal1Used[column - row + n] = false;
            diagonal2Used[column + row] = false;
            graph[row][column] = '.';
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<vector<char>> graph(n + 1, vector<char>(n + 1, '.'));
        vector<bool> rowUsed(n + 1, false);
        vector<bool> diagonal1Used(2 * n + 1, false);
        vector<bool> diagonal2Used(2 * n + 1, false);
        dfs(1, n, graph, rowUsed, diagonal1Used, diagonal2Used);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0843_H
