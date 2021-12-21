//
// Created by Fengwei Zhang on 2021/7/27.
//

#ifndef ACWINGSOLUTION_PROBLEM1129_H
#define ACWINGSOLUTION_PROBLEM1129_H

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Problem1129 {
private:
    int Spfa(const int &start, const int &end, const int &n, const vector<vector<pair<int, int>>> &graph) {
        int dist[n + 1];
        bool inQueue[n + 1];
        queue<int> q;
        memset(inQueue, 0, sizeof inQueue);
        memset(dist, 0x3f, sizeof dist);
        q.emplace(start);
        dist[start] = 0;
        inQueue[start] = true;
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            inQueue[root] = false;
            for (auto t: graph[root]) {
                auto nV = t.second;
                if (dist[nV] < dist[root] + t.first) {
                    continue;
                }
                dist[nV] = dist[root] + t.first;
                if (inQueue[nV]) {
                    continue;
                }
                inQueue[nV] = true;
                q.emplace(nV);
            }
        }
        return dist[end];
    }

    int main() {
        int t, c, s, e;
        scanf("%d%d%d%d", &t, &c, &s, &e);
        vector<vector<pair<int, int>>> graph(t + 1, vector<pair<int, int>>());
        int x, y, w;
        for (int i = 0; i < c; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            graph[x].emplace_back(w, y);
            graph[y].emplace_back(w, x);
        }
        printf("%d\n", Spfa(s, e, t, graph));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1129_H
