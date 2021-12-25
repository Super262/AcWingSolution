//
// Created by Fengwei Zhang on 12/24/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1142_H
#define ACWINGSOLUTION_PROBLEM1142_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem1142 {
    // 本题中的最小生成树：最大的边权最小
private:
    struct Edge {
        int u, v, w;

        bool operator<(const Edge &e) const {
            return w < e.w;
        }
    };

    int FindRoot(const int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = FindRoot(parent[x], parent);
        }
        return parent[x];
    }

    pair<int, int> Kruskal(int parent[], Edge edges[], int k) {
        int result = -1;
        int counter = 0;
        sort(edges, edges + k);
        for (int i = 0; i < k; ++i) {
            auto p1 = FindRoot(edges[i].u, parent);
            auto p2 = FindRoot(edges[i].v, parent);
            if (p1 == p2) {
                continue;
            }
            parent[p2] = p1;
            result = max(result, edges[i].w);
            ++counter;
        }
        return {counter, result};
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int parent[n + 1];
        for (int v = 1; v <= n; ++v) {
            parent[v] = v;
        }
        Edge edges[m];
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        }
        auto t = Kruskal(parent, edges, m);
        printf("%d %d\n", t.first, t.second);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1142_H
