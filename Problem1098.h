//
// Created by Fengwei Zhang on 2021/7/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1098_H
#define ACWINGSOLUTION_PROBLEM1098_H

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem1098 {
    // https://www.acwing.com/solution/content/7771/
public:
    static const int N = 50;
    bool visited[N][N];
    int graph[N][N];
    pair<int, int> q[N * N + 1];
    const int dx[] = {0, -1, 0, 1};
    const int dy[] = {-1, 0, 1, 0};

    int bfs(const int x, const int y, const int n, const int m) {
        int hh = 0, tt = -1;
        int area = 0;
        q[++tt] = pair<int, int>(x, y);
        visited[x][y] = true;
        while (hh <= tt) {
            ++area;
            auto root = q[hh++];
            auto rootX = root.first;
            auto rootY = root.second;
            for (int i = 0; i < 4; ++i) {
                if ((graph[rootX][rootY] >> i) & 1) {
                    continue;
                }
                auto nextX = rootX + dx[i];
                auto nextY = rootY + dy[i];
                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
                    continue;
                }
                if (visited[nextX][nextY]) {
                    continue;
                }
                visited[nextX][nextY] = true;
                q[++tt] = pair<int, int>(nextX, nextY);
            }
        }
        return area;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &graph[i][j]);
            }
        }
        int roomsCount = 0;
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j]) {
                    continue;
                }
                ++roomsCount;
                maxArea = max(maxArea, bfs(i, j, n, m));
            }
        }
        printf("%d\n%d\n", roomsCount, maxArea);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1098_H
