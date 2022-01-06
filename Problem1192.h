//
// Created by Fengwei Zhang on 10/6/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1192_H
#define ACWINGSOLUTION_PROBLEM1192_H

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Problem1192 {
private:
    bool TopoSort(const int n, int degree[], const vector<vector<int>> &graph, vector<int> &res) {
        queue<int> q;
        for (int v = 1; v <= n; ++v) {
            if (degree[v]) {
                continue;
            }
            q.emplace(v);
        }
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            res.emplace_back(root);
            for (const auto &nv: graph[root]) {
                --degree[nv];
                if (degree[nv] != 0) {
                    continue;
                }
                q.emplace(nv);
            }
        }
        return res.size() == n;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1);
        int degree[n + 1];
        memset(degree, 0, sizeof degree);
        while (m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            graph[b].emplace_back(a);
            ++degree[a];
        }
        vector<int> res;
        if (!TopoSort(n, degree, graph, res)) {
            puts("Poor Xed");
            return 0;
        }
        int dist[n + 1];
        for (int i = 1; i <= n; ++i) {
            dist[i] = 100;
        }
        for (const auto &v: res) {
            for (const auto &u: graph[v]) {
                dist[u] = max(dist[u], dist[v] + 1);
            }
        }
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result += dist[i];
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1192_H
