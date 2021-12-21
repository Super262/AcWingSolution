//
// Created by Fengwei Zhang on 2021/7/27.
//

#ifndef ACWINGSOLUTION_PROBLEM1127_H
#define ACWINGSOLUTION_PROBLEM1127_H

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Problem1127 {
private:
    int DijkstraSum(const int &start,
                    const int &p,
                    const vector<int> &home,
                    const vector<vector<pair<int, int>>> &graph) {
        int dist[p + 1];
        bool selected[p + 1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        memset(dist, 0x3f, sizeof dist);
        memset(selected, 0, sizeof selected);
        dist[start] = 0;
        heap.emplace(pair<int, int>(dist[start], start));
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto root = t.second;
            if (selected[root]) {
                continue;
            }
            selected[root] = true;
            for (const auto &nt: graph[root]) {
                auto nv = nt.second;
                auto nd = nt.first;
                if (dist[nv] < dist[root] + nd) {
                    continue;
                }
                dist[nv] = dist[root] + nd;
                heap.emplace(pair<int, int>(dist[nv], nv));
            }
        }
        int result = 0;
        for (const auto &x: home) {
            if (dist[x] == 0x3f3f3f3f) {
                return 0x3f3f3f3f;
            }
            result += dist[x];
        }
        return result;
    }

    int main() {
        int n, p, c;
        scanf("%d%d%d", &n, &p, &c);
        vector<vector<pair<int, int>>> graph(p + 1, vector<pair<int, int>>());
        vector<int> home(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &home[i]);
        }
        int x, y, w;
        int idx = 0;
        for (int i = 0; i < c; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            graph[x].emplace_back(w, y);
            graph[y].emplace_back(w, x);
        }
        int result = 0x3f3f3f3f;
        for (int i = 1; i <= p; ++i) {
            result = min(result, DijkstraSum(i, p, home, graph));
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1127_H
