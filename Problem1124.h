//
// Created by Fengwei Zhang on 10/6/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1124_H
#define ACWINGSOLUTION_PROBLEM1124_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem1124 {
    // 邻接矩阵上的欧拉回路
private:
    const int N = 501;
    int graph[N][N];
    int path[2 * N + 50];
    int ptt = 0;
    int degree[N];

    void dfs(const int u) {
        for (int i = 1; i <= N; ++i) {
            if (graph[u][i] == 0) {
                continue;
            }
            --graph[u][i];
            --graph[i][u];
            dfs(i);
        }
        path[ptt++] = u;
    }

    int main() {
        int m;
        scanf("%d", &m);
        int a, b;
        while (m--) {
            scanf("%d%d", &a, &b);
            ++graph[a][b];
            ++graph[b][a];
            ++degree[a];
            ++degree[b];
        }
        int root = 1;
        while (!degree[root]) {
            ++root;
        }
        for (int i = 1; i <= N; ++i) {
            if (degree[i] % 2) {
                root = i;
                break;
            }
        }
        dfs(root);
        for (int i = ptt - 1; i >= 0; --i) {
            printf("%d\n", path[i]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1124_H
