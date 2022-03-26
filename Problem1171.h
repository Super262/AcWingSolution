//
// Created by Fengwei Zhang on 1/7/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1171_H
#define ACWINGSOLUTION_PROBLEM1171_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Problem1171 {
    // https://www.acwing.com/solution/content/9034/
private:
    vector<int> bfs(const int root, const vector<vector<pair<int, int>>> &graph) {
        vector<int> dist(graph.size(), 0x3f3f3f3f);
        queue<int> q;
        q.emplace(root);
        dist[root] = 0;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (const auto &nt: graph[x]) {
                auto nv = nt.second;
                auto nd = nt.first;
                if (dist[nv] <= dist[x] + nd) {
                    continue;
                }
                dist[nv] = dist[x] + nd;
                q.emplace(nv);
            }
        }
        return dist;
    }

    int findRoot(const int x, vector<int> &parent) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x], parent);
        }
        return parent[x];
    }

    void tarjan(const int u,
                const vector<vector<pair<int, int>>> &graph,
                vector<int> &parent,
                const vector<int> &dist,
                vector<int> &status,
                const vector<vector<pair<int, int>>> &queries,
                vector<int> &result) {
        status[u] = 1;
        for (const auto &nt: graph[u]) {
            auto nv = nt.second;
            if (status[nv]) {
                continue;
            }
            tarjan(nv, graph, parent, dist, status, queries, result);
            parent[nv] = u;
        }
        for (const auto &q: queries[u]) {
            auto v = q.first;
            auto idx = q.second;
            if (status[v] != 2) {
                continue;
            }
            auto ancestor = findRoot(v, parent);
            result[idx] = dist[u] + dist[v] - 2 * dist[ancestor];
        }
        status[u] = 2;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int a, b, k;
            scanf("%d%d%d", &a, &b, &k);
            graph[a].emplace_back(k, b);
            graph[b].emplace_back(k, a);
        }
        vector<vector<pair<int, int>>> queries(n + 1);
        for (int idx = 0; idx < m; ++idx) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == y) {
                continue;
            }
            queries[x].emplace_back(y, idx);
            queries[y].emplace_back(x, idx);
        }
        auto dist = bfs(1, graph);
        vector<int> parent(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
        vector<int> result(m, 0);
        vector<int> status(n + 1, 0);
        tarjan(1, graph, parent, dist, status, queries, result);
        for (const auto &x: result) {
            printf("%d\n", x);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1171_H
