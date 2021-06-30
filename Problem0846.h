//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0846_H
#define ACWINGSOLUTION_PROBLEM0846_H

#include <vector>
#include <iostream>

class Problem0846 {
public:
    void addEdge(const int a,
                 const int b,
                 vector<int> &headIndex,
                 vector<int> &nextIndex,
                 vector<int> &vertexValue,
                 int &idx) {
        while (idx >= nextIndex.size()) {
            nextIndex.emplace_back(-1);
        }
        while (idx >= vertexValue.size()) {
            vertexValue.emplace_back(0);
        }
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int dfs(const int root,
            const int n,
            const vector<int> &headIndex,
            const vector<int> &nextIndex,
            const vector<int> &vertexValue,
            vector<bool> &visited, int &answer) {
        int nodesCount = 1;
        int maxComponentSize = 1;
        visited[root] = true;
        for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
            int v = vertexValue[idx];
            if (visited[v]) {
                continue;
            }
            int childSize = dfs(v, n, headIndex, nextIndex, vertexValue, visited, answer);
            maxComponentSize = max(maxComponentSize, childSize);
            nodesCount += childSize;
        }
        maxComponentSize = max(maxComponentSize, n - nodesCount);
        answer = min(maxComponentSize, answer);
        return nodesCount;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int a, b;
        vector<int> headIndex(n + 1, -1);
        vector<int> nextIndex(n, -1);
        vector<int> vertexValue(n, 0);
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a, &b);
            addEdge(a, b, headIndex, nextIndex, vertexValue, idx);
            addEdge(b, a, headIndex, nextIndex, vertexValue, idx);
        }
        vector<bool> visited(n + 1, false);
        int answer = n;
        dfs(1, n, headIndex, nextIndex, vertexValue, visited, answer);
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0846_H
