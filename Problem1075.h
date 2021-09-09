//
// Created by Fengwei Zhang on 2021/7/16.
//

#ifndef ACWINGSOLUTION_PROBLEM1075_H
#define ACWINGSOLUTION_PROBLEM1075_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1075 {
    // https://www.acwing.com/solution/content/8015/
public:
    const int MAX_N = 100010;
    int headIndex[MAX_N];
    int vertexValue[2 * MAX_N];
    int nextIndex[2 * MAX_N];

    void addEdge(const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int dfs(const int root, const int father, int &maxDistance, bool *visited) {
        visited[root] = true;
        int d1 = 0;
        int d2 = 0;
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            int child = vertexValue[idx];
            if (child == father) {
                continue;
            }
            int d = dfs(child, root, maxDistance, visited) + 1;
            if (d >= d1) {
                d2 = d1;
                d1 = d;
            } else if (d > d2) {
                d2 = d;
            }
        }
        maxDistance = max(maxDistance, d1 + d2);
        return d1;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n;
        scanf("%d", &n);
        auto divisorsSum = new int[n + 1];
        memset(divisorsSum, 0, sizeof(int) * (n + 1));
        for (int a = 1; a <= n; ++a) {
            // b不从1开始，避免累加自身（n）到因子和中
            for (int b = 2; b <= n / a; ++b) {  // 避免溢出，不使用“a * b <= n”
                divisorsSum[a * b] += a;
            }
        }
        int idx = 0;
        for (int i = 1; i <= n; ++i) {
            if (divisorsSum[i] > i) {
                continue;
            }
            // 添加双向边
            addEdge(divisorsSum[i], i, idx);
            addEdge(i, divisorsSum[i], idx);
        }
        auto visited = new bool[n + 1];
        memset(visited, 0, sizeof(bool) * (n + 1));
        int maxDistance = 0;
        for (int i = 1; i < n; ++i) {
            // 遍历所有可能的根结点（数、因数和）
            if (headIndex[i] == -1 || visited[i]) {
                continue;
            }
            dfs(i, -1, maxDistance, visited);
        }
        delete[] divisorsSum;
        delete[] visited;
        printf("%d\n", maxDistance);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1075_H
