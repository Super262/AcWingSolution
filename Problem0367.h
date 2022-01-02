//
// Created by Fengwei Zhang on 1/1/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0367_H
#define ACWINGSOLUTION_PROBLEM0367_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Problem0367 {
    // 牢记结论：https://www.acwing.com/solution/content/24673/
private:
    void Tarjan(const int root,
                const vector<vector<int>> &graph,
                vector<int> &low,
                vector<int> &dfn,
                vector<int> &vid,
                vector<int> &scc_size,
                stack<int> &stk,
                vector<bool> &in_stk,
                int &scc_cnt,
                int &time_stamp) {
        stk.emplace(root);
        in_stk[root] = true;
        ++time_stamp;
        dfn[root] = time_stamp;
        low[root] = time_stamp;
        for (const auto &nv: graph[root]) {
            if (!dfn[nv]) {
                Tarjan(nv, graph, low, dfn, vid, scc_size, stk, in_stk, scc_cnt, time_stamp);
                low[root] = min(low[root], low[nv]);
            } else if (in_stk[nv]) {
                low[root] = min(low[root], dfn[nv]);
            }
        }
        if (low[root] == dfn[root]) {
            ++scc_cnt;
            int y;
            do {
                y = stk.top();
                stk.pop();
                in_stk[y] = false;
                ++scc_size[scc_cnt];
                vid[y] = scc_cnt;
            } while (y != root);
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<vector<int>> graph(n + 1);
        for (int u = 1; u <= n; ++u) {
            int t;
            while (true) {
                scanf("%d", &t);
                if (t == 0) {
                    break;
                }
                graph[u].emplace_back(t);
            }
        }
        vector<int> low(n + 1, 0);
        vector<int> dfn(n + 1, 0);
        vector<int> vid(n + 1, 0);
        vector<int> scc_size(n + 1, 0);
        vector<bool> in_stk(n + 1, false);
        stack<int> stk;
        int scc_cnt = 0;
        int time_stamp = 0;
        for (int v = 1; v <= n; ++v) {
            if (dfn[v]) {
                continue;
            }
            Tarjan(v, graph, low, dfn, vid, scc_size, stk, in_stk, scc_cnt, time_stamp);
        }
        vector<int> de_out(n + 1, 0);
        vector<int> de_in(n + 1, 0);
        for (int v = 1; v <= n; ++v) {
            auto a = vid[v];
            for (const auto &nv: graph[v]) {
                auto b = vid[nv];
                if (a == b) {
                    continue;
                }
                ++de_out[a];
                ++de_in[b];
            }
        }
        int p = 0, q = 0;
        for (int i = 1; i <= scc_cnt; ++i) {
            if (de_in[i] == 0) {
                ++p;
            }
            if (de_out[i] == 0) {
                ++q;
            }
        }
        printf("%d\n", p);
        if (scc_cnt == 1) {
            printf("%d\n", 0);
        } else {
            printf("%d\n", max(p, q));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0367_H
