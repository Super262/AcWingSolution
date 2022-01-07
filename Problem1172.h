//
// Created by Fengwei Zhang on 1/6/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1172_H
#define ACWINGSOLUTION_PROBLEM1172_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Problem1172 {
    // https://www.acwing.com/solution/content/20554/
private:
    const int H = 15;
    const int N = 40000;

    vector<int> Bfs(const int root, const vector<vector<int>> &graph, vector<vector<int>> &dp) {  // 宽搜不容易爆栈
        queue<int> q;
        vector<int> depth(N + 1, 0x3f3f3f3f);
        depth[0] = 0;  // 哨兵，无效节点
        depth[root] = 1;
        q.emplace(root);
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (const auto &nv: graph[x]) {
                if (depth[nv] <= depth[x] + 1) { // 说明nv被搜索过
                    continue;
                }
                depth[nv] = depth[x] + 1;
                dp[nv][0] = x;
                q.emplace(nv);
                for (int k = 1; k <= H; ++k) {  // 从小到大
                    dp[nv][k] = dp[dp[nv][k - 1]][k - 1];
                }
            }
        }
        return depth;
    }

    int Lca(int a, int b, const vector<int> &depth, const vector<vector<int>> &dp) {
        if (depth[a] < depth[b]) {  // 保证a在b之下
            swap(a, b);
        }
        for (int k = H; k >= 0; --k) {  // 从大到小，找到a、b的同层祖先节点
            if (depth[dp[a][k]] < depth[b]) {
                continue;
            }
            a = dp[a][k];
        }
        if (a == b) {
            return a;
        }
        for (int k = H; k >= 0; --k) {  // 从大到小，找到a、b祖先的下层
            if (dp[a][k] == dp[b][k]) {
                continue;
            }
            a = dp[a][k];
            b = dp[b][k];
        }
        return dp[a][0];
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<vector<int>> graph(N + 1);
        int root = -1;
        for (int i = 0; i < n; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            if (b == -1) {
                root = a;
                continue;
            }
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
        vector<vector<int>> dp(N + 1, vector<int>(H + 1, 0));
        auto depth = Bfs(root, graph, dp);
        int m;
        scanf("%d", &m);
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            auto r = Lca(x, y, depth, dp);
            int result = -1;
            if (r == x) {
                result = 1;
            } else if (r == y) {
                result = 2;
            } else {
                result = 0;
            }
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1172_H
