//
// Created by Fengwei Zhang on 12/26/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0361_H
#define ACWINGSOLUTION_PROBLEM0361_H

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Problem0361 {
    // https://www.acwing.com/solution/content/6472/
    // 注意浮点数的正确比较：做差，不能用等于号
private:
    bool Spfa(const vector<int> &vertex_weight, const vector<vector<pair<int, int>>> &graph, const double mid) {
        const auto n = (int) vertex_weight.size() - 1;
        bool in_queue[n + 1];
        double dist[n + 1];
        int counter[n + 1];
        queue<int> q;
        memset(in_queue, 0, sizeof in_queue);
        memset(dist, 0x3f, sizeof dist);
        memset(counter, 0, sizeof counter);
        for (int v = 1; v <= n; ++v) {
            in_queue[v] = true;
            q.emplace(v);
            dist[v] = 0;
        }
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            in_queue[root] = false;
            for (const auto &t: graph[root]) {
                auto nv = t.second;
                auto nd = t.first * mid - vertex_weight[root];
                if (dist[root] + nd - dist[nv] > 1e-4) {
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
                in_queue[nv] = true;
                q.emplace(nv);
            }
        }
        return false;
    }

    int main() {
        int l, p;
        scanf("%d%d", &l, &p);
        vector<int> vertex_weight(l + 1);
        vector<vector<pair<int, int>>> graph(l + 1, vector<pair<int, int>>());
        for (int i = 1; i <= l; ++i) {
            int w;
            scanf("%d", &w);
            vertex_weight[i] = w;
        }
        for (int i = 0; i < p; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            graph[u].emplace_back(w, v);
        }
        double left = 0, right = 1000;
        while (right - left > 1e-4) {
            auto mid = left + (right - left) / 2;
            if (Spfa(vertex_weight, graph, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        printf("%.2lf\n", right);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0361_H
