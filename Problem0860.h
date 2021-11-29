//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0860_H
#define ACWINGSOLUTION_PROBLEM0860_H

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Problem0860 {
private:
    bool dfs(int root, int val, vector<int> &color, const vector<vector<int>> &graph) {
        color[root] = val;
        for (const auto &nv: graph[root]) {
            if (color[nv] == val) {
                return false;
            }
            if (color[nv] == 0 && !dfs(nv, 3 - val, color, graph)) {
                return false;
            }
        }
        return true;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1, vector<int>());
        vector<int> color(n + 1, 0);
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        bool result = true;
        for (int i = 1; i <= n; ++i) {
            if (color[i] != 0) {
                continue;
            }
            if (!dfs(i, 1, color, graph)) {
                result = false;
                break;
            }
        }
        if (result) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0860_H
