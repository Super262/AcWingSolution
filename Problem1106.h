//
// Created by Fengwei Zhang on 2021/7/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1106_H
#define ACWINGSOLUTION_PROBLEM1106_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem1106 {
private:
    const int N = 1000;
    bool visited[N][N];
    int graph[N][N];
    pair<int, int> q[N * N + 1];

    void bfs(const int x, const int y, const int n, bool &hasHigher, bool &hasLower) {
        int hh = 0, tt = -1;
        q[++tt] = pair<int, int>(x, y);
        visited[x][y] = true;
        while (hh <= tt) {
            auto root = q[hh++];
            auto rootH = graph[root.first][root.second];
            for (int i = root.first - 1; i <= root.first + 1; ++i) {
                for (int j = root.second - 1; j <= root.second + 1; ++j) {
                    if (i < 0 || i >= n || j < 0 || j >= n) {
                        continue;
                    }
                    if (i == root.first && j == root.second) {
                        continue;
                    }
                    if (graph[i][j] > rootH) {
                        hasHigher = true;
                    } else if (graph[i][j] < rootH) {
                        hasLower = true;
                    } else {
                        if (!visited[i][j]) {
                            q[++tt] = pair<int, int>(i, j);
                            visited[i][j] = true;
                        }
                    }
                }
            }
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &graph[i][j]);
            }
        }
        int valley = 0;
        int peak = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) {
                    continue;
                }
                bool hasHigher = false;
                bool hasLower = false;
                bfs(i, j, n, hasHigher, hasLower);
                if (!hasLower) {
                    ++valley;
                }
                if (!hasHigher) {
                    ++peak;
                }
            }
        }
        printf("%d %d\n", peak, valley);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1106_H
