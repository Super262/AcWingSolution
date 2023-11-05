//
// Created by Fengwei Zhang on 1/7/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0356_H
#define ACWINGSOLUTION_PROBLEM0356_H

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

class Problem0356 {
    // 用LCA加速求解次小生成树
    // f[i][j]：树上编号为i的节点向上移动2^j步后抵达的节点
    // d1[i][j]：在树上，编号为i的节点到编号为(i+2^j)的节点的路径上的最小边权
    // d2[i][j]：在树上，编号为i的节点到编号为(i+2^j)的节点的路径上的次小边权
private:
    static const int H = 16;
    static const int INF = 0x3f3f3f3f;

    struct Edge {
        int u, v, w;
        bool used;

        bool operator<(const Edge &e) const {
            return w < e.w;
        }
    };

    int find_root(const int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = find_root(parent[x], parent);
        }
        return parent[x];
    }

    long long kruskal(Edge edges[], const int m, const int n) {
        int parent[n + 1];
        for (int v = 0; v <= n; ++v) {
            parent[v] = v;
        }
        sort(edges, edges + m);
        long long result = 0;
        for (int i = 0; i < m; ++i) {
            auto &e = edges[i];
            auto pu = find_root(e.u, parent);
            auto pv = find_root(e.v, parent);
            if (pu == pv) {
                continue;
            }
            result += e.w;
            parent[pv] = pu;
            e.used = true;
        }
        return result;
    }

    vector<vector<pair<int, int>>> buildGraph(const int n, const Edge edges[], const int m) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < m; ++i) {
            if (!edges[i].used) {
                continue;
            }
            auto u = edges[i].u;
            auto v = edges[i].v;
            auto w = edges[i].w;
            graph[u].emplace_back(w, v);
            graph[v].emplace_back(w, u);
        }
        return graph;
    }

    void bfs(const vector<vector<pair<int, int>>> &graph,
             int depth[],
             int f[][H + 1],
             int d1[][H + 1],
             int d2[][H + 1]) {
        depth[0] = 0;  // 哨兵
        depth[1] = 1;
        queue<int> q;
        q.emplace(1);
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (const auto &nt: graph[x]) {
                auto nd = nt.first;
                auto nv = nt.second;
                if (depth[nv] <= depth[x] + 1) {
                    continue;
                }
                depth[nv] = depth[x] + 1;
                q.emplace(nv);
                f[nv][0] = x;
                d1[nv][0] = nd;
                d2[nv][0] = -INF;
                for (int k = 1; k <= H; ++k) {
                    auto ancestor = f[nv][k - 1];
                    f[nv][k] = f[ancestor][k - 1];
                    int temp[4] = {d1[nv][k - 1], d1[ancestor][k - 1], d2[nv][k - 1], d2[ancestor][k - 1]};
                    d1[nv][k] = -INF;
                    d2[nv][k] = -INF;
                    for (int d: temp) {
                        if (d > d1[nv][k]) {
                            d2[nv][k] = d1[nv][k];
                            d1[nv][k] = d;
                        } else if (d < d1[nv][k] && d > d2[nv][k]) {
                            d2[nv][k] = d;
                        }
                    }
                }
            }
        }
    }

    int lca(const Edge &e,
            const vector<vector<pair<int, int>>> &graph,
            const int depth[],
            int father[][H + 1],
            int d1[][H + 1],
            int d2[][H + 1]) {
        auto a = e.u;
        auto b = e.v;
        if (depth[a] < depth[b]) {
            swap(a, b);
        }
        static int q[300010];  // 存储所有可能被选中的边权（这里不能使用queue，会超时；不忘记static）
        int tt = 0;
        for (int k = H; k >= 0; --k) {
            if (depth[father[a][k]] < depth[b]) {
                continue;
            }
            q[tt++] = d1[a][k];
            q[tt++] = d2[a][k];
            a = father[a][k];
        }
        if (a != b) {
            for (int k = H; k >= 0; --k) {
                if (father[a][k] == father[b][k]) {
                    continue;
                }
                q[tt++] = d1[a][k];
                q[tt++] = d2[a][k];
                q[tt++] = d1[b][k];
                q[tt++] = d2[b][k];
                a = father[a][k];
                b = father[b][k];
            }
            q[tt++] = d1[a][0];
            q[tt++] = d1[b][0];
        }
        int t1 = -INF;
        int t2 = -INF;
        for (int i = 0; i < tt; ++i) {
            auto x = q[i];
            if (x > t1) {
                t2 = t1;
                t1 = x;
            } else if (x < t1 && x > t2) {
                t2 = x;
            }
        }
        if (e.w > t1) {
            return e.w - t1;
        }
        if (e.w > t2) {
            return e.w - t2;
        }
        return INF;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);

        Edge edges[m];
        for (int i = 0; i < m; ++i) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            edges[i] = {x, y, z, false};
        }

        auto mst_sum = kruskal(edges, m, n);
        auto graph = buildGraph(n, edges, m);

        int depth[n + 1];
        int father[n + 1][H + 1];
        int d1[n + 1][H + 1];
        int d2[n + 1][H + 1];
        memset(depth, 0x3f, sizeof depth);
        memset(father, 0, sizeof father);
        memset(d1, 0, sizeof d1);
        memset(d2, 0, sizeof d2);

        bfs(graph, depth, father, d1, d2);

        long long result = 1e18;  // 无效值一定要足够大
        for (int i = 0; i < m; ++i) {
            if (edges[i].used) {
                continue;
            }
            result = min(result, mst_sum + lca(edges[i], graph, depth, father, d1, d2));
        }
        printf("%lld\n", result);

        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0356_H
