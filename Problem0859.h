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
    int findRoot(const int target, int *parent) {
        if (parent[target] != target) {
            parent[target] = findRoot(parent[target], parent);
        }
        return parent[target];
    }

    void mergeSets(const int a, const int b, int *parent) {
        parent[findRoot(a, parent)] = findRoot(b, parent);
        findRoot(a, parent);
    }

    int kruskal(Edge *edges, int *parent, const int edgesNum, const int vertexsNum) {
        sort(edges, edges + edgesNum);
        int result = 0;
        int treeSize = 0;
        for (int i = 0; i < edgesNum; ++i) {
            int ra = findRoot(edges[i].start, parent);
            int rb = findRoot(edges[i].end, parent);
            if (ra == rb) {
                continue;
            }
            mergeSets(ra, rb, parent);
            ++treeSize;
            result += edges[i].weight;
        }
        if (treeSize < vertexsNum - 1) {
            return -1;
        }
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        auto parent = new int[n + 1];
        auto edges = new Edge[m];
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edges[i].start, &edges[i].end, &edges[i].weight);
        }
        int t = kruskal(edges, parent, m, n);
        if (t == -1) {
            puts("impossible");
        } else {
            printf("%d\n", t);
        }
        delete[] parent;
        delete[] edges;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0859_H
