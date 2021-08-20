//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0859_H
#define ACWINGSOLUTION_PROBLEM0859_H

#include <algorithm>
#include <iostream>

using namespace std;

struct Edge {
    int start;
    int end;
    int weight;

    bool operator<(const Edge &e) const {  // 牢记这个函数重载的模版
        return weight < e.weight;
    }
};

class Problem0859 {
private:
    const int N = 100010;
    int parent[N];
    Edge edges[2 * N];

    int findRoot(const int x) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }

    void mergeSets(const int a, const int b) {
        parent[findRoot(a)] = findRoot(b);
    }

    int kruskal(const int edgesSize, const int vertexesNum) {
        sort(edges, edges + edgesSize);
        int mstSize = 0;
        int mstWeight = 0;
        for (int i = 0; i < edgesSize; ++i) {
            auto a = edges[i].start;
            auto b = edges[i].end;
            if (findRoot(a) == findRoot(b)) {
                continue;
            }
            mergeSets(a, b);
            mstWeight += edges[i].weight;
            ++mstSize;
        }
        if (mstSize != vertexesNum - 1) {
            mstWeight = -1;
        }
        return mstWeight;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int v = 1; v <= n; ++v) {
            parent[v] = v;
        }
        int a, b, w;
        int edgeIdx = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &w);
            edges[edgeIdx].start = a;
            edges[edgeIdx].end = b;
            edges[edgeIdx].weight = w;
            ++edgeIdx;
        }
        int result = kruskal(m, n);
        if (result == -1) {
            printf("impossible\n");
        } else {
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0859_H
