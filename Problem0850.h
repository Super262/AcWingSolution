//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0850_H
#define ACWINGSOLUTION_PROBLEM0850_H

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Problem0850 {
private:
    int dijkstra(const int st, const int ed, const int n, const vector<vector<pair<int, int>>> &graph) {
        int dist[n + 1];
        bool selected[n + 1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        memset(dist, 0x3f, sizeof dist);
        memset(selected, 0, sizeof selected);
        dist[st] = 0;
        heap.push({dist[st], st});
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto rv = t.second;
            if (selected[rv]) {
                continue;
            }
            selected[rv] = true;
            for (const auto &nt: graph[rv]) {
                auto nv = nt.second;
                auto nd = nt.first;
                if (dist[nv] < dist[rv] + nd) {
                    continue;
                }
                dist[nv] = dist[rv] + nd;
                heap.push({dist[nv], nv});
            }
        }
        if (dist[ed] == 0x3f3f3f3f) {
            return -1;
        }
        return dist[ed];
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
        printf("%d\n", dijkstra(1, n, n, graph));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0850_H
