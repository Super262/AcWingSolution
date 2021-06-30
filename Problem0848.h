//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0848_H
#define ACWINGSOLUTION_PROBLEM0848_H

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Problem0848 {
public:
    void addEdge(const int a, const int b, vector<int> &headIndex, vector<int> &vertexValue, vector<int> &nextIndex,
                 vector<int> &inDegree, int &idx) {
        while (idx >= vertexValue.size()) {
            vertexValue.emplace_back(0);
        }
        while (idx >= nextIndex.size()) {
            nextIndex.emplace_back(-1);
        }
        ++inDegree[b];
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    vector<int> bfsTopo(const vector<int> &headIndex, const vector<int> &vertexValue, const vector<int> &nextIndex,
                        vector<int> &inDegree, vector<bool> &visited) {
        vector<int> result;
        const int n = (int) inDegree.size() - 1;
        queue<int> q;
        for (int v = 1; v <= n; ++v) {
            if (!inDegree[v]) {
                q.emplace(v);
                visited[v] = true;
            }
        }
        while (!q.empty()) {
            int root = q.front();
            q.pop();
            for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
                int neighbor = vertexValue[idx];
                --inDegree[neighbor];
                if (!inDegree[neighbor]) {
                    q.emplace(neighbor);
                    visited[neighbor] = true;
                }
            }
            result.emplace_back(root);
        }
        if (result.size() < n) {
            return vector<int>();
        }
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> headIndex(n + 1, -1);
        vector<int> inDegree(n + 1, 0);
        vector<int> vertexValue;
        vector<int> nextIndex;
        int idx = 0;
        int a, b;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            addEdge(a, b, headIndex, vertexValue, nextIndex, inDegree, idx);
        }
        vector<bool> visited(n + 1, false);
        vector<int> result = bfsTopo(headIndex, vertexValue, nextIndex, inDegree, visited);
        if (result.empty()) {
            printf("-1\n");
        } else {
            for (int v : result) {
                printf("%d ", v);
            }
            printf("\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0848_H
