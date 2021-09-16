//
// Created by Fengwei Zhang on 2021/7/23.
//

#ifndef ACWINGSOLUTION_PROBLEM0178_H
#define ACWINGSOLUTION_PROBLEM0178_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

class Problem0178 {
    // https://www.acwing.com/solution/content/21233/
private:
    const int N = 1000;
    const int M = 100000;
    int headIndex[N + 10], reversedHeadIndex[N + 10];
    int vertexValue[2 * M + 10], nextIndex[2 * M + 10], edgeWeight[2 * M + 10];
    int distToEnd[N + 10];

    void addEdge(int heIdx[], const int start, const int end, const int w, int &idx) {
        vertexValue[idx] = end;
        edgeWeight[idx] = w;
        nextIndex[idx] = heIdx[start];
        heIdx[start] = idx;
        ++idx;
    }

    void dijkstra(const int start, const int n) {
        bool visited[n + 1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        memset(distToEnd, 0x7f, sizeof distToEnd);
        memset(visited, 0, sizeof visited);
        heap.emplace(pair<int, int>(0, start));
        distToEnd[start] = 0;
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            const auto rootV = t.second;
            if (visited[rootV]) {
                continue;
            }
            visited[rootV] = true;
            for (int idx = reversedHeadIndex[rootV]; idx != -1; idx = nextIndex[idx]) {
                const int nextV = vertexValue[idx];
                if (distToEnd[nextV] <= distToEnd[rootV] + edgeWeight[idx]) {
                    continue;
                }
                distToEnd[nextV] = distToEnd[rootV] + edgeWeight[idx];
                heap.emplace(pair<int, int>(distToEnd[nextV], nextV));
            }
        }
    }

    int aStar(const int start, const int end, const int k, const int n) {
        int result = -1;
        int count[n + 1];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;
        dijkstra(end, n);
        memset(count, 0, sizeof count);
        heap.emplace(pair<int, pair<int, int>>(distToEnd[start], pair<int, int>(0, start)));
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto rootV = t.second.second;
            auto rootDistFromSrc = t.second.first;
            ++count[rootV];
            if (rootV == end && count[end] == k) { //终点已经被访问过k次了，返回答案
                return rootDistFromSrc;
            }
            for (int idx = headIndex[rootV]; idx != -1; idx = nextIndex[idx]) {
                int nextV = vertexValue[idx];
                // 如果走到一个中间点都cnt[j]>=K，则说明j已经出队k次了，且astar()并没有return distance，
                // 说明从j出发找不到第k短路(让终点出队k次)，即继续让j入队的话依然无解，那么就没必要让j继续入队了。
                if (count[nextV] < k) {
                    heap.emplace(pair<int, pair<int, int>>(rootDistFromSrc + edgeWeight[idx] + distToEnd[nextV],
                                                           pair<int, int>(rootDistFromSrc + edgeWeight[idx], nextV)));
                }
            }
        }
        return -1;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(reversedHeadIndex, -1, sizeof reversedHeadIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int m, n;
        scanf("%d%d", &n, &m);
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(headIndex, u, v, w, idx);
            addEdge(reversedHeadIndex, v, u, w, idx);
        }
        int start, end, k;
        scanf("%d%d%d", &start, &end, &k);
        // 题目规定每条最短路都要至少包含1条边，所以我们需要舍弃起点等于终点的情况
        if (start == end) {
            ++k;
        }
        printf("%d\n", aStar(start, end, k, n));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0178_H
