//
// Created by Fengwei Zhang on 1/6/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0164_H
#define ACWINGSOLUTION_PROBLEM0164_H

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <bitset>

using namespace std;

class Problem0164 {
    // 思路：先拓扑排序；由于当前点可达性依赖于后继点，所以再逆序统计可达性
    // https://www.acwing.com/solution/content/8511/
private:
    vector<int> TopoSort(const int n, const vector<vector<int>> &graph, int degree[]) {
        vector<int> res;
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
                if (degree[nv]) {
                    continue;
                }
                q.emplace(nv);
            }
        }
        return res;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1);
        int degree[n + 1];
        memset(degree, 0, sizeof degree);
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            graph[x].emplace_back(y);
            ++degree[y];
        }
        auto order = TopoSort(n, graph, degree);
        bitset<30001> dp[n + 1];
        for (int i = (int) order.size() - 1; i >= 0; --i) {
            auto u = order[i];
            dp[u][u] = true;
            for (const auto &v: graph[u]) {
                dp[u] |= dp[v];
            }
        }
        for (int v = 1; v <= n; ++v) {
            printf("%d\n", (int) dp[v].count());
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0164_H
