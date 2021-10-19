//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0853_H
#define ACWINGSOLUTION_PROBLEM0853_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0853 {
private:
    struct Edge {
        int start;
        int end;
        int weight;
    };

    Edge edges[10010];

    int bellmanFord(const int start, const int end, const int n, const int edgesSize, int pathLen) {
        int dist[n + 1];
        int temp[n + 1];
        memset(dist, 0x3f, sizeof dist);
        dist[start] = 0;
        while (pathLen--) {
            memcpy(temp, dist, sizeof dist);
            for (int i = 0; i < edgesSize; ++i) {
                dist[edges[i].end] = min(dist[edges[i].end], temp[edges[i].start] + edges[i].weight);
            }
        }
        // "正无穷"可能被负权边更新而减小，所以这里使用"0x3f3f3f3f/2"
        return dist[n] >= 0x3f3f3f3f / 2 ? 0x3f3f3f3f : dist[n];
    }

    int main() {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edges[i].start, &edges[i].end, &edges[i].weight);
        }
        int result = bellmanFord(1, n, n, m, k);
        if (result == 0x3f3f3f3f) {
            printf("impossible\n");
        } else {
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0853_H
