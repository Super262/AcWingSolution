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
    void dfs(const int n,
             const int y,
             vector<vector<char>> &graph,
             vector<bool> &rowUsed,
             vector<bool> &columnUsed,
             vector<bool> &diagonal1,
             vector<bool> &diagonal2) {
        if (y > n) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    printf("%c", graph[i][j]);
                }
                puts("");
            }
            puts("");
            return;
        }
        for (int x = 1; x <= n; ++x) {
            if (rowUsed[x] || columnUsed[y] || diagonal1[x - y + n] || diagonal2[y + x] || graph[x][y] == 'Q') {
                continue;
            }
            graph[x][y] = 'Q';
            rowUsed[x] = true;
            columnUsed[y] = true;
            diagonal1[x - y + n] = true;
            diagonal2[y + x] = true;
            dfs(n, y + 1, graph, rowUsed, columnUsed, diagonal1, diagonal2);
            graph[x][y] = '.';
            rowUsed[x] = false;
            columnUsed[y] = false;
            diagonal1[x - y + n] = false;
            diagonal2[y + x] = false;
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<vector<char>> graph(n + 1, vector<char>(n + 1, '.'));
        vector<bool> rowUsed(n + 1, false);
        vector<bool> columnUsed(n + 1, false);
        vector<bool> diagonal1(2 * n + 1, false);
        vector<bool> diagonal2(2 * n + 1, false);
        dfs(n, 1, graph, rowUsed, columnUsed, diagonal1, diagonal2);
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0843_H
