//
// Created by Fengwei Zhang on 2021/7/17.
//

#ifndef ACWINGSOLUTION_PROBLEM1077_H
#define ACWINGSOLUTION_PROBLEM1077_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1077 {
    // https://www.acwing.com/solution/content/13979/
private:
    // 1. dp[i][0]表示第i个节点由父节点处放置的守卫看护下的最小代价
    // 2. dp[i][1]表示第i个节点由子节点处放置的守卫看护下的最小代价
    // 3. dp[i][2]表示第i个节点由在该节点放置的守卫看护下的最小代价
    // 解释：1和3的意义很明显，2的意义代表，如果第i个节点由子节点守卫，那么所有子节点都不能由父节点守卫，
    //      并且每个子节点都得到了守卫，且至少有一个子节点处放置了守卫
    void dfs(const int root, const vector<vector<int>> &graph, const vector<int> &cost, vector<vector<int>> &dp) {
        dp[root][2] = cost[root];
        dp[root][0] = 0;
        int childrenCostSum = 0;
        for (const auto &nextV: graph[root]) {
            dfs(nextV, graph, cost, dp);
            childrenCostSum += min(dp[nextV][1], dp[nextV][2]);
            dp[root][0] += min(dp[nextV][1], dp[nextV][2]);
            dp[root][2] += min(min(dp[nextV][1], dp[nextV][2]), dp[nextV][0]);
        }
        for (const auto &nextV: graph[root]) {  // 枚举在任一点nextV放置守卫时，dp[root][1]的最小值
            dp[root][1] = min(dp[root][1], dp[nextV][2] + childrenCostSum - min(dp[nextV][1], dp[nextV][2]));
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<bool> hasParent(n + 1, false);
        vector<int> cost(n + 1, 0);
        vector<vector<int>> graph(n + 1, vector<int>());
        int v, c, k, u;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &v, &c, &k);
            cost[v] = c;
            for (int j = 0; j < k; ++j) {
                scanf("%d", &u);
                // 单向边即可，无需孩子指向父亲的边：DFS保证先计算子节点的状态，自动维护从孩子节点到父节点的依赖关系
                graph[v].push_back(u);
                hasParent[u] = true;
            }
        }
        int root = 1;
        while (hasParent[root]) {
            ++root;
        }
        vector<vector<int>> dp(n + 1, vector<int>(3, 0x3f3f3f3f));
        dfs(root, graph, cost, dp);
        printf("%d\n", min(dp[root][1], dp[root][2]));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1077_H
