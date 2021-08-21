//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0861_H
#define ACWINGSOLUTION_PROBLEM0861_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0861 {
private:
    const int N = 510;
    const int M = 100010;
    int headIndex[N];
    int nextIndex[M];
    int vertexValue[M];
    int matchedVertex[N];
    bool visited[N];

    void addEdge(const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    bool hasMatched(const int a) {
        for (auto idx = headIndex[a]; idx != -1; idx = nextIndex[idx]) {
            auto nextV = vertexValue[idx];
            if (visited[nextV]) {
                continue;
            }
            visited[nextV] = true;
            if (matchedVertex[nextV] && !hasMatched(matchedVertex[nextV])) {
                continue;
            }
            matchedVertex[nextV] = a;
            return true;
        }
        return false;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n1, n2, m;
        scanf("%d%d%d", &n1, &n2, &m);
        int a, b;
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            addEdge(a, b, idx);
        }
        int result = 0;
        for (int v1 = 1; v1 <= n1; ++v1) {
            memset(visited, 0, sizeof visited);
            if (hasMatched(v1)) {
                ++result;
            }
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0861_H
