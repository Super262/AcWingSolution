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
    // f[i][j]：节点i开始向上走 2^j 步所能走到的节点（0 <= j <= logN）
    // depth[i]：编号为i的节点的深度
private:
    const int H = 15;
    const int N = 40000;

    vector<int> bfs(const int root, const vector<vector<int>> &graph, vector<vector<int>> &f) {  // 宽搜不容易爆栈
        queue<int> q;
        vector<int> depth(N + 1, 0x3f3f3f3f);
        depth[0] = 0;  // 哨兵，无效节点，对应f[i][j]的初始值（若f[i][j]越过根结点，我们假设其深度为0）
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
                f[nv][0] = x;
                q.emplace(nv);
                for (int k = 1; k <= H; ++k) {  // 从小到大
                    f[nv][k] = f[f[nv][k - 1]][k - 1];
                }
            }
        }
        return depth;
    }

    int Lca(int a, int b, const vector<int> &depth, const vector<vector<int>> &f) {
        if (depth[a] < depth[b]) {  // 保证a在b之下
            swap(a, b);
        }
        for (auto k = H; k >= 0; --k) {  // 从大到小，找到a、b的同层祖先节点
            if (depth[f[a][k]] < depth[b]) {
                continue;
            }
            a = f[a][k];
        }
        if (a == b) {
            return a;
        }
        for (auto k = H; k >= 0; --k) {  // 从大到小，找到a、b祖先的下层
            if (f[a][k] == f[b][k]) {
                continue;
            }
            a = f[a][k];
            b = f[b][k];
        }
        return f[a][0];
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
        vector<vector<int>> f(N + 1, vector<int>(H + 1, 0));
        auto depth = bfs(root, graph, f);
        int m;
        scanf("%d", &m);
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            auto r = Lca(x, y, depth, f);
            int ans = -1;
            if (r == x) {
                ans = 1;
            } else if (r == y) {
                ans = 2;
            } else {
                ans = 0;
            }
            printf("%d\n", ans);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1172_H
