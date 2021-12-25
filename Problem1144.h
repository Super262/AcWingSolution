//
// Created by Fengwei Zhang on 12/25/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1144_H
#define ACWINGSOLUTION_PROBLEM1144_H

#include <iostream>
#include <vector>

using namespace std;

class Problem1144 {
private:
    struct Edge {
        int a, b, w;
    };

    int FindRoot(int x, vector<int> &parent) {
        if (x != parent[x]) {
            parent[x] = FindRoot(parent[x], parent);
        }
        return parent[x];
    }

    vector<Edge> GetEdges(const int n, const int m, const vector<vector<int>> &ids) {
        vector<Edge> edges;
        const int dx[] = {-1, 0, 1, 0};
        const int dy[] = {0, 1, 0, -1};
        const int dw[] = {1, 2, 1, 2};
        for (int z = 0; z < 2; ++z) {  // 先枚举纵向边，再枚举横向边。利用余数实现
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    for (int u = 0; u < 4; ++u) {
                        if (u % 2 != z) {
                            continue;
                        }
                        auto nx = i + dx[u];
                        auto ny = j + dy[u];
                        if (nx < 1 || ny < 1 || nx > n || ny > m) {
                            continue;
                        }
                        auto a = ids[i][j];
                        auto b = ids[nx][ny];
                        if (a < b) {  // 避免同一个方向的边被反复加入
                            edges.push_back({a, b, dw[u]});
                        }
                    }
                }
            }
        }
        return edges;
    }

    int Kruskal(const vector<Edge> &edges, vector<int> &parent) {
        // 由于边权为1或2，我们可以省略排序步骤
        int result = 0;
        for (const auto &e: edges) {
            auto pa = FindRoot(e.a, parent);
            auto pb = FindRoot(e.b, parent);
            if (pa == pb) {
                continue;
            }
            parent[pa] = pb;
            result += e.w;
        }
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> parent(n * m);
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
        vector<vector<int>> ids(n + 1, vector<int>(m + 1));
        for (int i = 1, t = 0; i <= n; ++i) {  // 映射点到索引
            for (int j = 1; j <= m; ++j, ++t) {
                ids[i][j] = t;
            }
        }
        int x1, y1, x2, y2;
        while (scanf("%d%d%d%d", &x1, &y1, &x2, &y2) != -1) {
            auto a = ids[x1][y1];
            auto b = ids[x2][y2];
            parent[FindRoot(a, parent)] = FindRoot(b, parent);
        }
        auto edges = GetEdges(n, m, ids);
        printf("%d\n", Kruskal(edges, parent));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1144_H
