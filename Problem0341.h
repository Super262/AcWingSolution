//
// Created by Fengwei Zhang on 2021/7/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0341_H
#define ACWINGSOLUTION_PROBLEM0341_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Problem0341 {
    // https://www.acwing.com/solution/content/3709/ (每个点可被多次经过，当前结果不是最终结果：不能使用Dijkstra算法)
private:
    void Spfa(const int n,
              const bool is_forward,
              const vector<vector<int>> &graph,
              const vector<int> &price,
              vector<int> &result) {
        vector<bool> is_in_queue(n + 1, false);
        queue<int> q;
        if (is_forward) {
            result[1] = price[1];
            is_in_queue[1] = true;
            q.emplace(1);
        } else {
            result[n] = price[n];
            is_in_queue[n] = true;
            q.emplace(n);
        }
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            is_in_queue[root] = false;
            for (const auto &nv: graph[root]) {
                if (is_forward && result[nv] <= min(result[root], price[nv])) {
                    continue;
                }
                if (!is_forward && result[nv] >= max(result[root], price[nv])) {
                    continue;
                }
                if (is_forward) {
                    result[nv] = min(result[root], price[nv]);
                } else {
                    result[nv] = max(result[root], price[nv]);
                }
                if (is_in_queue[nv]) {
                    continue;
                }
                is_in_queue[nv] = true;
                q.emplace(nv);
            }
        }
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> forward_graph(n + 1);
        vector<vector<int>> backward_graph(n + 1);
        vector<int> price(n + 1);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &price[i]);
        }
        for (int i = 1; i <= m; ++i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            forward_graph[a].emplace_back(b);
            backward_graph[b].emplace_back(a);
            if (c == 2) {
                forward_graph[b].emplace_back(a);
                backward_graph[a].emplace_back(b);
            }
        }
        vector<int> min_price_forward(n + 1, 0x3f3f3f3f);
        vector<int> max_price_backward(n + 1, -1);
        Spfa(n, true, forward_graph, price, min_price_forward);
        Spfa(n, false, backward_graph, price, max_price_backward);
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result = max(result, max_price_backward[i] - min_price_forward[i]);
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0341_H
