//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0859_H
#define ACWINGSOLUTION_PROBLEM0859_H

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Problem0859 {
private:
    struct Edge {
        int u;
        int v;
        int w;

        bool operator<(const Edge &e) const {
            return w < e.w;
        }
    };

    int find_root(int x, vector<int> &parent) {
        if (x != parent[x]) {
            parent[x] = find_root(parent[x], parent);
        }
        return parent[x];
    }

    int kruskal(const int n, vector<Edge> &edges, vector<int> &parent) {
        sort(edges.begin(), edges.end());
        int res = 0;
        int cnt = 0;
        for (const auto &e: edges) {
            if (find_root(e.u, parent) == find_root(e.v, parent)) {
                continue;
            }
            parent[find_root(e.u, parent)] = find_root(e.v, parent);
            ++cnt;
            res += e.w;
        }
        if (cnt != n - 1) {  // MST边数应为n-1
            return 0x3f3f3f3f;
        }
        return res;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        vector<Edge> edges(m);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        }
        auto res = kruskal(n, edges, parent);
        if (res == 0x3f3f3f3f) {
            printf("impossible\n");
        } else {
            printf("%d\n", res);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0859_H
