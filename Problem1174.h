//
// Created by Fengwei Zhang on 1/1/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1174_H
#define ACWINGSOLUTION_PROBLEM1174_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Problem1174 {
    // https://www.acwing.com/solution/content/42606/
private:
    void Tarjan(const int root,
                int &time_stamp,
                int &scc_cnt,
                stack<int> &stk,
                const vector<vector<int>> &graph,
                vector<int> &sid,
                vector<int> &low,
                vector<int> &disc,
                vector<bool> &in_stk,
                vector<int> &scc_size) {
        ++time_stamp;
        disc[root] = time_stamp;
        low[root] = time_stamp;
        stk.emplace(root);
        in_stk[root] = true;
        for (const auto &nv: graph[root]) {
            if (!disc[nv]) {
                Tarjan(nv, time_stamp, scc_cnt, stk, graph, sid, low, disc, in_stk, scc_size);
                low[root] = min(low[root], low[nv]);
            } else if (in_stk[nv]) {
                low[root] = min(low[root], disc[nv]);
            }
        }
        if (disc[root] == low[root]) {
            ++scc_cnt;
            int y;
            do {
                y = stk.top();
                stk.pop();
                in_stk[y] = false;
                sid[y] = scc_cnt;
                ++scc_size[scc_cnt];
            } while (y != root);
        }
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> graph(n + 1);
        while (m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            graph[a].emplace_back(b);
        }
        vector<int> low(n + 1, 0);  // low[u]：从u开始的搜索路径的所有点的时间戳的最小值
        vector<int> disc(n + 1, 0);  // disc[u]: u被发现的时间
        stack<int> stk;
        vector<bool> in_stk(n + 1, false);
        vector<int> scc_size(n + 1, 0);  // scc_size[i]：编号为i的强连通块的大小
        vector<int> sid(n + 1, 0);  // sid[x]：点x所在的强连通块的编号
        int scc_cnt = 0;  // 当前强连通块的个数
        int time_stamp = 0;  // 当前时间
        for (int v = 1; v <= n; ++v) {
            if (disc[v]) {
                continue;
            }
            Tarjan(v, time_stamp, scc_cnt, stk, graph, sid, low, disc, in_stk, scc_size);
        }
        vector<int> de_out(n + 1, 0);  // 记录每个连通分量的出度
        for (int v = 1; v <= n; ++v) {
            auto a = sid[v];
            for (const auto &nv: graph[v]) {
                auto b = sid[nv];
                if (a == b) {
                    continue;
                }
                ++de_out[a];
            }
        }
        int zero_scc_cnt = 0;  // 出度为0的连通块的个数
        int result = 0;
        for (int i = 1; i <= scc_cnt; ++i) {
            if (de_out[i]) {
                continue;
            }
            ++zero_scc_cnt;
            result += scc_size[i];  // DAG中，唯一的、出度为0的点是答案
            if (zero_scc_cnt > 1) {
                result = 0;
                break;
            }
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1174_H
