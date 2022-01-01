//
// Created by Fengwei Zhang on 12/27/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0362_H
#define ACWINGSOLUTION_PROBLEM0362_H

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Problem0362 {
    // https://www.acwing.com/solution/content/8205/
    // 在定义约束后，一定要验算，保证条件足够；同时，找到超级源点
    // S(i)：区间[0, i]中被选择的数的个数
    // 1. S(i) >= S(i - 1)
    // 2. S(b) - S(a - 1) >= c
    // 3. S(i) - S(i - 1) <= 1
    // 由于输入的区间的某个端点可能为0，我们调整区间的最小起点为1，数据范围变成[1, 50001]
private:
    int Spfa(const int n, const vector<vector<pair<int, int>>> &graph) {
        int dist[n + 1];
        bool in_queue[n + 1];
        queue<int> q;
        memset(dist, -0x3f, sizeof dist);
        memset(in_queue, 0, sizeof in_queue);
        dist[0] = 0;  // S(0) = 0
        q.emplace(0);
        in_queue[0] = true;
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            in_queue[root] = false;
            for (const auto &nt: graph[root]) {
                auto nv = nt.second;
                auto nd = nt.first;
                if (dist[nv] >= dist[root] + nd) {
                    continue;
                }
                dist[nv] = dist[root] + nd;
                if (in_queue[nv]) {
                    continue;
                }
                in_queue[nv] = true;
                q.emplace(nv);
            }
        }
        return dist[n];
    }

    int main() {
        const int m = 50001;
        vector<vector<pair<int, int>>> graph(m + 1);
        for (int i = 1; i <= m; ++i) {
            graph[i - 1].emplace_back(0, i);
            graph[i].emplace_back(-1, i - 1);
        }
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            ++a;
            ++b;
            graph[a - 1].emplace_back(c, b);
        }
        printf("%d\n", Spfa(m, graph));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0362_H
