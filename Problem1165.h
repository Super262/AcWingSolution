//
// Created by Fengwei Zhang on 12/26/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1165_H
#define ACWINGSOLUTION_PROBLEM1165_H

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Problem1165 {
    // https://www.acwing.com/solution/content/24634/
    // 注意优化建图方式，减少运算量
private:
    bool Spfa(const vector<vector<pair<int, int>>> &graph, const double mid) {
        const int n = (int) graph.size();
        double dist[n];
        int counter[n];
        bool in_queue[n];
        queue<int> q;
        memset(dist, 0x3f, sizeof dist);
        memset(counter, 0, sizeof counter);
        memset(in_queue, 0, sizeof in_queue);
        for (int v = 0; v < n; ++v) {
            q.emplace(v);
            in_queue[v] = true;
            dist[v] = 0;
        }
        int cnt = 0;
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            in_queue[root] = false;
            for (const auto &nt: graph[root]) {
                auto nv = nt.second;
                auto nd = nt.first;
                if ((dist[root] + mid - nd) - dist[nv] > 1e-4) {
                    continue;
                }
                dist[nv] = dist[root] + mid - nd;
                counter[nv] = counter[root] + 1;
                ++cnt;
                if (cnt > 10000) {
                    return true;  // 经验上的trick
                }
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
        int n;
        while (true) {
            scanf("%d", &n);
            if (n == 0) {
                break;
            }
            vector<vector<pair<int, int>>> graph(676, vector<pair<int, int>>());
            char temp[1010];
            for (int i = 0; i < n; ++i) {
                scanf("%s", temp);
                auto length = strlen(temp);
                if (length < 2) {
                    continue;
                }
                auto u = (temp[0] - 'a') * 26 + (temp[1] - 'a');
                auto v = (temp[length - 2] - 'a') * 26 + (temp[length - 1] - 'a');
                graph[u].emplace_back(length, v);
            }
            if (!Spfa(graph, 0)) {
                printf("No solution\n");
            } else {
                double left = 0, right = 1001;
                while (right - left > 1e-4) {
                    auto mid = left + (right - left) / 2;
                    if (Spfa(graph, mid)) {
                        left = mid;
                    } else {
                        right = mid;
                    }
                }
                printf("%lf\n", right);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1165_H
