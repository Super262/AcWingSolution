//
// Created by Fengwei Zhang on 2/13/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0529_H
#define ACWINGSOLUTION_PROBLEM0529_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Problem0529 {
    // https://www.acwing.com/solution/content/59439/
    // 状压DP + 最小生成树
    // 求二进制状态s的子集p：for (auto p = (s - 1) & s; p; p = (p - 1) & s)
private:
    static const int INF = 0x3f3f3f3f;

    vector<int> buildNext(const vector<vector<int>> &graph, const int n) {
        vector<int> ne(1 << n, 0);
        for (int st = 1; st < (1 << n); ++st) {
            for (int u = 0; u < n; ++u) {
                if (!((st >> u) & 1)) {
                    continue;
                }
                for (int v = 0; v < n; ++v) {
                    if (graph[u][v] == INF) {
                        continue;
                    }
                    ne[st] |= (1 << v);
                }
            }
        }
        return ne;
    }

    int getCost(const int cur, const int pre, const int n, const vector<vector<int>> &graph, const vector<int> &ne) {
        if ((ne[pre] & cur) != cur) {
            return -1;
        }
        auto remains = pre ^ cur;
        int cost = 0;
        for (int v = 0; v < n; ++v) {
            if (!((remains >> v) & 1)) {
                continue;
            }
            int t = 500000;  // 题意中有效的最大边长为5e5
            for (int u = 0; u < n; ++u) {
                if (!((pre >> u) & 1)) {
                    continue;
                }
                t = min(t, graph[u][v]);
            }
            cost += t;
        }
        return cost;
    }

    int dp(const int n, const vector<vector<int>> &graph) {
        int f[1 << n][n];
        memset(f, 0x3f, sizeof f);
        for (int u = 0; u < n; ++u) {
            f[1 << u][0] = 0;
        }
        const auto &ne = buildNext(graph, n);
        for (int cur = 1; cur < (1 << n); ++cur) {
            for (auto pre = (cur - 1) & cur; pre; pre = (pre - 1) & cur) {
                auto cost = getCost(cur, pre, n, graph, ne);
                if (cost == -1) {
                    continue;
                }
                for (int d = 1; d < n; ++d) {
                    f[cur][d] = min(f[cur][d], f[pre][d - 1] + cost * d);
                }
            }
        }
        auto res = INF;
        for (int d = 0; d < n; ++d) {
            res = min(res, f[(1 << n) - 1][d]);
        }
        return res;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n, vector<int>(n, INF));
        for (int v = 0; v < n; ++v) {
            graph[v][v] = 0;
        }
        while (m--) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            --u;
            --v;
            graph[u][v] = min(graph[u][v], w);
            graph[v][u] = graph[u][v];
        }
        printf("%d\n", dp(n, graph));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0529_H
