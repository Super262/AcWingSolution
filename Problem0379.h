//
// Created by Fengwei Zhang on 1/4/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0379_H
#define ACWINGSOLUTION_PROBLEM0379_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Problem0379 {
    // 1. 二分图、不存在奇数环、染色法不存在矛盾
    // 2. 匈牙利算法：匹配、最大匹配、匹配点、增广路径
    // 3. 最小点覆盖、最大独立集、最小路径点覆盖（最小路径重复点覆盖）
    //    最大匹配数 = 最小点覆盖 = 总点数 - 最大独立集 = 总点数 - 最小路径点覆盖
    // 最小路径重复点覆盖：https://www.acwing.com/solution/content/15162/
private:
    void Floyd(const int n, vector<vector<bool>> &graph) {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    graph[i][j] = graph[i][j] || (graph[i][k] & graph[k][j]);
                }
            }
        }
    }

    bool HasMatched(const int u, const int n, const vector<vector<bool>> &graph, bool visited[], int matched_idx[]) {
        for (int v = 1; v <= n; ++v) {
            if (!graph[u][v]) {
                continue;
            }
            if (visited[v]) {
                continue;
            }
            visited[v] = true;
            if (!matched_idx[v] || HasMatched(matched_idx[v], n, graph, visited, matched_idx)) {
                matched_idx[v] = u;
                return true;
            }
        }
        return false;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            graph[x][y] = true;
        }
        Floyd(n, graph);
        int cnt = 0;
        bool visited[n + 1];
        int matched_idx[n + 1];
        memset(matched_idx, 0, sizeof matched_idx);
        for (int v = 1; v <= n; ++v) {
            memset(visited, 0, sizeof visited);
            if (HasMatched(v, n, graph, visited, matched_idx)) {
                ++cnt;
            }
        }
        printf("%d\n", n - cnt);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0379_H
