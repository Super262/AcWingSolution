//
// Created by Fengwei Zhang on 2021/7/24.
//

#ifndef ACWINGSOLUTION_PROBLEM1112_H
#define ACWINGSOLUTION_PROBLEM1112_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1112 {
private:
    const int N = 110;
    char graph[N][N];
    bool visited[N][N];
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

    bool dfs(const int sX, const int sY, const int eX, const int eY, const int n) {
        visited[sX][sY] = true;
        if (sX == eX && sY == eY) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            auto nX = sX + dx[i];
            auto nY = sY + dy[i];
            if (nX < 0 || nX >= n || nY < 0 || nY >= n || visited[nX][nY] || graph[nX][nY] == '#') {
                continue;
            }
            if (dfs(nX, nY, eX, eY, n)) {
                return true;
            }
        }
        return false;
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            memset(visited, 0, sizeof visited);
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                scanf("%s", graph[i]);
            }
            int sx, sy, ex, ey;
            scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
            if (graph[sx][sy] != '#' && graph[ex][ey] != '#' && dfs(sx, sy, ex, ey, n)) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1112_H
