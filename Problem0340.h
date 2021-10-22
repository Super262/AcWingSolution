//
// Created by Fengwei Zhang on 2021/7/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0340_H
#define ACWINGSOLUTION_PROBLEM0340_H

#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

class Problem0340 {
    // https://www.acwing.com/solution/content/13645/
private:
    const int N = 1010;
    const int M = 20010;
    int headIndex[N];
    int nextIndex[M];
    int vertexValue[M];
    int edgeWeight[M];

    void addEdge(const int s, const int e, const int w, int &idx) {
        vertexValue[idx] = e;
        edgeWeight[idx] = w;
        nextIndex[idx] = headIndex[s];
        headIndex[s] = idx;
        ++idx;
    }

    bool check(const int bound, const int start, const int end, const int n, const int k) {
        deque<int> q;
        bool visited[n + 1];
        int dist[n + 1];
        memset(visited, 0, sizeof visited);
        memset(dist, 0x3f, sizeof dist);
        dist[start] = 0;
        q.push_front(start);
        while (!q.empty()) {
            auto root = q.front();
            q.pop_front();
            if (visited[root]) {
                continue;
            }
            visited[root] = true;
            for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
                int child = vertexValue[idx];
                int w = edgeWeight[idx] > bound ? 1 : 0;
                if (dist[child] <= dist[root] + w) {
                    continue;
                }
                dist[child] = dist[root] + w;
                if (w) {
                    q.push_back(child);
                } else {
                    q.push_front(child);
                }
            }
        }
        return dist[end] <= k;
    }

    int main() {
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        memset(vertexValue, 0, sizeof vertexValue);
        memset(edgeWeight, 0, sizeof edgeWeight);
        int n, p, k;
        scanf("%d%d%d", &n, &p, &k);
        int idx = 0;
        for (int i = 0; i < p; ++i) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            addEdge(a, b, w, idx);
            addEdge(b, a, w, idx);
        }
        int left = 0, right = 1000001;  // 左端点取0，因为0可能是一个解；右端点取1000001，因为1到N可能不连通
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid, 1, n, n, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left == 1000001) {
            printf("%d\n", -1);
        } else {
            printf("%d\n", left);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0340_H
