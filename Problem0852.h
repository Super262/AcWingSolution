//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0852_H
#define ACWINGSOLUTION_PROBLEM0852_H

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Problem0852 {
    // 1. 虚拟源点
    // 2. 最短路径经过的边数大于等于n，有负环
private:
    bool spfa(const int n, const vector<vector<pair<int, int>>> &graph) {
        int dist[n + 1];
        bool in_queue[n + 1];
        int edges_cnt[n + 1];
        queue<int> q;
        memset(dist, 0x3f, sizeof dist);
        memset(in_queue, 0, sizeof in_queue);
        memset(edges_cnt, 0, sizeof edges_cnt);
        for (int v = 1; v <= n; ++v) {
            q.emplace(v);
            dist[v] = 0;
            in_queue[v] = true;
        }
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            in_queue[root] = false;
            for (const auto &t: graph[root]) {
                auto nd = t.first;
                auto nv = t.second;
                if (dist[nv] <= dist[root] + nd) {
                    continue;
                }
                dist[nv] = dist[root] + nd;
                edges_cnt[nv] = edges_cnt[root] + 1;
                if (edges_cnt[nv] >= n) {
                    return true;
                }
                if (in_queue[nv]) {
                    continue;
                }
                q.emplace(nv);
                in_queue[nv] = true;
            }
        }
        return false;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
        int u, v, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            graph[u].push_back({w, v});
        }
        if (spfa(n, graph)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0852_H
