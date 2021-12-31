//
// Created by Fengwei Zhang on 12/26/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1169_H
#define ACWINGSOLUTION_PROBLEM1169_H

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

class Problem1169 {
    // 差分约束问题的源点条件：从源点出发，一定可达所有边
    // 最小值：SPFA求最长路
    // 本题不能使用vector保存图信息，会超时
private:
    static const int N = 100010, M = 300010;
    int n, m;
    int h[N], e[M], w[M], ne[M], idx;
    LL dist[N];
    int q[N], cnt[N];
    bool st[N];

    void add(int a, int b, int c) {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    bool spfa() {
        int hh = 0, tt = 1;
        memset(dist, -0x3f, sizeof dist);
        dist[0] = 0;
        q[0] = 0;
        st[0] = true;

        while (hh != tt) {
            int t = q[--tt];
            st[t] = false;

            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (dist[j] < dist[t] + w[i]) {
                    dist[j] = dist[t] + w[i];
                    cnt[j] = cnt[t] + 1;
                    if (cnt[j] >= n + 1) return false;
                    if (!st[j]) {
                        q[tt++] = j;
                        st[j] = true;
                    }
                }
            }
        }

        return true;
    }

    int main() {
        scanf("%d%d", &n, &m);
        memset(h, -1, sizeof h);
        while (m--) {
            int x, a, b;
            scanf("%d%d%d", &x, &a, &b);
            if (x == 1) add(b, a, 0), add(a, b, 0);
            else if (x == 2) add(a, b, 1);
            else if (x == 3) add(b, a, 0);
            else if (x == 4) add(b, a, 1);
            else add(a, b, 0);
        }

        for (int i = 1; i <= n; i++) add(0, i, 1);

        if (!spfa()) puts("-1");
        else {
            LL res = 0;
            for (int i = 1; i <= n; i++) res += dist[i];
            printf("%lld\n", res);
        }

        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1169_H
