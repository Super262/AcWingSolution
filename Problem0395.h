//
// Created by Fengwei Zhang on 1/2/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0395_H
#define ACWINGSOLUTION_PROBLEM0395_H

#include <cstring>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

class Problem0395 {
    // 有向图变强连通需加边数：max(p, q)，详见367题
    // 无向图变双连通需加边数：(cnt + 1) / 2
    // https://www.acwing.com/solution/content/8518/
private:
    void Tarjan(const int u,
                const int pi,
                int disc[],
                int low[],
                int did[],
                const vector<vector<pair<int, int>>> &graph,
                stack<int> &stk,
                int &time_stamp,
                int &edcc_cnt) {  // 标记无向图中的双连通分量
        ++time_stamp;
        disc[u] = time_stamp;
        low[u] = time_stamp;
        stk.emplace(u);
        for (const auto &nt: graph[u]) {
            auto v = nt.first;
            auto ei = nt.second;
            if (!disc[v]) {
                Tarjan(v, ei, disc, low, did, graph, stk, time_stamp, edcc_cnt);
                low[u] = min(low[u], low[v]);
                // 若disc[u] < low[v], (u, v) 是桥
            } else if (ei != (pi ^ 1)) {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (disc[u] == low[u]) {
            ++edcc_cnt;
            int y;
            do {
                y = stk.top();
                stk.pop();
                did[y] = edcc_cnt;
            } while (y != u);
        }
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int idx = 2;  // 边的编号，双向边为一对：(2, 3)，(4, 5)，跳过(0, 1)，避免冲突
        vector<vector<pair<int, int>>> graph(n + 1);
        while (m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            graph[a].emplace_back(b, idx++);
            graph[b].emplace_back(a, idx++);
        }
        int disc[n + 1];
        int low[n + 1];
        int did[n + 1];
        stack<int> stk;
        int time_stamp = 0;
        int edcc_cnt = 0;
        memset(disc, 0, sizeof disc);
        memset(low, 0, sizeof low);
        memset(did, 0, sizeof did);
        for (int v = 1; v <= n; ++v) {
            if (disc[v]) {
                continue;
            }
            Tarjan(v, -1, disc, low, did, graph, stk, time_stamp, edcc_cnt);
        }
        int degree[edcc_cnt + 1];
        memset(degree, 0, sizeof degree);
        for (int u = 1; u <= n; ++u) {
            for (const auto &t: graph[u]) {
                if (did[u] == did[t.first]) {
                    continue;
                }
                ++degree[did[t.first]];
            }
        }
        int cnt = 0;
        for (int i = 1; i <= edcc_cnt; ++i) {
            if (degree[i] != 1) {
                continue;
            }
            ++cnt;
        }
        printf("%d\n", (cnt + 1) / 2);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0395_H
