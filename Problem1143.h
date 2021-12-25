//
// Created by Fengwei Zhang on 12/24/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1143_H
#define ACWINGSOLUTION_PROBLEM1143_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Problem1143 {
    // 技巧："缩点"，将连通分量看成1个点，求最小生成树
    // 先选择所有必选边，再枚举非必选边
private:
    struct Edge {
        int u, v, w;

        bool operator<(Edge &e) const {
            return w < e.w;
        }
    };

    int FindRoot(int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = FindRoot(parent[x], parent);
        }
        return parent[x];
    }

    int Kruskal(vector<Edge> &edges, int parent[]) {
        int result = 0;
        sort(edges.begin(), edges.end());
        for (const auto &e: edges) {
            auto p1 = FindRoot(e.u, parent);
            auto p2 = FindRoot(e.v, parent);
            if (p1 == p2) {
                continue;
            }
            parent[p2] = p1;
            result += e.w;
        }
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int parent[n + 1];
        for (int v = 1; v <= n; ++v) {
            parent[v] = v;
        }
        vector<Edge> edges;
        int result = 0;
        for (int i = 0; i < m; ++i) {
            int p, u, v, w;
            scanf("%d%d%d%d", &p, &u, &v, &w);
            if (p == 1) {
                auto p1 = FindRoot(u, parent);
                auto p2 = FindRoot(v, parent);
                parent[p2] = p1;
                result += w;
            } else {
                edges.push_back({u, v, w});
            }
        }
        result += Kruskal(edges, parent);
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1143_H
