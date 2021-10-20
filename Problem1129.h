//
// Created by Fengwei Zhang on 2021/7/27.
//

#ifndef ACWINGSOLUTION_PROBLEM1129_H
#define ACWINGSOLUTION_PROBLEM1129_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1129 {
private:
    const int N = 7000;
    int headIndex[N];
    int vertexValue[2 * N];
    int nextIndex[2 * N];
    int weight[2 * N];

    void addEdge(const int &a, const int &b, const int &w, int &idx) {
        vertexValue[idx] = b;
        weight[idx] = w;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int spfa(const int &start, const int &end, const int &n) {
        int dist[n + 1];
        bool inQueue[n + 1];
        int q[N];
        int hh = 0, tt = -1;
        memset(inQueue, 0, sizeof inQueue);
        memset(dist, 0x3f, sizeof dist);
        dist[start] = 0;
        inQueue[start] = true;
        q[++tt] = start;
        while (hh <= tt) {
            auto root = q[hh++];
            inQueue[root] = false;
            for (auto idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
                auto nV = vertexValue[idx];
                if (dist[nV] < dist[root] + weight[idx]) {
                    continue;
                }
                dist[nV] = dist[root] + weight[idx];
                if (inQueue[nV]) {
                    continue;
                }
                inQueue[nV] = true;
                q[++tt] = nV;
            }
        }
        return dist[end];
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int t, c, s, e;
        scanf("%d%d%d%d", &t, &c, &s, &e);
        int x, y, w;
        int idx = 0;
        for (int i = 0; i < c; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            addEdge(x, y, w, idx);
            addEdge(y, x, w, idx);
        }
        printf("%d\n", spfa(s, e, t));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1129_H
