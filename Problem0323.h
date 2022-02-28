//
// Created by Fengwei Zhang on 2021/7/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0323_H
#define ACWINGSOLUTION_PROBLEM0323_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0323 {
    // 保证所有边至少有1个顶点被选择：f[u][0]表示不在u放置士兵，f[u][1]表示在u放置士兵
    // https://www.acwing.com/solution/content/66365/
private:
    void dfs(const int u, const vector<vector<int>> &g, vector<vector<int>> &f) {
        f[u][0] = 0;
        f[u][1] = 1;
        for (const auto &v: g[u]) {
            dfs(v, g, f);
            f[u][0] += f[v][1];
            f[u][1] += min(f[v][1], f[v][0]);
        }
    }

    int main() {
        int n;
        while (cin >> n) {
            vector<vector<int>> g(n + 1, vector<int>());
            vector<bool> has_father(n + 1, false);
            for (int i = 0; i < n; ++i) {
                int r, m;
                scanf("%d:(%d) ", &r, &m);
                for (int j = 0; j < m; ++j) {
                    int b;
                    scanf("%d", &b);
                    g[r].push_back(b);  // 所有边是单向边
                    has_father[b] = true;
                }
            }
            int root = 0;
            while (has_father[root]) {
                ++root;
            }
            vector<vector<int>> f(n + 1, vector<int>(2, 0));
            dfs(root, g, f);
            printf("%d\n", min(f[root][0], f[root][1]));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0323_H
