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
    // 转化：判断长度为n的区间内的最小值是否大于或等于0
private:
    static const int N = 3000010;
    int oil[N], cost[N];
    bool visited[N];
    long long dq[N];
    long long prefix[2 * N];

    void helper1(const int n) {
        int hh = 0, tt = -1;
        for (int i = 2 * n; i >= 1; --i) {
            while (hh <= tt && dq[hh] - i + 1 > n + 1) {
                ++hh;
            }
            while (hh <= tt && prefix[i] <= prefix[dq[tt]]) {
                --tt;
            }
            dq[++tt] = i;
            if (i <= n && prefix[dq[hh]] - prefix[i - 1] >= 0) {
                visited[i] = true;
            }
        }
    }

    void helper2(const int n) {
        int hh = 0, tt = -1;
        for (int i = 1; i <= 2 * n; ++i) {
            while (hh <= tt && i - dq[hh] + 1 > n + 1) {
                ++hh;
            }
            while (hh <= tt && prefix[i] <= prefix[dq[tt]]) {
                --tt;
            }
            dq[++tt] = i;
            if (i > n && prefix[dq[hh]] - prefix[i + 1] >= 0) {
                visited[i - n] = true;
            }
        }
    }

    int main() {
        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &oil[i], &cost[i]);
        }
        for (int i = 1; i <= n; ++i) {
            prefix[i] = oil[i] - cost[i];
            prefix[i + n] = prefix[i];
        }
        for (int i = 1; i <= 2 * n; ++i) {
            prefix[i] += prefix[i - 1];
        }
        helper1(n);

        memset(prefix, 0, sizeof prefix);
        cost[0] = cost[n];
        for (int i = 1; i <= n; ++i) {
            prefix[i] = oil[i] - cost[i - 1];
            prefix[i + n] = prefix[i];
        }
        for (int i = 2 * n; i >= 1; --i) {
            prefix[i] += prefix[i + 1];
        }
        helper2(n);

        for (int i = 1; i <= n; ++i) {
            if (visited[i]) {
                printf("TAK\n");
            } else {
                printf("NIE\n");
            }
        }

        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1088_H
