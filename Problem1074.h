//
// Created by Fengwei Zhang on 2021/7/16.
//

#ifndef ACWINGSOLUTION_PROBLEM1074_H
#define ACWINGSOLUTION_PROBLEM1074_H

#include <iostream>
#include <vector>

using namespace std;

class Problem1074 {
    // 分组背包 + 树形DP：https://www.acwing.com/solution/content/10714/
    // f[i][m]：以i为根，保留m个树枝时的最多苹果
private:
    void dfs(int u, int p, int m, const vector<vector<pair<int, int>>> &graph, vector<vector<int>> &f) {
        for (const auto &t: graph[u]) {
            auto v = t.first;
            if (v == p) {
                continue;
            }
            dfs(v, u, m, graph, f);
            for (int j = m; j >= 0; --j) {  // 循环体积
                for (int k = 0; k < j; ++k) {  // 循环决策（这里k不能等于j！）
                    // 不要忘记是j - k - 1，不是j - k，要减去到子结点的边（树枝）
                    f[u][j] = max(f[u][j], f[u][j - k - 1] + t.second + f[v][k]);
                }
            }
        }
    }

    int main() {
        int n, q;
        scanf("%d%d", &n, &q);
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
        vector<vector<int>> f(n + 1, vector<int>(q + 1, 0));
        for (int i = 0; i < n - 1; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            graph[a].push_back({b, w});  // 由于我们并不清楚树的形状，所以这里使用双向边
            graph[b].push_back({a, w});
        }
        dfs(1, -1, q, graph, f);
        printf("%d\n", f[1][q]);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1074_H
