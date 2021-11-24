//
// Created by Fengwei Zhang on 2021/7/16.
//

#ifndef ACWINGSOLUTION_PROBLEM1073_H
#define ACWINGSOLUTION_PROBLEM1073_H

#include <iostream>
#include <vector>

using namespace std;

class Problem1073 {
    // https://www.acwing.com/solution/content/29249/
    // 向下搜索：用子节点的返回值更新父节点
    // 向上搜索：用父节点的返回值更新子节点
    // 注意：向下搜索的起点可以是任意点，向上搜索的起点必须和向下搜索的起点一致！
private:
    int dfsDown(int root,
                int father,
                const vector<vector<pair<int, int>>> &graph,
                vector<int> &d1,
                vector<int> &d2,
                vector<int> &d1Next) {
        for (const auto &t: graph[root]) {
            if (t.first == father) {
                continue;
            }
            auto d = dfsDown(t.first, root, graph, d1, d2, d1Next) + t.second;
            if (d >= d1[root]) {
                d2[root] = d1[root];
                d1[root] = d;
                d1Next[root] = t.first;
            } else if (d > d2[root]) {
                d2[root] = d;
            }
        }
        return d1[root];
    }

    void dfsUp(int root, int father,
               const vector<vector<pair<int, int>>> &graph,
               vector<int> &d1,
               vector<int> &d2,
               vector<int> &u1,
               vector<int> &d1Next) {
        for (const auto &t: graph[root]) {
            if (t.first == father) {
                continue;
            }
            if (d1Next[root] == t.first) {
                u1[t.first] = max(u1[root], d2[root]) + t.second;
            } else {
                u1[t.first] = max(u1[root], d1[root]) + t.second;
            }
            dfsUp(t.first, root, graph, d1, d2, u1, d1Next);
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
        vector<int> d1(n + 1, 0);
        vector<int> d2(n + 1, 0);
        vector<int> u1(n + 1, 0);
        vector<int> d1Next(n + 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            graph[b].push_back({a, w});
            graph[a].push_back({b, w});
        }
        dfsDown(n, -1, graph, d1, d2, d1Next);
        dfsUp(n, -1, graph, d1, d2, u1, d1Next);
        int result = 0x7f7f7f7f;
        for (int i = 1; i <= n; ++i) {
            result = min(result, max(u1[i], d1[i]));
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1073_H
