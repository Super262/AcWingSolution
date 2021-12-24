//
// Created by Fengwei Zhang on 12/24/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1141_H
#define ACWINGSOLUTION_PROBLEM1141_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem1141 {
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

    int Kruskal(int parent[], Edge edges[], int k) {
        int result = 0;
        sort(edges, edges + k);
        for (int i = 0; i < k; ++i) {
            auto p1 = FindRoot(edges[i].u, parent);
            auto p2 = FindRoot(edges[i].v, parent);
            if (p1 != p2) {
                parent[p2] = p1;
            } else {
                result += edges[i].w;
            }
        }
        return result;
    }

    int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        int parent[n + 1];
        for (int v = 1; v <= n; ++v) {
            parent[v] = v;
        }
        Edge edges[k];
        for (int i = 0; i < k; ++i) {
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        }
        printf("%d\n", Kruskal(parent, edges, k));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1141_H
