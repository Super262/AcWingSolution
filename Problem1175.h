//
// Created by Fengwei Zhang on 1/1/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1175_H
#define ACWINGSOLUTION_PROBLEM1175_H

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Problem1175 {
    // https://www.acwing.com/solution/content/24796/
private:
    void Tarjan(const int u,
                const vector<vector<int>> &graph,
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
        in_stk[u] = true;
        stk.emplace(u);
        for (const auto &nv: graph[u]) {
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
        int n, m, x;
        scanf("%d%d%d", &n, &m, &x);
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            graph[a].emplace_back(b);
        }
        // 为提高速度，不使用vector初始化状态数组
        int sid[n + 1];
        int disc[n + 1];
        int low[n + 1];
        int scc_size[n + 1];
        bool in_stk[n + 1];
        stack<int> stk;
        int scc_cnt = 0;
        int time_stamp = 0;
        memset(sid, 0, sizeof sid);
        memset(disc, 0, sizeof disc);
        memset(low, 0, sizeof low);
        memset(scc_size, 0, sizeof scc_size);
        memset(in_stk, 0, sizeof in_stk);
        for (int v = 1; v <= n; ++v) {
            if (disc[v]) {
                continue;
            }
            Tarjan(v, graph, sid, disc, low, scc_size, in_stk, stk, scc_cnt, time_stamp);
        }
        unordered_set<long long> edges_set; // 判重，避免加入重边：a * 100000ll + b，a、b是强连通块的编号
        vector<vector<int>> scc_dag(scc_cnt + 1);
        for (int u = 1; u <= n; ++u) {
            auto a = sid[u];
            for (const auto &v: graph[u]) {
                auto b = sid[v];
                if (a == b) {
                    continue;
                }
                if (edges_set.count(a * 100000ll + b)) {
                    continue;
                }
                edges_set.insert(a * 100000ll + b);
                scc_dag[a].emplace_back(b);
            }
        }
        int dp[scc_cnt + 1];  // dp[i]：以编号为i的强连通块结尾的"链"中包含的顶点数
        int counter[scc_cnt + 1];  // counter[i]：满足顶点数为dp[i]的"链"的数量
        memset(dp, 0, sizeof dp);
        memset(counter, 0, sizeof counter);
        for (int u = scc_cnt; u >= 1; --u) {  // 按拓扑序搜索：Tarjan的编号顺序为反拓扑序，因此这里要逆序
            if (!dp[u]) {
                dp[u] = scc_size[u];
                counter[u] = 1;
            }
            for (const auto &v: scc_dag[u]) {
                if (dp[v] < dp[u] + scc_size[v]) {
                    dp[v] = dp[u] + scc_size[v];
                    counter[v] = counter[u];
                } else if (dp[v] == dp[u] + scc_size[v]) {
                    counter[v] = (int) (((long long) counter[v] + counter[u]) % x);
                }
            }
        }
        int max_path = -1, sol_cnt = 0;
        for (int i = 1; i <= scc_cnt; ++i) {
            if (dp[i] > max_path) {
                max_path = dp[i];
                sol_cnt = counter[i];
            } else if (dp[i] == max_path) {
                sol_cnt = (int) (((long long) sol_cnt + counter[i]) % x);
            }
        }
        printf("%d\n", max_path);
        printf("%d\n", sol_cnt);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1175_H
