//
// Created by Fengwei Zhang on 12/25/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0346_H
#define ACWINGSOLUTION_PROBLEM0346_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0346 {
    // https://www.acwing.com/solution/content/2456/
private:
    struct Edge {
        int u, v, w;

        bool operator<(const Edge &e) const {
            return w < e.w;
        }
    };

    int FindRoot(int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = FindRoot(parent[x], parent);
        }
        return parent[x];
    }

    long long Kruskal(int n, int parent[], int cluster_size[], Edge edges[], int m) {
        sort(edges, edges + m);
        long long result = 0;
        for (int i = 0; i < m; ++i) {
            auto pa = FindRoot(edges[i].u, parent);
            auto pb = FindRoot(edges[i].v, parent);
            if (pa == pb) {
                continue;
            }
            result += ((long long) cluster_size[pa] * cluster_size[pb] - 1) * (edges[i].w + 1);
            parent[pb] = pa;
            cluster_size[pa] += cluster_size[pb];
        }
        return result;
    }

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int n;
            scanf("%d", &n);
            int parent[n + 1];
            int cluster_size[n + 1];
            for (int v = 1; v <= n; ++v) {
                parent[v] = v;
                cluster_size[v] = 1;
            }
            Edge edges[n - 1];
            for (int i = 0; i < n - 1; ++i) {
                scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
            }
            printf("%lld\n", Kruskal(n, parent, cluster_size, edges, n - 1));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0346_H
