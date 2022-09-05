//
// Created by Fengwei Zhang on 2021/7/24.
//

#ifndef ACWINGSOLUTION_PROBLEM1116_H
#define ACWINGSOLUTION_PROBLEM1116_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1116 {
private:
    static const int N = 10;
    bool visited[N][N];
    const int dx[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
    const int dy[8] = {2, -2, 1, -1, -2, 2, -1, 1};

    void dfs(int sx, int sy, int n, int m, int curCount, int &answer) {
        if (curCount == n * m) {
            ++answer;
            return;
        }
        visited[sx][sy] = true;
        for (int i = 0; i < 8; ++i) {
            auto nx = sx + dx[i];
            auto ny = sy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
                continue;
            }
            dfs(nx, ny, n, m, curCount + 1, answer);
        }
        visited[sx][sy] = false;
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n, m, sx, sy;
            scanf("%d%d%d%d", &n, &m, &sx, &sy);
            int answer = 0;
            memset(visited, 0, sizeof visited);
            dfs(sx, sy, n, m, 1, answer);
            printf("%d\n", answer);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1116_H
