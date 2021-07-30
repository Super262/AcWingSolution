//
// Created by Fengwei Zhang on 2021/7/30.
//

#ifndef ACWINGSOLUTION_PROBLEM1137_H
#define ACWINGSOLUTION_PROBLEM1137_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1137 {
public:
    const int N = 2010, M = 22010;
    int headIndex[N], nextIndex[M], vertexValue[M], edgeWeight[M];
    int dist[N], q[N];
    bool isInQueue[N];

    void addEdge(const int s, const int e, const int w, int &idx) {
        vertexValue[idx] = e;
        edgeWeight[idx] = w;
        nextIndex[idx] = headIndex[s];
        headIndex[s] = idx;
        ++idx;
    }

    int spfa(const int e) {
        int hh = 0, tt = -1;
        memset(isInQueue, 0, sizeof isInQueue);
        memset(dist, 0x7f, sizeof dist);
        dist[0] = 0;
        q[++tt] = 0;
        isInQueue[0] = true;
        while (hh <= tt) {
            auto root = q[hh++];
            isInQueue[root] = false;
            for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
                auto childV = vertexValue[idx];
                if (dist[childV] <= dist[root] + edgeWeight[idx]) {
                    continue;
                }
                dist[childV] = dist[root] + edgeWeight[idx];
                if (isInQueue[childV]) {
                    continue;
                }
                q[++tt] = childV;
                isInQueue[childV] = true;
            }
        }
        return dist[e] == 0x7f7f7f7f ? -1 : dist[e];
    }

    int main() {
        int n, m, s;
        while (scanf("%d%d%d", &n, &m, &s) != -1) {
            memset(headIndex, -1, sizeof headIndex);
            memset(nextIndex, -1, sizeof nextIndex);
            int idx = 0;
            for (int i = 1; i <= m; ++i) {
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                addEdge(a, b, c, idx);
            }
            int w;
            scanf("%d", &w);
            for (int i = 1; i <= w; ++i) {
                int v;
                scanf("%d", &v);
                addEdge(0, v, 0, idx);
            }
            printf("%d\n", spfa(s));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1137_H
