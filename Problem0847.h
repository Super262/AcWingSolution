//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0847_H
#define ACWINGSOLUTION_PROBLEM0847_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0847 {
private:
    const int N = 100010;
    int headIndex[N];
    int nextIndex[2 * N];
    int vertexValue[2 * N];
    int dist[N];
    int q[2 * N];

    void addEdge(const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int bfs(const int root, const int target) {
        memset(dist, -1, sizeof dist);
        int hh = 0, tt = -1;
        dist[root] = 0;
        q[++tt] = root;
        while (hh <= tt) {
            auto currentLevelSize = tt - hh + 1;
            while (currentLevelSize--) {
                auto node = q[hh++];
                if (node == target) {
                    return dist[node];
                }
                for (auto idx = headIndex[node]; idx != -1; idx = nextIndex[idx]) {
                    auto nextV = vertexValue[idx];
                    if (dist[nextV] != -1) {
                        continue;
                    }
                    q[++tt] = nextV;
                    dist[nextV] = dist[node] + 1;
                }
            }
        }
        return dist[target];
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n, m;
        scanf("%d%d", &n, &m);
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            addEdge(a, b, idx);
        }
        printf("%d\n", bfs(1, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0847_H
