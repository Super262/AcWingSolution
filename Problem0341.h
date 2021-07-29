//
// Created by Fengwei Zhang on 2021/7/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0341_H
#define ACWINGSOLUTION_PROBLEM0341_H

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem0341 {
    // https://www.acwing.com/solution/content/3709/ (每个点可被多次经过：不能使用Dijkstra算法)
public:
#include <iostream>
#include <cstring>
#include <algorithm>

    using namespace std;
    const int N = 100010;
    const int M = 2000010;
    int price[N];
    int headIndexFromStart[N], headIndexFromEnd[N], nextIndex[M], vertexValue[M];
    int minPriceFromStart[N], maxPriceFromEnd[N], q[N];
    bool isInQueue[N];

    void addEdge(const int s, const int e, int &idx, bool fromStart) {
        vertexValue[idx] = e;
        if (fromStart) {
            nextIndex[idx] = headIndexFromStart[s];
            headIndexFromStart[s] = idx;
        } else {
            nextIndex[idx] = headIndexFromEnd[s];
            headIndexFromEnd[s] = idx;
        }
        ++idx;
    }

    void spfa(const int s, const bool fromStart) {
        int hh = 0, tt = -1;
        int *headIndex;
        if (fromStart) {
            memset(minPriceFromStart, 0x7f, sizeof minPriceFromStart);
            minPriceFromStart[s] = price[s];
            headIndex = headIndexFromStart;
        } else {
            memset(maxPriceFromEnd, -1, sizeof maxPriceFromEnd);
            maxPriceFromEnd[s] = price[s];
            headIndex = headIndexFromEnd;
        }
        memset(isInQueue, 0, sizeof isInQueue);
        q[++tt] = s;
        isInQueue[s] = true;
        while (hh <= tt) {
            auto root = q[hh++];
            isInQueue[root] = false;
            for (int idx = headIndex[root]; idx != -1; idx = nextIndex[idx]) {
                int childV = vertexValue[idx];
                if (fromStart && minPriceFromStart[childV] <= min(minPriceFromStart[root], price[childV])) {
                    continue;
                }
                if (((!fromStart) && maxPriceFromEnd[childV] >= max(maxPriceFromEnd[root], price[childV]))) {
                    continue;
                }
                if (fromStart) {
                    minPriceFromStart[childV] = min(minPriceFromStart[root], price[childV]);
                } else {
                    maxPriceFromEnd[childV] = max(maxPriceFromEnd[root], price[childV]);
                }
                if (isInQueue[childV]) {
                    continue;
                }
                isInQueue[childV] = true;
                q[++tt] = childV;
            }
        }
    }

    int main() {
        memset(headIndexFromStart, -1, sizeof headIndexFromStart);
        memset(headIndexFromEnd, -1, sizeof headIndexFromEnd);
        memset(nextIndex, -1, sizeof nextIndex);
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &price[i]);
        }
        int idx = 0;
        for (int i = 1; i <= m; ++i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            addEdge(a, b, idx, true);
            addEdge(b, a, idx, false);
            if (c == 2) {
                addEdge(b, a, idx, true);
                addEdge(a, b, idx, false);
            }
        }
        spfa(1, true);
        spfa(n, false);
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result = max(result, maxPriceFromEnd[i] - minPriceFromStart[i]);
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0341_H
