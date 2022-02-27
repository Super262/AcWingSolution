//
// Created by Fengwei Zhang on 2021/7/16.
//

#ifndef ACWINGSOLUTION_PROBLEM1075_H
#define ACWINGSOLUTION_PROBLEM1075_H

#include <iostream>
#include <vector>

using namespace std;

class Problem1075 {
    // 求森林中的最大直径
    // https://www.acwing.com/solution/content/8015/
private:
    int downMax(int root, int father, int &answer, const vector<vector<int>> &graph, vector<bool> &visited) {
        visited[root] = true;
        int d1 = 0, d2 = 0;
        for (const auto &t: graph[root]) {
            if (t == father) {
                continue;
            }
            auto d = downMax(t, root, answer, graph, visited) + 1;
            if (d >= d1) {
                d2 = d1;
                d1 = d;
            } else if (d > d2) {
                d2 = d;
            }
        }
        answer = max(answer, d1 + d2);
        return d1;
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<int> divs_sum(n + 1, 0);
        for (int a = 1; a <= n; ++a) {  // 时间复杂度：O(nlogn)
            // 避免溢出，不使用“a * b <= n”
            // b不从1开始，避免累加自身（n）到因子和中
            for (int b = 2; b <= n / a; ++b) {
                divs_sum[a * b] += a;
            }
        }
        vector<vector<int>> graph(n + 1, vector<int>());
        for (int i = 1; i <= n; ++i) {
            if (i < divs_sum[i]) {
                continue;
            }
            // 添加双向边
            graph[i].push_back(divs_sum[i]);
            graph[divs_sum[i]].push_back(i);
        }
        int answer = 0;
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; ++i) {  // 本题可能包含多棵树，因此需要尝试以每个点为根的树
            if (graph[i].empty() || visited[i]) {
                continue;
            }
            // 遍历所有可能的根结点（数、因数和）
            // 不要忘记传入visited！
            downMax(i, -1, answer, graph, visited);
        }
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1075_H
