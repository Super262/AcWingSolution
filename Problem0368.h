//
// Created by Fengwei Zhang on 1/2/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0368_H
#define ACWINGSOLUTION_PROBLEM0368_H

#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

class Problem0368 {
    // 使用Tarjan算法解决差分约束问题：https://www.acwing.com/solution/content/24811/
private:
    void Tarjan(const int u,
                const vector<vector<pair<int, int>>> &graph,
                int vid[],
                int disc[],
                int low[],
                int scc_size[],
                bool in_stk[],
                stack<int> &stk,
                int &scc_cnt,
                int &time_stamp) {
        ++time_stamp;
        disc[u] = time_stamp;
        low[u] = time_stamp;
        stk.emplace(u);
        in_stk[u] = true;
        for (const auto &nt: graph[u]) {
            auto nv = nt.second;
            if (!disc[nv]) {
                Tarjan(nv, graph, vid, disc, low, scc_size, in_stk, stk, scc_cnt, time_stamp);
                low[u] = min(low[u], low[nv]);
            } else if (in_stk[nv]) {
                low[u] = min(low[u], disc[nv]);
            }
        }
        if (low[u] == disc[u]) {
            ++scc_cnt;
            int y;
            do {
                y = stk.top();
                stk.pop();
                in_stk[y] = false;
                vid[y] = scc_cnt;
                ++scc_size[scc_cnt];
            } while (y != u);
        }
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<pair<int, int>>> graph(n + 1);
        // 初始化所有差分约束
        for (int i = 1; i <= n; ++i) {
            graph[0].emplace_back(1, i);
        }
        while (m--) {
            int t, a, b;
            scanf("%d%d%d", &t, &a, &b);
            if (t == 1) {
                graph[a].emplace_back(0, b);
                graph[b].emplace_back(0, a);
            } else if (t == 2) {
                graph[a].emplace_back(1, b);
            } else if (t == 3) {
                graph[b].emplace_back(0, a);
            } else if (t == 4) {
                graph[b].emplace_back(1, a);
            } else {
                graph[a].emplace_back(0, b);
            }
        }
        int vid[n + 1];
        int disc[n + 1];
        int low[n + 1];
        int scc_size[n + 1];
        bool in_stk[n + 1];
        stack<int> stk;
        int scc_cnt = 0;
        int time_stamp = 0;
        memset(vid, 0, sizeof vid);
        memset(disc, 0, sizeof disc);
        memset(low, 0, sizeof low);
        memset(scc_size, 0, sizeof scc_size);
        memset(in_stk, 0, sizeof in_stk);
        Tarjan(0, graph, vid, disc, low, scc_size, in_stk, stk, scc_cnt, time_stamp);
        bool success = true;
        vector<vector<pair<int, int>>> scc_dag(scc_cnt + 1);
        for (int v = 0; v <= n; ++v) {
            auto a = vid[v];
            for (const auto &nt: graph[v]) {
                auto nv = nt.second;
                auto b = vid[nv];
                if (a == b) {
                    if (nt.first > 0) {
                        success = false;
                        break;
                    }
                } else {
                    scc_dag[a].emplace_back(nt.first, b);
                }
            }
            if (!success) {
                break;
            }
        }
        if (!success) {
            printf("%d\n", -1);
        } else {
            int dist[scc_cnt + 1];
            memset(dist, 0, sizeof dist);
            for (int i = scc_cnt; i >= 1; --i) {
                for (const auto &nt: scc_dag[i]) {
                    dist[nt.second] = max(dist[nt.second], dist[i] + nt.first);
                }
            }
            long long res = 0;
            for (int i = 1; i <= scc_cnt; ++i) {
                res += (long long) dist[i] * scc_size[i];
            }
            printf("%lld\n", res);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0368_H
