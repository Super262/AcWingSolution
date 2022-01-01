//
// Created by Fengwei Zhang on 12/27/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1170_H
#define ACWINGSOLUTION_PROBLEM1170_H

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Problem1170 {
    // 1. 题目说明牛的顺序与编号相同，因此 X(i) <= X(i + 1)
    // 2. X(b1) <= X(a1) + L, a1 < b1
    // 3. X(a2) <= X(b2) - D, a2 < b2
    // 为保证所有边被遍历，可以不加思索，添加超级源点X(0)
private:
    const int INF = 0x3f3f3f3f;

    bool Spfa(const int super_st_count, const int n, const vector<vector<pair<int, int>>> &graph, int dist[]) {
        bool in_queue[n + 1];
        int counter[n + 1];
        queue<int> q;
        memset(counter, 0, sizeof counter);
        memset(dist, 0x3f, sizeof(int) * (n + 1));
        memset(in_queue, 0, sizeof in_queue);
        for (int v = 1; v <= super_st_count; ++v) {
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
        int n, ml, md;
        scanf("%d%d%d", &n, &ml, &md);
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 1; i + 1 <= n; ++i) {
            graph[i + 1].emplace_back(0, i);
        }
        for (int i = 0; i < ml; ++i) {
            int a, b, l;
            scanf("%d%d%d", &a, &b, &l);
            if (a > b) {
                swap(a, b);
            }
            graph[a].emplace_back(l, b);
        }
        for (int i = 0; i < md; ++i) {
            int a, b, d;
            scanf("%d%d%d", &a, &b, &d);
            if (a > b) {
                swap(a, b);
            }
            graph[b].emplace_back(-d, a);
        }
        int dist[n + 1];
        if (Spfa(n, n, graph, dist)) {
            printf("%d\n", -1);
        } else {
            Spfa(1, n, graph, dist);
            if (dist[n] == INF) {
                printf("%d\n", -2);
            } else {
                printf("%d\n", dist[n]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1170_H
