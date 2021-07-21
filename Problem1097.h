//
// Created by Fengwei Zhang on 2021/7/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1097_H
#define ACWINGSOLUTION_PROBLEM1097_H

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem1097 {
public:
    const int N = 1000;
    char graph[N + 1][N + 1];
    bool visited[N + 1][N + 1];
    pair<int, int> q[N * N + 1];

    void bfs(const int x, const int y, const int n, const int m) {
        int hh = 0, tt = -1;
        visited[x][y] = true;
        q[++tt] = pair<int, int>(x, y);
        while (hh <= tt) {
            auto root = q[hh++];
            for (int nextX = root.first - 1; nextX <= root.first + 1; ++nextX) {
                for (int nextY = root.second - 1; nextY <= root.second + 1; ++nextY) {
                    if (nextX == root.first && nextY == root.second) {
                        continue;
                    }
                    if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
                        continue;
                    }
                    if (graph[nextX][nextY] == '.' || visited[nextX][nextY]) {
                        continue;
                    }
                    q[++tt] = pair<int, int>(nextX, nextY);
                    visited[nextX][nextY] = true;
                }
            }
        }
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%s", graph[i]);  // 不使用"%c"是为了避免回车符
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j] || graph[i][j] == '.') {
                    continue;
                }
                ++result;
                bfs(i, j, n, m);
            }
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1097_H
