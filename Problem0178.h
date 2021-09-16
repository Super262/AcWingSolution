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
    int headIdx[N + 10], rgHeadIdx[N + 10];
    int verVal[2 * M + 10], nextIdx[2 * M + 10], edgeWeight[2 * M + 10];
    int dis2E[N + 10];

    void addEdge(int heIdx[], const int start, const int end, const int w, int &idx) {
        verVal[idx] = end;
        edgeWeight[idx] = w;
        nextIdx[idx] = heIdx[start];
        heIdx[start] = idx;
        ++idx;
    }

    void dijkstra(const int start, const int n) {
        bool visited[n + 1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        memset(dis2E, 0x7f, sizeof dis2E);
        memset(visited, 0, sizeof visited);
        heap.emplace(pair<int, int>(0, start));
        dis2E[start] = 0;
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            const auto rootV = t.second;
            if (visited[rootV]) {
                continue;
            }
            visited[rootV] = true;
            for (int idx = rgHeadIdx[rootV]; idx != -1; idx = nextIdx[idx]) {
                const int nextV = verVal[idx];
                if (dis2E[nextV] <= dis2E[rootV] + edgeWeight[idx]) {
                    continue;
                }
                dis2E[nextV] = dis2E[rootV] + edgeWeight[idx];
                heap.emplace(pair<int, int>(dis2E[nextV], nextV));
            }
        }
    }

    int aStar(const int start, const int end, const int k, const int n) {
        dijkstra(end, n);
        int count[n + 1];
        memset(count, 0, sizeof count);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;
        heap.emplace(pair<int, pair<int, int>>(dis2E[start], pair<int, int>(0, start)));
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto rootV = t.second.second;
            auto rootDistFromSrc = t.second.first;
            ++count[rootV];
            if (rootV == end && count[end] == k) { //终点已经被访问过k次了，返回答案
                return rootDistFromSrc;
            }
            for (int idx = headIdx[rootV]; idx != -1; idx = nextIdx[idx]) {
                int nextV = verVal[idx];
                // 如果走到一个中间点都cnt[j]>=K，则说明j已经出队k次了，且astar()并没有return distance，
                // 说明从j出发找不到第k短路(让终点出队k次)，即继续让j入队的话依然无解，那么就没必要让j继续入队了。
                if (count[nextV] < k) {
                    heap.emplace(pair<int, pair<int, int>>(rootDistFromSrc + edgeWeight[idx] + dis2E[nextV],
                                                           pair<int, int>(rootDistFromSrc + edgeWeight[idx], nextV)));
                }
            }
        }
        return -1;
    }

    int main() {
        memset(headIdx, -1, sizeof headIdx);
        memset(rgHeadIdx, -1, sizeof rgHeadIdx);
        memset(nextIdx, -1, sizeof nextIdx);
        int m, n;
        scanf("%d%d", &n, &m);
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(headIdx, u, v, w, idx);
            addEdge(rgHeadIdx, v, u, w, idx);
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
