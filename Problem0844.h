//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0844_H
#define ACWINGSOLUTION_PROBLEM0844_H

#include <algorithm>
#include <iostream>

using namespace std;

class Problem0844 {
private:
    const int N = 100;
    int matrix[N][N];
    bool visited[N][N];
    pair<int, int> q[N * N + 10];

    int bfs(const int n, const int m) {
        int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
        int hh = 0, tt = -1;
        q[++tt] = pair<int, int>(n - 1, m - 1);
        visited[n - 1][m - 1] = true;
        int result = 0;
        while (hh <= tt) {
            int curL = tt - hh + 1;
            while (curL--) {
                auto root = q[hh++];
                if (root.first == 0 && root.second == 0) {
                    return result;
                }
                for (int i = 0; i < 4; ++i) {
                    auto nextX = root.first + dx[i];
                    auto nextY = root.second + dy[i];
                    if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || matrix[nextX][nextY] == 1 ||
                        visited[nextX][nextY]) {
                        continue;
                    }
                    q[++tt] = pair<int, int>(nextX, nextY);
                    visited[nextX][nextY] = true;
                }
            }
            ++result;
        }
        return 0x7f7f7f7f;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }
        printf("%d\n", bfs(n, m));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0844_H
