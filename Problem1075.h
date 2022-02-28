//
// Created by Fengwei Zhang on 2021/7/16.
//

#ifndef ACWINGSOLUTION_PROBLEM1075_H
#define ACWINGSOLUTION_PROBLEM1075_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Problem1075 {
    // 求森林中的最大直径
    // https://www.acwing.com/solution/content/8015/
private:
    int dfs(int u, int p, const vector<vector<int>> &g, bool visited[], int &ans) {
        visited[u] = true;
        int d1 = 0;
        int d2 = 0;
        for (const auto &v: g[u]) {
            if (v == p) {
                continue;
            }
            auto n1 = dfs(v, u, g, visited, ans) + 1;
            if (n1 >= d1) {
                d2 = d1;
                d1 = n1;
            } else if (n1 > d2) {
                d2 = n1;
            }
        }
        ans = max(ans, d1 + d2);
        return d1;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int divs_sum[n + 1];
        memset(divs_sum, 0, sizeof divs_sum);
        for (int a = 1; a <= n; ++a) {  // 时间复杂度：O(nlogn)
            // 避免溢出，不使用“a * b <= n”
            // b不从1开始，避免累加自身（n）到因子和中
            for (int b = 2; b <= n / a; ++b) {
                divs_sum[a * b] += a;
            }
        }
        vector<vector<int>> g(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (divs_sum[i] >= i) {
                continue;
            }
            g[divs_sum[i]].push_back(i);  // 添加单向边！
        }
        bool visited[n + 1];
        int ans = 0;
        memset(visited, 0, sizeof visited);
        for (int u = 1; u <= n; ++u) {  // 本题可能包含多棵树，因此需要尝试以每个点为根的树
            if (visited[u] || g[u].empty()) {
                continue;
            }
            dfs(u, -1, g, visited, ans);
        }
        printf("%d\n", ans);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1075_H
