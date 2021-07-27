//
// Created by Fengwei Zhang on 2021/7/27.
//

#ifndef ACWINGSOLUTION_PROBLEM1129_H
#define ACWINGSOLUTION_PROBLEM1129_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1129 {
public:
    int *headIndex;
    int *nextIndex;
    int *vertexValue;
    int *edgeWeight;

    void addEdge(const int s, const int e, const int w, int &idx) {
        vertexValue[idx] = e;
        edgeWeight[idx] = w;
        nextIndex[idx] = headIndex[s];
        headIndex[s] = idx;
        ++idx;
    }

    int spfa(const int start, const int end, const int n, const int m) {
        if (start == end) {
            return 0;
        }
        auto dist = new int[n + 1];
        auto isInQueue = new bool[n + 1];
        memset(dist, 0x7f, sizeof(int) * (n + 1));
        memset(isInQueue, 0, sizeof(bool) * (n + 1));
        auto q = new int[m + 1];
        int hh = 0, tt = -1;
        dist[start] = 0;
        isInQueue[start] = true;
        q[++tt] = start;
        while (hh <= tt) {
            auto root = q[hh++];
            isInQueue[root] = false;
            for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
                int childV = vertexValue[idx];
                if (dist[childV] <= dist[root] + edgeWeight[idx]) {
                    continue;
                }
                dist[childV] = dist[root] + edgeWeight[idx];
                if (isInQueue[childV]) {
                    continue;
                }
                isInQueue[childV] = true;
                q[++tt] = childV;
            }
        }
        int result = dist[end];
        delete[] dist;
        delete[] isInQueue;
        delete[] q;
        return result;
    }

    int main() {
        int t, c, start, end;
        scanf("%d%d%d%d", &t, &c, &start, &end);
        headIndex = new int[t + 1];
        nextIndex = new int[2 * c + 1];
        vertexValue = new int[2 * c + 1];
        edgeWeight = new int[2 * c + 1];
        memset(headIndex, -1, sizeof(int) * (t + 1));
        memset(nextIndex, -1, sizeof(int) * (2 * c + 1));
        memset(vertexValue, 0, sizeof(int) * (2 * c + 1));
        memset(edgeWeight, 0, sizeof(int) * (2 * c + 1));
        int idx = 0;
        for (int i = 0; i < c; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            addEdge(a, b, w, idx);
            addEdge(b, a, w, idx);
        }
        int result = spfa(start, end, t, c);
        printf("%d\n", result);
        delete[] headIndex;
        delete[] nextIndex;
        delete[] vertexValue;
        delete[] edgeWeight;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1129_H
