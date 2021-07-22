//
// Created by Fengwei Zhang on 2021/7/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0173_H
#define ACWINGSOLUTION_PROBLEM0173_H

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Problem0173 {
    // https://www.acwing.com/solution/content/18754/
public:
    const int N = 1000;
    pair<int, int> q[N * N + 1];
    int dist[N][N];
    char graph[N][N];

    void bfs(const int n, const int m) {
        int dx[] = {0, 1, -1, 0};
        int dy[] = {1, 0, 0, -1};
        int hh = 0, tt = -1;
        memset(dist, -1, sizeof dist);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (graph[i][j] == '0') {
                    continue;
                }
                dist[i][j] = 0;
                q[++tt] = pair<int, int>(i, j);
            }
        }
        while (hh <= tt) {
            auto root = q[hh++];
            for (int i = 0; i < 4; ++i) {
                int nextX = root.first + dx[i];
                int nextY = root.second + dy[i];
                if (nextX >= n || nextX < 0 || nextY >= m || nextY < 0) {
                    continue;
                }
                if (dist[nextX][nextY] != -1) {
                    continue;
                }
                dist[nextX][nextY] = dist[root.first][root.second] + 1;
                q[++tt] = pair<int, int>(nextX, nextY);
            }
        }
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%s", graph[i]);
        }
        bfs(n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d ", dist[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0173_H
