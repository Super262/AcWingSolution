//
// Created by Fengwei Zhang on 12/26/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1148_H
#define ACWINGSOLUTION_PROBLEM1148_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Problem1148 {
    // 1. 建立最小生成树，并标记树边
    // 2. 预处理，计算任意两点a、b间路径上最大边的权重c1和次大边的权重c2
    // 3. 依次枚举所有非树边，求min(sum + w - c1)，w > c1 或 min(sum + w - c2)，w > c2
private:
    struct Edge {
        int u, v, w;
        bool for_mst;

        bool operator<(const Edge &e) const {
            return w < e.w;
        }
    };

    int FindRoot(int x, vector<int> &parent) {
        auto u = x;
        while (u != parent[u]) {
            u = parent[u];
        }
        while (x != u) {
            auto p = parent[x];
            parent[x] = u;
            x = p;
        }
        return u;
    }

    pair<long long, vector<vector<pair<int, int>>>> Kruskal(vector<Edge> &edges, const int n, vector<int> &parent) {
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
        long long mst_size = 0;
        sort(edges.begin(), edges.end());
        for (auto &e: edges) {
            auto pu = FindRoot(e.u, parent);
            auto pv = FindRoot(e.v, parent);
            if (pu == pv) {
                continue;
            }
            parent[pu] = pv;
            mst_size += e.w;
            e.for_mst = true;
            graph[e.u].push_back({e.w, e.v});
            graph[e.v].push_back({e.w, e.u});
        }
        return {mst_size, graph};
    }

    void dfs(const vector<vector<pair<int, int>>> &graph,
             const int v,
             const int parent,
             const int first_current_maximal,
             const int second_current_maximal,
             vector<int> &first_longest_part,
             vector<int> &second_longest_part) {
        first_longest_part[v] = first_current_maximal;
        second_longest_part[v] = second_current_maximal;
        for (const auto &t: graph[v]) {
            if (t.second == parent) {
                continue;
            }
            auto next_w = t.first;
            auto first_next = first_current_maximal;
            auto second_next = second_current_maximal;
            if (next_w > first_next) {
                second_next = first_next;
                first_next = next_w;
            } else if (next_w < first_next && next_w > second_next) {  // 不要忘记这需要2个条件
                second_next = next_w;
            }
            dfs(graph, t.second, v, first_next, second_next, first_longest_part, second_longest_part);
        }
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<Edge> edges(m);
        vector<int> parent(n + 1);
        vector<vector<int>> first_longest_part(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> second_longest_part(n + 1, vector<int>(n + 1, 0));
        for (int v = 1; v <= n; ++v) {
            parent[v] = v;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
            edges[i].for_mst = false;
        }
        auto temp = Kruskal(edges, n, parent);
        auto mst_size = temp.first;
        auto graph = temp.second;
        for (int v = 1; v <= n; ++v) {
            dfs(graph, v, -1, 0, 0, first_longest_part[v], second_longest_part[v]);
        }
        long long result = 1e18;
        for (const auto &e: edges) {
            if (e.for_mst) {
                continue;
            }
            if (e.w > first_longest_part[e.u][e.v]) {
                result = min(result, mst_size + e.w - first_longest_part[e.u][e.v]);
            } else if (e.w > second_longest_part[e.u][e.v]) {
                result = min(result, mst_size + e.w - second_longest_part[e.u][e.v]);
            }
        }
        printf("%lld\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1148_H
