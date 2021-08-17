//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0846_H
#define ACWINGSOLUTION_PROBLEM0846_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0846 {
private:
    const int N = 100010;
    bool visited[N];
    int headIndex[N];
    int vertexValue[2 * N];
    int nextIndex[2 * N];

    void addEdge(const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int dfs(const int root, const int n, int &answer) {
        visited[root] = true;
        int maxComponentSize = 1;
        int nodesCount = 1;
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            auto childV = vertexValue[idx];
            if (visited[childV]) {
                continue;
            }
            auto childSize = dfs(childV, n, answer);
            maxComponentSize = max(maxComponentSize, childSize);
            nodesCount += childSize;
        }
        maxComponentSize = max(maxComponentSize, n - nodesCount);
        answer = min(answer, maxComponentSize);
        return nodesCount;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n;
        scanf("%d", &n);
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            addEdge(a, b, idx);
            addEdge(b, a, idx);
        }
        int answer = n;
        dfs(1, n, answer);
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0846_H
