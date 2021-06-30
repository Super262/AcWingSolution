//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0847_H
#define ACWINGSOLUTION_PROBLEM0847_H

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Problem0847 {
public:
    void addEdge(const int a,
                 const int b,
                 vector<int> &headIndex,
                 vector<int> &vertexValue,
                 vector<int> &nextIndex,
                 int &idx) {
        while (idx >= vertexValue.size()) {
            vertexValue.emplace_back(0);
        }
        while (idx >= nextIndex.size()) {
            nextIndex.emplace_back(-1);
        }
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int bfs(const int root,
            const int target,
            const vector<int> &headIndex,
            const vector<int> &vertexValue,
            const vector<int> &nextIndex,
            vector<int> &distance) {
        if (headIndex[root] == -1) {
            return -1;
        }
        if (target == root) {
            return 0;
        }
        distance[root] = 0;
        queue<int> q;
        q.emplace(root);
        while (!q.empty()) {
            int levelSize = (int) q.size();
            for (int i = 0; i < levelSize; ++i) {
                int v = q.front();
                q.pop();
                for (int idx = headIndex[v]; idx != -1; idx = nextIndex[idx]) {
                    int neighbor = vertexValue[idx];
                    if (distance[neighbor] != -1) {
                        continue;
                    }
                    distance[neighbor] = distance[v] + 1;
                    if (neighbor == target) {
                        return distance[neighbor];
                    }
                    q.emplace(neighbor);
                }
            }
        }
        return -1;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> headIndex(n + 1, -1);
        vector<int> distance(n + 1, -1);
        int idx = 0;
        vector<int> vertexValue;
        vector<int> nextIndex;
        int a, b;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            addEdge(a, b, headIndex, vertexValue, nextIndex, idx);
        }
        printf("%d\n", bfs(1, n, headIndex, vertexValue, nextIndex, distance));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0847_H
