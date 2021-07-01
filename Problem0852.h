//
// Created by Fengwei Zhang on 2021/6/10.
//

#ifndef ACWINGSOLUTION_PROBLEM0852_H
#define ACWINGSOLUTION_PROBLEM0852_H

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Problem0852 {
public:
    void addEdge(const int start,
                 const int end,
                 const int w,
                 vector<int> &headIndex,
                 vector<int> &vertexValue,
                 vector<int> &nextIndex,
                 vector<int> &weight,
                 int &idx) {
        if (idx >= vertexValue.size()) {
            vertexValue.emplace_back(0);
        }
        if (idx >= nextIndex.size()) {
            nextIndex.emplace_back(-1);
        }
        if (idx >= weight.size()) {
            weight.emplace_back(0);
        }
        vertexValue[idx] = end;
        nextIndex[idx] = headIndex[start];
        weight[idx] = w;
        headIndex[start] = idx;
        ++idx;
    }

    // 每次做一遍SPFA一定是正确的，但时间复杂度较高，可能会超时。初始时将所有点插入队列中可以按如下方式理解：
    // 在原图的基础上新建一个虚拟源点，从该点向其他所有点连一条权值为0的有向边。那么原图有负环等价于新图有负环。
    bool spfa(const int n,
              const vector<int> &headIndex,
              const vector<int> &vertexValue,
              const vector<int> &nextIndex,
              const vector<int> &weight) {
        queue<int> q;
        vector<int> edgesCount(n + 1, 0);
        vector<int> distance(n + 1, 0x3f3f3f3f);
        vector<bool> isInQueue(n + 1, false);
        for (int v = 1; v <= n; ++v) {
            q.emplace(v);
            isInQueue[v] = true;
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            isInQueue[v] = false;
            for (int neighborIdx = headIndex[v]; neighborIdx != -1; neighborIdx = nextIndex[neighborIdx]) {
                int neighborV = vertexValue[neighborIdx];
                if (distance[neighborV] < distance[v] + weight[neighborIdx]) {
                    continue;
                }
                distance[neighborV] = distance[v] + weight[neighborIdx];
                edgesCount[neighborV] = edgesCount[v] + 1;
                if (edgesCount[neighborV] > n) {
                    return true;
                }
                if (!isInQueue[neighborV]) {
                    q.emplace(neighborV);
                    isInQueue[neighborV] = true;
                }
            }
        }
        return false;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> headIndex(n + 1, -1);
        vector<int> vertexValue(2 * n + 1, 0);
        vector<int> nextIndex(2 * n + 1, -1);
        vector<int> weight(2 * n + 1, 0);
        int idx = 0;
        int x, y, z;
        while (m--) {
            scanf("%d%d%d", &x, &y, &z);
            addEdge(x, y, z, headIndex, vertexValue, nextIndex, weight, idx);
        }
        if (spfa(n, headIndex, vertexValue, nextIndex, weight)) {
            puts("Yes");
        } else {
            puts("No");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0852_H
