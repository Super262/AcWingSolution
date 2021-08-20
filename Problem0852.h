//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0852_H
#define ACWINGSOLUTION_PROBLEM0852_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0852 {
private:
    const int N = 2010;
    const int M = 10010;
    int headIndex[N];
    int nextIndex[M];
    int vertexValue[M];
    int weight[M];

    void addEdge(const int a, const int b, const int w, int &idx) {
        vertexValue[idx] = b;
        weight[idx] = w;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    bool spfa(const int n, const int m) {
        auto q = new int[m * n + 10];
        auto dist = new int[n + 1];
        auto isInQueue = new bool[n + 1];
        auto routeLen = new int[n + 1];
        memset(dist, 0x7f, sizeof(int) * (n + 1));
        memset(isInQueue, 0, sizeof(bool) * (n + 1));
        memset(routeLen, 0, sizeof(int) * (n + 1));
        int hh = 0, tt = -1;
        for (int v = 1; v <= n; ++v) {
            isInQueue[v] = true;
            q[++tt] = v;
            dist[v] = 0;
        }
        bool result = false;
        while (hh <= tt) {
            auto node = q[hh++];
            isInQueue[node] = false;
            for (auto idx = headIndex[node]; idx != -1; idx = nextIndex[idx]) {
                auto nextV = vertexValue[idx];
                if (dist[nextV] <= dist[node] + weight[idx]) {
                    continue;
                }
                dist[nextV] = dist[node] + weight[idx];
                routeLen[nextV] = routeLen[node] + 1;
                if (routeLen[nextV] >= n) {
                    result = true;
                    break;
                }
                if (isInQueue[nextV]) {
                    continue;
                }
                q[++tt] = nextV;
                isInQueue[nextV] = true;
            }
        }
        delete[] q;
        delete[] dist;
        delete[] isInQueue;
        delete[] routeLen;
        return result;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n, m;
        scanf("%d%d", &n, &m);
        int a, b, w;
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &w);
            addEdge(a, b, w, idx);
        }
        if (spfa(n, m)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0852_H
