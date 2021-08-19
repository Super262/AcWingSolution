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
    int nextIndex[2 * N];
    int weight[2 * N];
    int vertexValue[2 * N];

    void addEdge(const int a, const int b, const int w, int &idx) {
        vertexValue[idx] = b;
        weight[idx] = w;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int spfa(const int root, const int target, const int n) {
        auto q = new int[2 * N];  // 队列的空间应该和边的数量一致
        auto dist = new int[n + 1];
        auto isInQueue = new bool[n + 1];
        memset(dist, 0x7f, sizeof(int) * (n + 1));
        memset(isInQueue, 0, sizeof(bool) * (n + 1));
        int hh = 0, tt = -1;
        q[++tt] = root;
        isInQueue[root] = true;
        dist[root] = 0;
        while (hh <= tt) {
            auto node = q[hh++];
            isInQueue[node] = false;
            for (int idx = headIndex[node]; idx != -1; idx = nextIndex[idx]) {
                auto nextV = vertexValue[idx];
                if (dist[nextV] <= dist[node] + weight[idx]) {
                    continue;
                }
                dist[nextV] = dist[node] + weight[idx];
                if (isInQueue[nextV]) {
                    continue;
                }
                q[++tt] = nextV;
                isInQueue[nextV] = true;
            }
        }
        delete[] isInQueue;
        delete[] q;
        auto result = dist[target];
        delete[] dist;
        if (result == 0x7f7f7f7f) {
            result = -1;
        }
        return result;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n, m;
        scanf("%d%d", &n, &m);
        int idx = 0;
        int a, b, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &w);
            addEdge(a, b, w, idx);
        }
        int result = spfa(1, n, n);
        if (result == -1) {
            printf("impossible\n");
        } else {
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0851_H
