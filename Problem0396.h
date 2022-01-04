//
// Created by Fengwei Zhang on 1/3/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0396_H
#define ACWINGSOLUTION_PROBLEM0396_H

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Problem0396 {
    // 1. 出口数量 res >= 2
    // 2. 对每个连通块，(1) 若无割点，则任选2个点作为出口，方案数为 cnt * (cnt - 1) / 2，cnt为连通块中点的数量；
    //  (2) 有割点，需要"缩点"；需要注意的是，每个割点至少属于2个V-DCC；
    //      步骤：把每个割点单独作为1个点；从每个V-DCC向其所包含的每个割点连边，统计每个V-DCC的度数；
    //           若某个V-DCC的度数为1，说明它只有1个割点，我们要在该V-DCC的内部设置1个出口
    //           若某个V-DCC的度数大于1，说明它有多个割点，我们无需在该V-DCC的内部设置出口
private:
    void Tarjan(const int u,
                const int root,
                const vector<vector<int>> &graph,
                vector<vector<int>> &vdcc,
                stack<int> &stk,
                int disc[],
                int low[],
                bool is_cut[],
                int &time_stamp,
                int &vdcc_cnt) {
        ++time_stamp;
        disc[u] = time_stamp;
        low[u] = time_stamp;
        stk.emplace(u);
        if (u == root && graph[u].empty()) {  // u是孤立点，本身是V-DCC
            ++vdcc_cnt;
            vdcc[vdcc_cnt].emplace_back(u);
            return;
        }
        int cnt = 0;  // 当前子树的分枝数
        for (const auto &v: graph[u]) {
            if (!disc[v]) {
                Tarjan(v, root, graph, vdcc, stk, disc, low, is_cut, time_stamp, vdcc_cnt);
                low[u] = min(low[u], low[v]);
                if (disc[u] <= low[v]) {  // 开始寻找V-DCC的时机
                    ++cnt;
                    if (u != root || cnt > 1) {  // 割点：不是根结点，有分枝
                        is_cut[u] = true;
                    }
                    ++vdcc_cnt;
                    int y;
                    do {
                        y = stk.top();
                        stk.pop();
                        vdcc[vdcc_cnt].emplace_back(y);
                    } while (y != v);
                    vdcc[vdcc_cnt].emplace_back(u);  // 不要忘记啊，u也属于这个V-DCC
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    int main() {
        const int N = 1000;
        int low[N + 1];
        int disc[N + 1];
        bool is_cut[N + 1];
        vector<vector<int>> graph(N + 1);
        vector<vector<int>> vdcc(N + 1);
        int t = 1;
        while (true) {
            for (int i = 0; i <= N; ++i) {
                graph[i].clear();
                vdcc[i].clear();
            }
            int m;
            scanf("%d", &m);
            if (m == 0) {
                break;
            }
            int n = 1;
            while (m--) {
                int a, b;
                scanf("%d%d", &a, &b);
                n = max(n, max(a, b));
                graph[a].emplace_back(b);
                graph[b].emplace_back(a);
            }
            memset(disc, 0, sizeof disc);
            memset(low, 0, sizeof low);
            memset(is_cut, 0, sizeof is_cut);
            int time_stamp = 0;
            int vdcc_cnt = 0;
            stack<int> stk;
            for (int root = 1; root <= n; ++root) {
                if (disc[root]) {
                    continue;
                }
                Tarjan(root, root, graph, vdcc, stk, disc, low, is_cut, time_stamp, vdcc_cnt);
            }
            int res = 0;
            unsigned long long num = 1;
            for (int i = 1; i <= vdcc_cnt; ++i) {
                int cnt = 0;
                for (const auto &v: vdcc[i]) {
                    if (is_cut[v]) {
                        ++cnt;
                    }
                }
                if (cnt == 0) {
                    if (vdcc[i].size() > 1) {
                        res += 2;
                        num *= vdcc[i].size() * (vdcc[i].size() - 1) / 2;
                    } else {
                        ++res;
                    }
                } else if (cnt == 1) {
                    ++res;
                    num *= vdcc[i].size() - 1;
                }
            }
            printf("Case %d: %d %llu\n", t, res, num);
            ++t;
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0396_H
