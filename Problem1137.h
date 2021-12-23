//
// Created by Fengwei Zhang on 2021/7/30.
//

#ifndef ACWINGSOLUTION_PROBLEM1137_H
#define ACWINGSOLUTION_PROBLEM1137_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Problem1137 {
private:
    int Spfa(const int st, const int ed, const vector<vector<pair<int, int>>> &graph) {
        queue<int> q;
        vector<int> dist(graph.size(), 0x3f3f3f3f);
        vector<bool> is_in_queue(graph.size(), false);
        dist[st] = 0;
        q.emplace(st);
        is_in_queue[st] = true;
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            is_in_queue[root] = false;
            for (const auto &nt: graph[root]) {
                auto nv = nt.second;
                auto nd = nt.first;
                if (dist[nv] <= dist[root] + nd) {
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
        return dist[ed] == 0x3f3f3f3f ? -1 : dist[ed];
    }

    int main() {
        int n, m, s;
        while (scanf("%d%d%d", &n, &m, &s) != -1) {
            vector<vector<pair<int, int>>> graph(n + 1);
            for (int i = 1; i <= m; ++i) {
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                graph[a].emplace_back(c, b);
            }
            int w;
            scanf("%d", &w);
            for (int i = 1; i <= w; ++i) {
                int v;
                scanf("%d", &v);
                graph[0].emplace_back(0, v);
            }
            printf("%d\n", Spfa(0, s, graph));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1137_H
