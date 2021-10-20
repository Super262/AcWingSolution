//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0850_H
#define ACWINGSOLUTION_PROBLEM0850_H

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

class Problem0850 {
private:
    const int N = 150005;
    int headIndex[N];
    int vertexValue[2 * N];
    int nextIndex[2 * N];
    int weight[2 * N];

    void addEdge(int a, int b, int w, int &idx) {
        vertexValue[idx] = b;
        weight[idx] = w;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    int dijkstra(const int start, int end, int n) {
        int dist[n + 1];
        bool selected[n + 1];
        memset(dist, 0x3f, sizeof dist);
        memset(selected, 0, sizeof selected);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        dist[start] = 0;
        heap.emplace(pair<int, int>(dist[start], start));
        while (!heap.empty()) {  // 判断节点是否被选择，再压入队列
            auto t = heap.top();
            heap.pop();
            auto closeV = t.second;
            if (selected[closeV]) {
                continue;
            }
            selected[closeV] = true;
            for (int idx = headIndex[closeV]; idx != -1; idx = nextIndex[idx]) {
                auto childV = vertexValue[idx];
                if (dist[childV] < dist[closeV] + weight[idx]) {
                    continue;
                }
                dist[childV] = dist[closeV] + weight[idx];
                heap.emplace(pair<int, int>(dist[childV], childV));
            }
        }
        if (dist[end] == 0x3f3f3f3f) {
            return -1;
        }
        return dist[end];
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int n, m;
        scanf("%d%d", &n, &m);
        int x, y, w;
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            addEdge(x, y, w, idx);
        }
        printf("%d\n", dijkstra(1, n, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0850_H
