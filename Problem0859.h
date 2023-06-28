//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0859_H
#define ACWINGSOLUTION_PROBLEM0859_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0859 {
private:
    const int INF = 0x3f3f3f3f;

    struct Edge {
        int u;
        int v;
        int w;

        bool operator<(const Edge &e) const {
            return w < e.w;
        }
    };

    int findRoot(int x, int parent[]) {
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

    int mergeSets(int pa, int pb, int parent[], int set_size[]) {
        if (pa == pb) {
            return -1;
        }
        if (set_size[pb] > set_size[pa]) {
            swap(pa, pb);
        }
        set_size[pa] += set_size[pb];
        parent[pb] = pa;
        return pa;
    }

    int kruskal(const int n, const int m, Edge edges[], int parent[], int set_size[]) {
        sort(edges, edges + m);
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            auto pa = findRoot(edges[i].u, parent);
            auto pb = findRoot(edges[i].v, parent);
            if (pa == pb) {
                continue;
            }
            mergeSets(pa, pb, parent, set_size);
            ++cnt;
            ans += edges[i].w;
        }
        if (cnt != n - 1) {  // MST边数应为n-1
            return INF;
        }
        return ans;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int parent[n + 1];
        int set_size[n + 1];
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            set_size[i] = 1;
        }
        Edge edges[m];
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        }
        auto ans = kruskal(n, m, edges, parent, set_size);
        if (ans == INF) {
            printf("impossible\n");
        } else {
            printf("%d\n", ans);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0859_H
