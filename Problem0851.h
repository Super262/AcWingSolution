//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0851_H
#define ACWINGSOLUTION_PROBLEM0851_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0851 {
private:
    const int N = 100010;
    int headIndex[N];
    int nextIndex[N];
    int vertexValue[N];
    int weight[N];

    void addEdge(int a, int b, int w, int &idx) {
        vertexValue[idx] = b;
        weight[idx] = w;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int spfa(int start, int end, int n) {
        int q[N];
        int hh = 0, tt = -1;
        bool isInQueue[n + 1];
        int dist[n + 1];
        memset(dist, 0x3f, sizeof dist);
        memset(isInQueue, 0, sizeof isInQueue);
        q[++tt] = start;
        isInQueue[root] = true;
        dist[start] = 0;
        while (hh <= tt) {  // 先尝试更新距离，再尝试压入队列
            auto root = q[hh++];
            isInQueue[root] = false;
            for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
                auto nextV = vertexValue[idx];
                if (dist[nextV] < dist[root] + weight[idx]) {
                    continue;
                }
                dist[nextV] = dist[root] + weight[idx];
                if (isInQueue[nextV]) {
                    continue;
                }
                q[++tt] = nextV;
                isInQueue[nextV] = true;
            }
        }
        if (dist[end] == 0x3f3f3f3f) {
            return -1;
        }
        return dist[end];
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n, m;
        scanf("%d%d", &n, &m);
        int x, y, w;
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            addEdge(x, y, w, idx);
        }
        auto result = spfa(1, n, n);
        if (result == -1) {
            printf("impossible\n");
        } else {
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0851_H
