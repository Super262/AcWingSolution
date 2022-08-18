//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0843_H
#define ACWINGSOLUTION_PROBLEM0843_H

#include <iostream>

using namespace std;

class Problem0843 {
    // 以截距为对角线编号
private:
    static const int N = 9;
    char graph[N][N];
    bool colUsed[N];
    bool dgUsed[2 * N];
    bool udgUsed[2 * N];

    void dfs(const int r, const int n) {
        if (r >= n) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    printf("%c", graph[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (colUsed[c] || dgUsed[c + r] || udgUsed[n - r + c] || graph[r][c] == 'Q') {
                continue;
            }
            colUsed[c] = true;
            dgUsed[c + r] = true;
            udgUsed[n - r + c] = true;
            graph[r][c] = 'Q';
            dfs(r + 1, n);
            colUsed[c] = false;
            dgUsed[c + r] = false;
            udgUsed[n - r + c] = false;
            graph[r][c] = '.';
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = '.';
            }
        }
        dfs(0, n);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0843_H
