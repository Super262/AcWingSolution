//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0861_H
#define ACWINGSOLUTION_PROBLEM0861_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0861 {
public:
    void addEdge(const int a, const int b, int* headIndex, int *vertexValue, int *nextIndex, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    bool hasMatched(const int start, bool *visited, int *matchedVertex, const int* headIndex, const int *vertexValue, const int *nextIndex) {
        for (int idx = headIndex[start]; idx != -1; idx = nextIndex[idx]) {
            int neighbor = vertexValue[idx];
            if (visited[neighbor]) {
                continue;
            }
            visited[neighbor] = true;
            if (matchedVertex[neighbor] && !hasMatched(matchedVertex[neighbor], visited, matchedVertex, headIndex, vertexValue, nextIndex)) {
                continue;
            }
            matchedVertex[neighbor] = start;
            return true;
        }
        return false;
    }

    int main() {
        int n1, n2, m;
        scanf("%d%d%d", &n1, &n2, &m);
        auto headIndex = new int[n1 + 1];
        auto vertexValue = new int[m];
        auto nextIndex = new int[m];
        memset(headIndex, -1, sizeof(int) * (n1 + 1));
        memset(vertexValue, 0, sizeof(int) * m);
        memset(nextIndex, -1, sizeof(int) * m);
        int idx = 0;
        int x, y;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &x, &y);
            addEdge(x, y, headIndex, vertexValue, nextIndex, idx);
        }
        auto visited = new bool[n2 + 1];
        auto matchedVertex = new int[n2 + 1];
        memset(matchedVertex, 0, sizeof(int) * (n2 + 1));
        int result = 0;
        for (int v = 1; v <= n1; ++v) {
            memset(visited, 0, sizeof(bool) * (n2 + 1));
            if (hasMatched(v, visited, matchedVertex, headIndex, vertexValue, nextIndex)) {
                ++result;
            }
        }
        printf("%d\n", result);
        delete[] headIndex;
        delete[] vertexValue;
        delete[] nextIndex;
        delete[] visited;
        delete[] matchedVertex;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0861_H
