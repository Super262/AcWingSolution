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
public:
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

    void dijkstra(const int start) {
        auto visited = new bool[N + 1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        memset(distToEnd, 0x7f, sizeof distToEnd);
        memset(visited, 0, sizeof(bool) * (N + 1));
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
        delete[] visited;
    }

    int aStar(const int start, const int end, const int k) {
        int result = -1;
        auto count = new int[N + 1];
        memset(count, 0, sizeof(int) * (N + 1));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;
        heap.emplace(pair<int, pair<int, int>>(distToEnd[start], pair<int, int>(0, start)));
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto rootV = t.second.second;
            auto rootDistFromSrc = t.second.first;
            ++count[rootV];
            if (count[end] == k) {
                result = rootDistFromSrc;
                break;
            }
            for (int idx = headIndex[rootV]; idx != -1; idx = nextIndex[idx]) {
                int nextV = vertexValue[idx];
                if (count[nextV] < k) {
                    heap.emplace(pair<int, pair<int, int>>(rootDistFromSrc + edgeWeight[idx] + distToEnd[nextV],
                                                           pair<int, int>(rootDistFromSrc + edgeWeight[idx], nextV)));
                }
            }
        }
        delete[] count;
        return result;
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
        if (start == end) {
            ++k;
        }
        dijkstra(end);
        printf("%d\n", aStar(start, end, k));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0178_H
