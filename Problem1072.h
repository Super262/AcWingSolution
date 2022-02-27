//
// Created by Fengwei Zhang on 2021/7/16.
//

#ifndef ACWINGSOLUTION_PROBLEM1072_H
#define ACWINGSOLUTION_PROBLEM1072_H

#include <iostream>
#include <vector>

using namespace std;

class Problem1072 {
    // 任取一点为起点，找到距离该点最远的点u
    // 找到距离u最远的点v；u和v间的距离即为直径
private:
    int treeModel(const int root, const int father, const vector<vector<pair<int, int>>> &graph, int &answer) {
        int d1 = 0;
        int d2 = 0;
        for (auto t: graph[root]) {
            if (t.first == father) {
                continue;
            }
            auto child_d1 = treeModel(t.first, root, graph, answer) + t.second;
            if (child_d1 >= d1) {
                d2 = d1;
                d1 = child_d1;
            } else if (child_d1 > d2) {
                d2 = child_d1;
            }
        }
        answer = max(answer, d1 + d2);
        return d1;
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
        for (int i = 0; i < n - 1; ++i) {
            int a, b, w;  // 注意，这里需使用双向边
            scanf("%d%d%d", &a, &b, &w);
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }
        int answer = 0;
        treeModel(1, -1, graph, answer);
        printf("%d\n", answer);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1072_H
