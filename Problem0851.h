//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0851_H
#define ACWINGSOLUTION_PROBLEM0851_H

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Problem0851 {
private:
    int spfa(int st, int ed, int n, const vector<vector<pair<int, int>>> &graph) {
        int dist[n + 1];
        bool is_in_queue[n + 1];
        queue<int> q;
        memset(dist, 0x3f, sizeof dist);
        memset(is_in_queue, 0, sizeof is_in_queue);
        dist[st] = 0;
        q.emplace(st);
        is_in_queue[st] = true;
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            is_in_queue[root] = false;
            for (const auto &e: graph[root]) {
                auto nv = e.second;
                auto nd = e.first;
                if (dist[nv] < dist[root] + nd) {
                    continue;
                }
                dist[nv] = dist[root] + nd;
                if (is_in_queue[nv]) {
                    continue;
                }
                q.emplace(nv);
                is_in_queue[nv] = true;
            }
        }
        return dist[ed];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
        int x, y, z;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &z);
            graph[x].push_back({z, y});
        }
        auto res = spfa(1, n, n, graph);
        if (res == 0x3f3f3f3f) {
            printf("impossible\n");
        } else {
            printf("%d\n", res);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0851_H
