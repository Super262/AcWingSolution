//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0860_H
#define ACWINGSOLUTION_PROBLEM0860_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0860 {
public:
    void addEdge(const int a,
                 const int b,
                 vector<int> &headIndex,
                 vector<int> &vertexValue,
                 vector<int> &nextIndex,
                 int &idx) {
        if (idx >= vertexValue.size()) {
            vertexValue.emplace_back(0);
        }
        if (idx >= nextIndex.size()) {
            nextIndex.emplace_back(-1);
        }
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    bool dfs(const int start,
             const int c,
             vector<int> &color,
             const vector<int> &headIndex,
             const vector<int> &vertexValue,
             const vector<int> &nextIndex) {
        color[start] = c;
        for (int neighborIdx = headIndex[start]; neighborIdx != -1; neighborIdx = nextIndex[neighborIdx]) {
            int v = vertexValue[neighborIdx];
            if (!color[v]) {
                if (!dfs(v, 3 - c, color, headIndex, vertexValue, nextIndex)) {
                    return false;
                }
            } else if (color[v] == c) {
                return false;
            }
        }
        return true;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> headIndex(n + 1, -1);
        vector<int> vertexValue(2 * n + 1, 0);
        vector<int> nextIndex(2 * n + 1, -1);
        int idx = 0;
        int u, v;
        while (m--) {
            scanf("%d%d", &u, &v);
            addEdge(u, v, headIndex, vertexValue, nextIndex, idx);
            addEdge(v, u, headIndex, vertexValue, nextIndex, idx);
        }
        vector<int> color(n + 1, 0);
        for (int j = 1; j <= n; ++j) {
            if (color[j]) {
                continue;
            }
            if (!dfs(j, 1, color, headIndex, vertexValue, nextIndex)) {
                puts("No");
                return 0;
            }
        }
        puts("Yes");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0860_H
