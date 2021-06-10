//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0861_H
#define ACWINGSOLUTION_PROBLEM0861_H

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Problem0861 {
public:
    void addEdge(const int v1,
                 const int v2,
                 int *headIndex,
                 vector<int> &vertexValue,
                 vector<int> &nextIndex,
                 int &idx) {
        if (idx >= (int) vertexValue.size()) {
            vertexValue.emplace_back(0);
        }
        if (idx >= (int) nextIndex.size()) {
            nextIndex.emplace_back(-1);
        }
        vertexValue[idx] = v2;
        nextIndex[idx] = headIndex[v1];
        headIndex[v1] = idx;
        ++idx;
    }

    bool getMatched(const int start,
                    int *matchedVertex,
                    bool *visited,
                    const int *headIndex,
                    const vector<int> &vertexValue,
                    const vector<int> &nextIndex) {
        for (int neighborIdx = headIndex[start]; neighborIdx != -1; neighborIdx = nextIndex[neighborIdx]) {
            int v = vertexValue[neighborIdx];
            if (visited[v]) {
                continue;
            }
            visited[v] = true;
            if (matchedVertex[v] &&
                !getMatched(matchedVertex[v], matchedVertex, visited, headIndex, vertexValue, nextIndex)) {
                continue;
            }
            matchedVertex[v] = start;
            return true;
        }
        return false;
    }

    int main() {
        int n1, n2, m;
        scanf("%d%d%d", &n1, &n2, &m);
        vector<int> vertexValue(m, 0);
        vector<int> nextIndex(m, -1);
        int *headIndex = new int[n1 + 1];
        for (int i = 1; i <= n1; ++i) {
            headIndex[i] = -1;
        }
        int idx = 0;
        int a, b;
        while (m--) {
            scanf("%d%d", &a, &b);
            addEdge(a, b, headIndex, vertexValue, nextIndex, idx);
        }
        int *matchedVertex = new int[n2 + 1];
        memset(matchedVertex, 0, (n2 + 1) * sizeof(int));
        bool *visited = new bool[n2 + 1];
        int result = 0;
        for (int v1 = 1; v1 <= n1; ++v1) {
            memset(visited, 0, (n2 + 1) * sizeof(bool));
            if (!getMatched(v1, matchedVertex, visited, headIndex, vertexValue, nextIndex)) {
                continue;
            }
            ++result;
        }
        printf("%d\n", result);
        delete[] matchedVertex;
        delete[] visited;
        delete[] headIndex;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0861_H
