//
// Created by Fengwei Zhang on 1/4/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0378_H
#define ACWINGSOLUTION_PROBLEM0378_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Problem0378 {
    // https://www.acwing.com/solution/content/8945/
private:
    int GetIdx(int x, int y, int base) {
        return (x - 1) * base + y - 1;
    }

    bool HasMatched(int x, int y, int n, int m, const vector<vector<bool>> &graph, bool visited[], int matched[]) {
        const int dx[] = {1, -1, 2, -2, -2, 2, -1, 1};
        const int dy[] = {2, 2, 1, 1, -1, -1, -2, -2};
        for (int i = 0; i < 8; ++i) {
            auto nx = x + dx[i];
            auto ny = y + dy[i];
            auto ni = GetIdx(nx, ny, m);
            if (nx < 1 || ny < 1 || nx > n || ny > m || graph[nx][ny] || visited[ni]) {
                continue;
            }
            visited[ni] = true;
            auto tx = matched[ni] / m + 1;
            auto ty = matched[ni] % m + 1;
            if (matched[ni] == -1 || HasMatched(tx, ty, n, m, graph, visited, matched)) {
                matched[ni] = GetIdx(x, y, m);
                return true;
            }
        }
        return false;
    }

    int main() {
        int n, m, t;
        scanf("%d%d%d", &n, &m, &t);
        vector<vector<bool>> graph(n + 1, vector<bool>(m + 1, false));
        for (int i = 0; i < t; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            graph[x][y] = true;
        }
        bool visited[n * m];
        int matched[n * m];
        memset(matched, -1, sizeof matched);
        int matched_cnt = 0;
        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= m; ++y) {
                if (graph[x][y] || (x + y) % 2) {
                    continue;
                }
                memset(visited, 0, sizeof visited);
                if (HasMatched(x, y, n, m, graph, visited, matched)) {
                    ++matched_cnt;
                }
            }
        }
        printf("%d\n", n * m - t - matched_cnt);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0378_H
