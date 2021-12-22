//
// Created by Fengwei Zhang on 2021/7/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0340_H
#define ACWINGSOLUTION_PROBLEM0340_H

#include <iostream>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

class Problem0340 {
    // https://www.acwing.com/solution/content/13645/
private:
    int Dijkstra(const int bound,
                 const int st,
                 const int ed,
                 const int n,
                 const vector<vector<pair<int, int>>> &graph) {
        deque<int> q;
        bool selected[n + 1];
        int dist[n + 1];
        memset(selected, 0, sizeof selected);
        memset(dist, 0x3f, sizeof dist);
        dist[st] = 0;
        q.push_front(st);
        while (!q.empty()) {
            auto root = q.front();
            q.pop_front();
            if (selected[root]) {
                continue;
            }
            selected[root] = true;
            for (const auto &nt: graph[root]) {
                auto child = nt.second;
                int w = nt.first > bound ? 1 : 0;
                if (dist[child] <= dist[root] + w) {
                    continue;
                }
                dist[child] = dist[root] + w;
                if (w) {
                    q.push_back(child);
                } else {
                    q.push_front(child);
                }
            }
        }
        return dist[ed];
    }

    int main() {
        int n, p, k;
        scanf("%d%d%d", &n, &p, &k);
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < p; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            graph[a].emplace_back(w, b);
            graph[b].emplace_back(w, a);
        }
        int left = 0, right = 1000001;  // 左端点取0，因为0可能是一个解；右端点取1000001，因为1到N可能不连通
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (Dijkstra(mid, 1, n, n, graph) <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left == 1000001) {
            printf("%d\n", -1);
        } else {
            printf("%d\n", left);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0340_H
