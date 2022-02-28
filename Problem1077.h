//
// Created by Fengwei Zhang on 2021/7/17.
//

#ifndef ACWINGSOLUTION_PROBLEM1077_H
#define ACWINGSOLUTION_PROBLEM1077_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Problem1077 {
    // https://www.acwing.com/solution/content/13979/
private:
    // 1. f[i][0]表示第i个节点由父节点处放置的守卫看护下的最小代价
    // 2. f[i][1]表示第i个节点由子节点处放置的守卫看护下的最小代价
    // 3. f[i][2]表示第i个节点由在该节点放置的守卫看护下的最小代价
    // f[i][s]表示整个子树的花费
    // 解释：1和3的意义很明显，2的意义代表，如果第i个节点由子节点守卫，那么所有子节点都不能由父节点守卫，
    //      并且每个子节点都得到了守卫，且至少有一个子节点处放置了守卫
    void dfs(const int u, const vector<vector<int>> &g, const vector<int> &cost, vector<vector<int>> &f) {
        f[u][2] = cost[u];
        f[u][0] = 0;
        int kids_cost = 0;
        for (const auto &v: g[u]) {
            dfs(v, g, cost, f);
            kids_cost += min(f[v][1], f[v][2]);
            f[u][0] += min(f[v][1], f[v][2]);
            f[u][2] += min(min(f[v][1], f[v][2]), f[v][0]);
        }
        for (const auto &v: g[u]) {  // 枚举在任一子结点v放置守卫时，f[u][1]的最小值
            f[u][1] = min(f[u][1], f[v][2] + kids_cost - min(f[v][1], f[v][2]));
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<bool> has_parent(n + 1, false);
        vector<int> cost(n + 1, 0);
        vector<vector<int>> g(n + 1, vector<int>());
        int v, c, k, u;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &v, &c, &k);
            cost[v] = c;
            for (int j = 0; j < k; ++j) {
                scanf("%d", &u);
                // 单向边即可，无需孩子指向父亲的边：DFS保证先计算子节点的状态，自动维护从孩子节点到父节点的依赖关系
                g[v].push_back(u);
                has_parent[u] = true;
            }
        }
        int root = 1;
        while (has_parent[root]) {
            ++root;
        }
        vector<vector<int>> f(n + 1, vector<int>(3, 0x3f3f3f3f));
        dfs(root, g, cost, f);
        printf("%d\n", min(f[root][1], f[root][2]));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1077_H
