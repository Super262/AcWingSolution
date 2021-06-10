//
// Created by Fengwei Zhang on 2021/6/9.
//

#ifndef ACWINGSOLUTION_PROBLEM0851_H
#define ACWINGSOLUTION_PROBLEM0851_H

class Problem0851 {
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

    int spfa(const vector<int> &headIndex,
             const vector<int> &vertexValue,
             const vector<int> &nextIndex,
             const vector<int> &weight,
             const int n) {
        queue<int> q; // q存放距离变小的顶点
        vector<int> distance(n + 1, 0x3f3f3f3f);
        vector<bool> isInQueue(n + 1, false);
        distance[1] = 0;
        q.emplace(1);
        isInQueue[1] = true;
        while (!q.empty()) {
            auto vertex = q.front();
            q.pop();
            isInQueue[vertex] = false;
            for (int neighborIdx = headIndex[vertex]; neighborIdx != -1; neighborIdx = nextIndex[neighborIdx]) {
                int neighborV = vertexValue[neighborIdx];
                if (distance[neighborV] <= distance[vertex] + weight[neighborIdx]) {
                    continue;
                }
                distance[neighborV] = distance[vertex] + weight[neighborIdx];
                if (!isInQueue[neighborV]) {
                    q.emplace(neighborV);
                    isInQueue[neighborV] = true;
                }
            }
        }
        if (distance[n] == 0x3f3f3f3f) {
            return -1;
        }
        return distance[n];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int x, y, z;
        vector<int> headIndex(n + 1, -1);
        vector<int> vertexValue(2 * n + 1, 0);
        vector<int> nextIndex(2 * n + 1, -1);
        vector<int> weight(2 * n + 1, 0);
        int idx = 0;
        while (m--) {
            scanf("%d%d%d", &x, &y, &z);
            addEdge(x, y, z, headIndex, vertexValue, nextIndex, weight, idx);
        }
        int result = spfa(headIndex, vertexValue, nextIndex, weight, n);
        if (result == -1) {
            puts("impossible");
        } else {
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0851_H
