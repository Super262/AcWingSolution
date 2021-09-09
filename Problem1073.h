//
// Created by Fengwei Zhang on 2021/7/16.
//

#ifndef ACWINGSOLUTION_PROBLEM1073_H
#define ACWINGSOLUTION_PROBLEM1073_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1073 {
    // https://www.acwing.com/solution/content/29249/
public:
    int headIndex[10010];
    int vertexValue[20010];
    int nextIndex[20010];
    int weight[20010];
    int d1[10010];
    int d2[10010];
    int u1[10010];
    int d1Next[10010];

    void addEdge(const int a, const int b, const int w, int &idx) {
        vertexValue[idx] = b;
        weight[idx] = w;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int dfs_down(const int root, const int father) {
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            int child = vertexValue[idx];
            if (child == father) {
                continue;
            }
            int d = dfs_down(child, root) + weight[idx];
            if (d >= d1[root]) {
                d2[root] = d1[root];
                d1[root] = d;
                d1Next[root] = child;
            } else if (d > d2[root]) {
                d2[root] = d;
            }
        }
        return d1[root];
    }

    void dfs_up(const int root, const int father) {
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            int child = vertexValue[idx];
            if (child == father) {
                continue;
            }
            if (d1Next[root] == child) {
                u1[child] = max(u1[root], d2[root]) + weight[idx];
            } else {
                u1[child] = max(u1[root], d1[root]) + weight[idx];
            }
            dfs_up(child, root);
        }
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof headIndex);
        int n;
        scanf("%d", &n);
        int idx = 0;
        for (int i = 0; i < n - 1; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            addEdge(a, b, w, idx);
            addEdge(b, a, w, idx);
        }
        dfs_down(1, -1);
        dfs_up(1, -1);
        int result = 0x7f7f7f7f;
        for (int i = 1; i <= n; ++i) {
            result = min(result, max(d1[i], u1[i]));
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1073_H
