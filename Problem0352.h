//
// Created by Fengwei Zhang on 1/8/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0352_H
#define ACWINGSOLUTION_PROBLEM0352_H

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Problem0352 {
    // LCA + 树上差分：https://www.acwing.com/solution/content/4090/
private:
    static const int H = 16;

    void Bfs(const vector<int> graph[], int depth[], int father[][H + 1]) {
        queue<int> q;
        depth[0] = 0;
        depth[1] = 1;
        q.emplace(1);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (const auto &v: graph[u]) {
                if (depth[v] <= depth[u] + 1) {
                    continue;
                }
                depth[v] = depth[u] + 1;
                q.emplace(v);
                father[v][0] = u;
                for (int k = 1; k <= H; ++k) {
                    father[v][k] = father[father[v][k - 1]][k - 1];
                }
            }
        }
    }

    int Lca(int a, int b, const vector<int> graph[], const int depth[], int father[][H + 1]) {
        if (depth[a] < depth[b]) {
            swap(a, b);
        }
        for (int k = H; k >= 0; --k) {
            if (depth[father[a][k]] < depth[b]) {
                continue;
            }
            a = father[a][k];
        }
        if (a == b) {
            return a;
        }
        for (int k = H; k >= 0; --k) {
            if (father[a][k] == father[b][k]) {
                continue;
            }
            a = father[a][k];
            b = father[b][k];
        }
        return father[a][0];
    }

    int Dfs(const int u, const int p, const int m, const vector<int> graph[], const int diff[], int &answer) {
        int res = diff[u];
        for (const int &v: graph[u]) {
            if (v == p) {
                continue;
            }
            auto s = Dfs(v, u, m, graph, diff, answer);
            if (s == 1) {
                ++answer;
            } else if (s == 0) {
                answer += m;
            }
            res += s;
        }
        return res;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> graph[n + 1];
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
        int depth[n + 1];
        int father[n + 1][H + 1];
        int diff[n + 1];
        memset(depth, 0x3f, sizeof depth);
        memset(father, 0, sizeof father);
        memset(diff, 0, sizeof diff);
        Bfs(graph, depth, father);
        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            ++diff[x];
            ++diff[y];
            diff[Lca(x, y, graph, depth, father)] -= 2;
        }
        int answer = 0;
        Dfs(1, -1, m, graph, diff, answer);
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0352_H
