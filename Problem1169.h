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
    int h[N], e[M], ne[M], w[M];
    long long dist[N];
    int q[N], cnt[N];
    bool st[N];

    void add(int a, int b, int c, int &idx) {
        e[idx] = b;
        w[idx] = c;
        ne[idx] = h[a];
        h[a] = idx;
        ++idx;
    }

    bool spfa(int n) {
        int tt = -1;
        memset(dist, -0x3f, sizeof dist);
        memset(cnt, 0, sizeof cnt);
        memset(st, 0, sizeof st);
        dist[0] = 0;
        q[++tt] = 0;
        st[0] = true;
        while (tt >= 0) {
            auto root = q[tt--];
            st[root] = false;
            for (int i = h[root]; i != -1; i = ne[i]) {
                auto nv = e[i];
                if (dist[nv] >= dist[root] + w[i]) {
                    continue;
                }
                dist[nv] = dist[root] + w[i];
                cnt[nv] = cnt[root] + 1;
                if (cnt[nv] >= n) {
                    return false;
                }
                if (st[nv]) {
                    continue;
                }
                st[nv] = true;
                q[++tt] = nv;
            }
        }
        return true;
    }

    int main() {
        memset(h, -1, sizeof h);
        memset(ne, -1, sizeof ne);
        int n, k;
        scanf("%d%d", &n, &k);
        int idx = 0;
        while (k--) {
            int x, a, b;
            scanf("%d%d%d", &x, &a, &b);
            if (x == 1) {
                add(b, a, 0, idx);
                add(a, b, 0, idx);
            } else if (x == 2) {
                add(a, b, 1, idx);
            } else if (x == 3) {
                add(b, a, 0, idx);
            } else if (x == 4) {
                add(b, a, 1, idx);
            } else {
                add(a, b, 0, idx);
            }
        }
        for (int v = 1; v <= n; ++v) {
            add(0, v, 1, idx);
        }
        if (!spfa(n + 1)) {
            puts("-1");
        } else {
            long long res = 0;
            for (int v = 1; v <= n; ++v) {
                res += dist[v];
            }
            printf("%lld\n", res);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1169_H
