//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0859_H
#define ACWINGSOLUTION_PROBLEM0859_H

#include <algorithm>
#include <iostream>

using namespace std;

struct Edge {
    int start, end, weight;

    bool operator<(const Edge &e) const {
        return weight < e.weight;
    }
};

class Problem0859 {
public:
    int findRoot(int *parent, const int target) {
        if (parent[target] != target) {
            parent[target] = findRoot(parent, parent[target]);
        }
        return parent[target];
    }

    void mergeSets(int *parent, const int a, const int b) {
        parent[findRoot(parent, a)] = findRoot(parent, b);
        findRoot(parent, a);
    }

    int kruskal(Edge *edges, int *parent, const int vertexesCount, const int edgesCount) {
        sort(edges, edges + edgesCount);
        int result = 0;
        int treeSize = 0;
        int start, end;
        for (int i = 0; i < edgesCount; ++i) {
            start = edges[i].start;
            end = edges[i].end;
            start = findRoot(parent, start);
            end = findRoot(parent, end);
            if (start != end) {
                mergeSets(parent, start, end);
                result += edges[i].weight;
                ++treeSize;
            }
        }
        if (treeSize < vertexesCount - 1) {
            return -1;
        }
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int *parent = new int[n + 1];
        Edge *edges = new Edge[m];
        int u, v, w;
        for (int k = 0; k < m; ++k) {
            scanf("%d%d%d", &u, &v, &w);
            edges[k] = Edge{u, v, w};
        }
        for (int k = 1; k <= n; ++k) {
            parent[k] = k;
        }
        int result = kruskal(edges, parent, n, m);
        if (result == -1) {
            puts("impossible");
        } else {
            printf("%d\n", result);
        }
        delete[] parent;
        delete[] edges;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0859_H
