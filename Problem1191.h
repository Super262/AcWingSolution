//
// Created by Fengwei Zhang on 10/6/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1191_H
#define ACWINGSOLUTION_PROBLEM1191_H

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Problem1191 {
private:
    vector<int> TopoSort(const int n, const vector<vector<int>> &graph, int degree[]) {
        queue<int> q;
        for (int v = 1; v <= n; ++v) {
            if (degree[v]) {
                continue;
            }
            q.emplace(v);
        }
        vector<int> res;
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
        return res;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int degree[n + 1];
        vector<vector<int>> graph(n + 1);
        memset(degree, 0, sizeof degree);
        for (int u = 1; u <= n; ++u) {
            while (true) {
                int v;
                scanf("%d", &v);
                if (v == 0) {
                    break;
                }
                graph[u].emplace_back(v);
                ++degree[v];
            }
        }
        auto res = TopoSort(n, graph, degree);
        for (const auto &v: res) {
            printf("%d ", v);
        }
        printf("\n");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1191_H
