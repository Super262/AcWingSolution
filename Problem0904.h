//
// Created by Fengwei Zhang on 12/26/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0904_H
#define ACWINGSOLUTION_PROBLEM0904_H

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Problem0904 {
    // 将虫洞看作负权边，用SPFA判断负环
private:
    bool Spfa(const vector<vector<pair<int, int>>> &graph) {
        const auto n = (int) graph.size() - 1;
        int counter[n + 1];
        int dist[n + 1];
        bool in_queue[n + 1];
        queue<int> q;
        memset(counter, 0, sizeof counter);
        memset(dist, 0, sizeof dist);
        memset(in_queue, 0, sizeof in_queue);
        for (int v = 1; v <= n; ++v) {
            dist[v] = 0;
            q.emplace(v);
            in_queue[v] = true;
        }
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            in_queue[root] = false;
            for (const auto &nt: graph[root]) {
                auto nv = nt.second;
                auto nd = nt.first;
                if (dist[nv] <= dist[root] + nd) {
                    continue;
                }
                dist[nv] = dist[root] + nd;
                counter[nv] = counter[root] + 1;
                if (counter[nv] >= n) {
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
        int f;
        scanf("%d", &f);
        while (f--) {
            int n, m, w;
            scanf("%d%d%d", &n, &m, &w);
            vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
            for (int i = 0; i < m; ++i) {
                int s, e, t;
                scanf("%d%d%d", &s, &e, &t);
                graph[s].emplace_back(t, e);
                graph[e].emplace_back(t, s);
            }
            for (int i = 0; i < w; ++i) {
                int s, e, t;
                scanf("%d%d%d", &s, &e, &t);
                graph[s].emplace_back(-t, e);
            }
            if (Spfa(graph)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0904_H
