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
    static const int N = 1000;
    static const int M = 100000;
    int headIdx[N + 10], rgHeadIdx[N + 10];
    int verVal[2 * M + 10], nextIdx[2 * M + 10], edgeWeight[2 * M + 10];
    int dis2End[N + 10];

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
        memset(dis2End, 0x7f, sizeof dis2End);
        memset(visited, 0, sizeof visited);
        heap.emplace(pair<int, int>(0, start));
        dis2End[start] = 0;
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            const auto rootV = t.second;
            if (visited[rootV]) {
                continue;
            }
            visited[rootV] = true;
            for (int idx = rgHeadIdx[rootV]; idx != -1; idx = nextIdx[idx]) {
                const int nV = verVal[idx];
                if (dis2End[nV] <= dis2End[rootV] + edgeWeight[idx]) {
                    continue;
                }
                dis2End[nV] = dis2End[rootV] + edgeWeight[idx];
                heap.emplace(pair<int, int>(dis2End[nV], nV));
            }
        }
    }

    int aStar(const int start, const int end, const int k, const int n) {
        int count[n + 1];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;
        dijkstra(end, n);
        memset(count, 0, sizeof count);
        heap.emplace(pair<int, pair<int, int>>(dis2End[start], pair<int, int>(0, start)));
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto rV = t.second.second;
            auto rD2S = t.second.first;
            ++count[rV];
            if (rV == end && count[end] == k) { //终点已经被访问过k次了，返回答案
                return rD2S;
            }
            for (int idx = headIdx[rV]; idx != -1; idx = nextIdx[idx]) {
                int nV = verVal[idx];
                // 如果走到一个中间点都cnt[j]>=K，则说明j已经出队k次了，且astar()并没有return distance，
                // 说明从j出发找不到第k短路(让终点出队k次)，即继续让j入队的话依然无解，那么就没必要让j继续入队了。
                if (count[nV] < k) {
                    heap.emplace(pair<int, pair<int, int>>(rD2S + edgeWeight[idx] + dis2End[nV],
                                                           pair<int, int>(rD2S + edgeWeight[idx], nV)));
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
