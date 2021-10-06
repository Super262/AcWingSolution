//
// Created by Fengwei Zhang on 10/6/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1191_H
#define ACWINGSOLUTION_PROBLEM1191_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1191 {
private:
    const int N = 101;
    int headIndex[N], nextIndex[N * N], vertexValue[N * N];
    int degree[N];
    int q[N];

    void topoSort(const int n) {
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
    }

    void addEdge(const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n;
        scanf("%d", &n);
        int idx = 0;
        for (int i = 1; i <= n; ++i) {
            int a;
            while (true) {
                scanf("%d", &a);
                if (a == 0) {
                    break;
                }
                addEdge(i, a, idx);
                ++degree[a];
            }
        }
        topoSort(n);
        for (int i = 0; i < n; ++i) {
            printf("%d ", q[i]);
        }
        printf("\n");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1191_H
