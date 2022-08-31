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
    // 状压DP求解"最小生成树"；f[i][j]表示生成树是i（二进制状态），深度是j
    // 求二进制状态s的子集p：for (auto p = (s - 1) & s; p; p = (p - 1) & s)
    // https://www.acwing.com/solution/content/59439/
private:
    static const int INF = 0x3f3f3f3f;

    vector<int> buildNext(const vector<vector<int>> &graph, const int n) {
        // 预处理所有状态能够扩展一层后得到的最大的下一层状态
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
        // 计算pre转移到cur的代价
        if ((ne[pre] & cur) != cur) {  // 无法延伸，直接剪枝
            return -1;
        }
        auto remains = pre ^ cur;  // 发生变化的点
        int cost = 0;
        for (int v = 0; v < n; ++v) {
            if (!((remains >> v) & 1)) {
                continue;
            }
            int t = 500000;  // 题意中有效的最大边长为5e5
            for (int u = 0; u < n; ++u) {  // 找出当前连通块内能把该点加入所用的最小边的边长
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
            f[1 << u][0] = 0;  // 开局免费选一个起点（初始状态）
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
            res = min(res, f[(1 << n) - 1][d]);  // 目标状态中找最优解
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
