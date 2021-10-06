//
// Created by Fengwei Zhang on 10/6/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1192_H
#define ACWINGSOLUTION_PROBLEM1192_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1192 {
private:
    const int N = 10010;
    int headIndex[N], nextIndex[2 * N], vertexValue[2 * N];
    int degree[N];
    int q[N];

    void addEdge(const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    bool topoSort(const int n) {
        int hh = 0, tt = -1;
        for (int i = 1; i <= n; ++i) {
            if (degree[i]) {
                continue;
            }
            q[++tt] = i;
        }
        while (hh <= tt) {
            auto root = q[hh++];
            for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
                auto childV = vertexValue[idx];
                --degree[childV];
                if (degree[childV] == 0) {
                    q[++tt] = childV;
                }
            }
        }
        return tt + 1 == n;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n, m;
        scanf("%d%d", &n, &m);
        int a, b, idx = 0;
        while (m--) {
            scanf("%d%d", &a, &b);
            addEdge(b, a, idx);
            ++degree[a];
        }
        if (!topoSort(n)) {
            puts("Poor Xed");
            return 0;
        }
        int dist[n + 1];
        for (int i = 1; i <= n; ++i) {
            dist[i] = 100;
        }
        for (int i = 0; i < n; ++i) {
            auto v = q[i];
            for (auto j = headIndex[v]; j != -1; j = nextIndex[j]) {
                auto u = vertexValue[j];
                dist[u] = max(dist[u], dist[v] + 1);
            }
        }
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result += dist[i];
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1192_H
