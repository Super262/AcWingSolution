//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0853_H
#define ACWINGSOLUTION_PROBLEM0853_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0853 {
public:
    int bellman_ford(const int n,
                     const int edgesCount,
                     int maxPathLen,
                     const vector<int> &edgeStart,
                     const vector<int> &edgeEnd,
                     const vector<int> &edgeWeight) {
        vector<int> distance(n + 1, 0x3f3f3f3f);
        distance[1] = 0;
        while (maxPathLen--) {
            const vector<int> prevDis(distance);  // 不要忘记这个备份！
            for (int j = 0; j < edgesCount; ++j) {
                distance[edgeEnd[j]] = min(distance[edgeEnd[j]], prevDis[edgeStart[j]] + edgeWeight[j]);
            }
        }
        // "正无穷"可能被负权边更新而减小，所以这里使用"0x3f3f3f3f/2"
        return distance[n] >= 0x3f3f3f3f / 2 ? -1 : distance[n];
    }

    int main() {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector<int> edgeStart(m, 0);
        vector<int> edgeEnd(m, 0);
        vector<int> edgeWeight(m, 0);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edgeStart[i], &edgeEnd[i], &edgeWeight[i]);
        }
        int result = bellman_ford(n, m, k, edgeStart, edgeEnd, edgeWeight);
        if (result == -1) {
            printf("impossible\n");
        } else {
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0853_H
