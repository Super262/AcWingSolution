//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0848_H
#define ACWINGSOLUTION_PROBLEM0848_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0848 {
private:
    const int N = 100010;
    int headIndex[N];
    int nextIndex[2 * N];
    int vertexValue[2 * N];
    int inDegree[N];
    int result[N];
    int q[2 * N];

    void addEdge(const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        ++inDegree[b];
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    bool bfs(const int n) {
        // 拓扑排序的BFS过程不需要visited数组
        int resultTop = 0;
        int hh = 0, tt = -1;
        for (int i = 1; i <= n; ++i) {
            if (inDegree[i]) {
                continue;
            }
            q[++tt] = i;
        }
        while (hh <= tt) {
            auto node = q[hh++];
            result[resultTop++] = node;
            for (int idx = headIndex[node]; idx != -1; idx = nextIndex[idx]) {
                int nV = vertexValue[idx];
                --inDegree[nV];
                if (inDegree[nV]) {
                    continue;
                }
                q[++tt] = nV;
            }
        }
        return resultTop == n;
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
        if (bfs(n)) {
            for (int i = 0; i < n; ++i) {
                printf("%d ", result[i]);
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0848_H
