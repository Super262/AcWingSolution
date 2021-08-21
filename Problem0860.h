//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0860_H
#define ACWINGSOLUTION_PROBLEM0860_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0860 {
private:
    using namespace std;
    const int N = 100010;
    int headIndex[N];
    int nextIndex[2 * N];
    int vertexValue[2 * N];
    int colorValue[N];

    void addEdge(const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    bool dfs(const int v, const int c) {
        colorValue[v] = c;
        for (auto idx = headIndex[v]; idx != -1; idx = nextIndex[idx]) {
            auto nextV = vertexValue[idx];
            if (colorValue[nextV] == colorValue[v]) {
                return false;
            }
            if (!colorValue[nextV] && !dfs(nextV, 3 - c)) {
                return false;
            }
        }
        return true;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n, m;
        scanf("%d%d", &n, &m);
        int a, b;
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            addEdge(a, b, idx);
            addEdge(b, a, idx);
        }
        bool result = true;
        for (int v = 1; v <= n; ++v) {
            if (colorValue[v]) {
                continue;
            }
            if (!dfs(v, 1)) {
                result = false;
                break;
            }
        }
        if (result) {
            puts("Yes");
        } else {
            puts("No");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0860_H
