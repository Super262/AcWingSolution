//
// Created by Fengwei Zhang on 2021/7/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0188_H
#define ACWINGSOLUTION_PROBLEM0188_H

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Problem0188 {
    // https://www.acwing.com/solution/content/6027/
public:
    const int N = 150;
    char graph[N][N];
    int dist[N][N];
    pair<int, int> q[N * N + 1];

    int bfs(const int startX, const int startY, const int endX, const int endY, const int R, const int C) {
        if (startX == endX && startY == endY) {
            return 0;
        }
        int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
        int dy[] = {-2, -2, 2, 2, -1, -1, 1, 1};
        int hh = 0, tt = -1;
        memset(dist, -1, sizeof dist);
        dist[startX][startY] = 0;
        q[++tt] = pair<int, int>(startX, startY);
        while (hh <= tt) {
            auto root = q[hh++];
            for (int i = 0; i < 8; ++i) {
                int nextX = root.first + dx[i];
                int nextY = root.second + dy[i];

                // 不可达
                if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C || graph[nextX][nextY] == '*') {
                    continue;
                }
                // 可达但重复访问
                if (dist[nextX][nextY] != -1) {
                    continue;
                }

                dist[nextX][nextY] = dist[root.first][root.second] + 1;
                if (nextX == endX && nextY == endY) {
                    return dist[endX][endY];
                }
                q[++tt] = pair<int, int>(nextX, nextY);
            }
        }
        return -1;
    }

    int main() {
        int r, c;
        scanf("%d%d", &c, &r);
        int startX = -1, startY = -1, endX = -1, endY = -1;
        for (int i = 0; i < r; ++i) {
            scanf("%s", graph[i]);
            for (int j = 0; j < c; ++j) {
                if (graph[i][j] == 'K') {
                    startX = i;
                    startY = j;
                } else if (graph[i][j] == 'H') {
                    endX = i;
                    endY = j;
                }
            }
        }
        printf("%d\n", bfs(startX, startY, endX, endY, r, c));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0188_H
