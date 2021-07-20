//
// Created by Fengwei Zhang on 2021/7/20.
//

#ifndef ACWINGSOLUTION_PROBLEM1088_H
#define ACWINGSOLUTION_PROBLEM1088_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1088 {
    // https://www.acwing.com/solution/content/34005/
public:
    void visitorHelper1(const long long *prefixSum, bool *visited, const int N) {
        auto q = new int[2 * N];
        memset(q, 0, sizeof(int) * 2 * N);
        int hh = 0, tt = -1;
        for (int i = 2 * N; i >= 1; --i) {
            while (hh <= tt && q[hh] > i + N - 1) {
                ++hh;
            }
            while (hh <= tt && prefixSum[q[tt]] >= prefixSum[i]) {
                --tt;
            }
            q[++tt] = i;
            if (i <= N && prefixSum[q[hh]] >= prefixSum[i - 1]) {
                visited[i] = true;
            }
        }
        delete[] q;
    }

    void visitorHelper2(const long long *prefixSum, bool *visited, const int N) {
        auto q = new int[2 * N];
        memset(q, 0, sizeof(int) * 2 * N);
        int hh = 0, tt = -1;
        for (int i = 1; i <= 2 * N; ++i) {
            while (hh <= tt && q[hh] < i - N + 1) {
                ++hh;
            }
            while (hh <= tt && prefixSum[q[tt]] >= prefixSum[i]) {
                --tt;
            }
            q[++tt] = i;
            if (i > N && prefixSum[q[hh]] >= prefixSum[i + 1]) {
                visited[i - N] = true;
            }
        }
        delete[] q;
    }

    int main() {
        int n;
        scanf("%d", &n);
        auto visited = new bool[n + 1];
        memset(visited, 0, sizeof(bool) * (n + 1));
        auto oil = new int[n + 1];
        auto cost = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &oil[i], &cost[i]);
        }
        auto prefixSum = new long long[2 * n + 1];
        memset(prefixSum, 0, sizeof(long long) * (2 * n + 1));
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i + n] = oil[i] - cost[i];
        }
        for (int i = 1; i <= 2 * n; ++i) {
            prefixSum[i] += prefixSum[i - 1];
        }
        visitorHelper1(prefixSum, visited, n);
        memset(prefixSum, 0, sizeof(long long) * (2 * n + 1));
        cost[0] = cost[n];
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i + n] = oil[i] - cost[i - 1];
        }
        for (int i = 2 * n; i >= 1; --i) {
            prefixSum[i] += prefixSum[i + 1];
        }
        visitorHelper2(prefixSum, visited, n);
        for (int i = 1; i <= n; ++i) {
            if (visited[i]) {
                printf("TAK\n");
            } else {
                printf("NIE\n");
            }
        }
        delete[] oil;
        delete[] cost;
        delete[] visited;
        delete[] prefixSum;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1088_H
