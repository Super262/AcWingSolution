//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0848_H
#define ACWINGSOLUTION_PROBLEM0848_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Problem0848 {
private:
    vector<int> bfs(const int n, const vector<vector<int>> &graph, vector<int> &in_degree) {
        queue<int> q;
        vector<int> res;
        for (int i = 1; i <= n; ++i) {
            if (in_degree[i] == 0) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            res.emplace_back(t);
            for (const auto &v: graph[t]) {
                --in_degree[v];
                if (in_degree[v] == 0) {
                    q.emplace(v);
                }
            }
        }
        return res;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1, vector<int>());
        vector<int> in_degree(n + 1, 0);
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            graph[u].emplace_back(v);
            ++in_degree[v];
        }
        auto res = bfs(n, graph, in_degree);
        if (res.size() != n) {
            printf("-1\n");
        } else {
            for (const auto &x: res) {
                printf("%d ", x);
            }
            printf("\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0848_H
