//
// Created by Fengwei Zhang on 2021/7/12.
//

#ifndef ACWINGSOLUTION_PROBLEM0010_H
#define ACWINGSOLUTION_PROBLEM0010_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


class Problem0010 {
    // dp[r][v]：物品体积不超过v时，选择根结点为r的最大价值
private:
    struct Item {
        int v, w;
    };

    void knapsack(const vector<Item> &items,
                  const int m,
                  const int root,
                  vector<vector<int>> &dp,
                  const vector<vector<int>> &graph) {
        for (auto son: graph[root]) {  // 循环物品组
            knapsack(items, m, son, dp, graph);
            for (int j = m - items[root].v; j >= 0; --j) {  // 循环体积
                // 遍历所有可能方案：暂时不选择根结点时的方案
                for (int child_v = 0; child_v <= j; ++child_v) {  // 循环决策
                    dp[root][j] = max(dp[root][j], dp[root][j - child_v] + dp[son][child_v]);
                }
            }
        }
        // 将根结点加入背包
        for (int j = m; j >= items[root].v; --j) {
            dp[root][j] = dp[root][j - items[root].v] + items[root].w;
        }
        // 当背包容量小于根结点体积时，无法向背包中加入任何物品
        for (int j = items[root].v - 1; j >= 0; --j) {
            dp[root][j] = 0;
        }
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<Item> items(n + 1);
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> graph(n + 1, vector<int>());  // 注意：这里只保存单向边（父->子）
        int root = 0;
        for (int i = 1; i <= n; ++i) {
            int t;
            scanf("%d%d%d", &items[i].v, &items[i].w, &t);
            if (t == -1) {
                root = i;
            } else {
                graph[t].emplace_back(i);
            }
        }
        knapsack(items, m, root, dp, graph);
        printf("%d\n", dp[root][m]);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0010_H
