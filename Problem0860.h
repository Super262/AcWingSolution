//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0860_H
#define ACWINGSOLUTION_PROBLEM0860_H

#include <cstring>
#include <iostream>

using namespace std;

class Problem0860 {
public:
    void addEdge(const int a, const int b, int *headIndex, int *vertexValue, int *nextIndex, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    bool dfs(const int start, const int c, int *colorValue, const int *headIndex, const int *vertexValue, const int *nextIndex) {
        colorValue[start] = c;
        for (int idx = headIndex[start]; idx != -1; idx = nextIndex[idx]) {
            auto neighbor = vertexValue[idx];
            if (colorValue[neighbor] == c || (!colorValue[neighbor] && !dfs(neighbor, 3 - c, colorValue, headIndex, vertexValue, nextIndex))) {
                return false;
            }
        }
        return true;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        auto headIndex = new int[n + 1];
        auto vertexValue = new int[2 * m];
        auto nextIndex = new int[2 * m];
        int idx = 0;
        memset(headIndex, -1, sizeof(int) * (n + 1));
        memset(vertexValue, 0, sizeof(int) * (2 * m));
        memset(nextIndex, -1, sizeof(int) * (2 * m));
        int x, y;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &x, &y);
            addEdge(x, y, headIndex, vertexValue, nextIndex, idx);
            addEdge(y, x, headIndex, vertexValue, nextIndex, idx);
        }
        auto colorValue = new int[n + 1];
        memset(colorValue, 0, sizeof(int) * (n + 1));
        bool result = true;
        for (int v = 1; v <= n; ++v) {
            if (colorValue[v]) {
                continue;
            }
            if (!dfs(v, 1, colorValue, headIndex, vertexValue, nextIndex)) {
                result = false;
                break;
            }
        }
        if (result) {
            puts("Yes");
        } else {
            puts("No");
        }
        delete[] headIndex;
        delete[] vertexValue;
        delete[] nextIndex;
        delete[] colorValue;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0860_H
