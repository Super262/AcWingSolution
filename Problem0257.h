//
// Created by Fengwei Zhang on 1/3/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0257_H
#define ACWINGSOLUTION_PROBLEM0257_H

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Problem0257 {
    // 二分 + 染色法判断二分图：https://www.acwing.com/solution/content/3042/
private:
    bool Dfs(const int u, const int limit, const int c, const vector<vector<pair<int, int>>> &graph, int color[]) {
        color[u] = c;
        for (const auto &nt: graph[u]) {
            if (nt.first <= limit) {  // 只有大于limit的边被视为横跨边
                continue;
            }
            auto v = nt.second;
            if (color[v]) {
                if (color[v] == c) {
                    return false;
                }
            } else if (!Dfs(v, limit, 3 - c, graph, color)) {
                return false;
            }
        }
        return true;
    }

    bool Check(const int n, const int limit, int color[], const vector<vector<pair<int, int>>> &graph) {
        memset(color, 0, sizeof(int) * (n + 1));
        for (int v = 1; v <= n; ++v) {
            if (color[v]) {
                continue;
            }
            if (!Dfs(v, limit, 1, graph, color)) {
                return false;
            }
        }
        return true;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<pair<int, int>>> graph(n + 1);
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            graph[a].emplace_back(c, b);
            graph[b].emplace_back(c, a);
        }
        int color[n + 1];
        int left = 0, right = 1000000000;
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (Check(n, mid, color, graph)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        printf("%d\n", right);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0257_H
