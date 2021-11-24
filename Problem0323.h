//
// Created by Fengwei Zhang on 2021/7/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0323_H
#define ACWINGSOLUTION_PROBLEM0323_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0323 {
    // 保证所有边至少有1个顶点被选择
    // https://www.acwing.com/solution/content/66365/
private:
    void dfs(const int root, const vector<vector<int>> &graph, vector<vector<int>> &dp) {
        dp[root][0] = 0;
        dp[root][1] = 1;
        for (const auto &nextV: graph[root]) {
            dfs(nextV, graph, dp);
            dp[root][0] += dp[nextV][1];
            dp[root][1] += min(dp[nextV][1], dp[nextV][0]);
        }
    }

    int main() {
        int n;
        while (cin >> n) {
            vector<vector<int>> graph(n + 1, vector<int>());
            vector<bool> hasFather(n + 1, false);
            for (int i = 0; i < n; ++i) {
                int r, m;
                scanf("%d:(%d) ", &r, &m);
                for (int j = 0; j < m; ++j) {
                    int b;
                    scanf("%d", &b);
                    graph[r].push_back(b);  // 所有边是单向边
                    hasFather[b] = true;
                }
            }
            int root = 0;
            while (hasFather[root]) {
                ++root;
            }
            vector<vector<int>> dp(n + 1, vector<int>(2, 0));
            dfs(root, graph, dp);
            printf("%d\n", min(dp[root][0], dp[root][1]));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0323_H
