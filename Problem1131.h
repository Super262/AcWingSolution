//
// Created by Fengwei Zhang on 12/22/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1131_H
#define ACWINGSOLUTION_PROBLEM1131_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Problem1131 {
// https://www.acwing.com/solution/content/14900/
// 注意数组下标：题目中所有的索引（坐标，钥匙编号）都从1开始
private:
    int GetIdx(int x, int y, int m) {
        return (x - 1) * m + y - 1;
    }

    int Bfs(int stx,
            int sty,
            int edx,
            int edy,
            int n,
            int m,
            int p,
            const vector<vector<int>> &graph,
            const vector<int> &keys) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n * m, vector<bool>(1 << (p + 1), false));
        vector<vector<int>> dist(n * m, vector<int>(1 << (p + 1), 0x3f3f3f3f));
        const int dx[] = {0, -1, 0, 1};
        const int dy[] = {1, 0, -1, 0};
        auto sti = GetIdx(stx, sty, m);
        dist[sti][keys[sti]] = 0;
        visited[sti][keys[sti]] = true;
        q.emplace(sti, keys[sti]);
        while (!q.empty()) {
            auto rt = q.front();
            q.pop();
            auto ri = rt.first;
            auto rs = rt.second;
            auto rx = ri / m + 1;
            auto ry = ri % m + 1;
            if (rx == edx && ry == edy) {
                return dist[ri][rs];
            }
            for (int i = 0; i < 4; ++i) {
                auto nx = rx + dx[i];
                auto ny = ry + dy[i];
                auto ni = GetIdx(nx, ny, m);
                if (nx < 1 || ny < 1 || nx > n || ny > m || graph[ri][ni] == 0) {
                    continue;
                }
                if (graph[ri][ni] != -1 && ((rs >> graph[ri][ni]) & 1) == 0) {
                    continue;
                }
                auto ns = rs | keys[ni];
                if (visited[ni][ns]) {
                    continue;
                }
                dist[ni][ns] = dist[ri][rs] + 1;
                q.emplace(ni, ns);
                visited[ni][ns] = true;
            }
        }
        return -1;
    }

    int main() {
        int n, m, p, k;
        scanf("%d%d%d%d", &n, &m, &p, &k);
        vector<vector<int>> graph(n * m, vector<int>(n * m, -1));
        for (int i = 0; i < k; ++i) {
            int x1, y1, x2, y2, z;
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &z);
            auto t1 = GetIdx(x1, y1, m);
            auto t2 = GetIdx(x2, y2, m);
            graph[t1][t2] = z;
            graph[t2][t1] = z;
        }
        vector<int> keys(n * m, 0);
        int s;
        scanf("%d", &s);
        for (int i = 0; i < s; ++i) {
            int x, y, q;
            scanf("%d%d%d", &x, &y, &q);
            keys[GetIdx(x, y, m)] |= (1 << q);
        }
        printf("%d\n", Bfs(1, 1, n, m, n, m, p, graph, keys));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1131_H
