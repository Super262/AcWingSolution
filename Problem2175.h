//
// Created by Fengwei Zhang on 1/20/22.
//

#ifndef ACWINGSOLUTION_PROBLEM2175_H
#define ACWINGSOLUTION_PROBLEM2175_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem2175 {
private:
    static const int N = 110, M = 5500;
    int head[N], cur[N], level[N], edge[M], nid[M], cap[M];
    int q[N];

    void AddEdge(int a, int b, int c, int &idx) {
        edge[idx] = b;
        cap[idx] = c;
        nid[idx] = head[a];
        head[a] = idx;
        ++idx;
    }

    bool HasPath(int st, int ed) {
        memset(level, -1, sizeof level);
        int hh = 0, tt = -1;
        q[++tt] = st;
        level[st] = 0;
        cur[st] = head[st];
        while (hh <= tt) {
            auto t = q[hh++];
            for (auto i = head[t]; i != -1; i = nid[i]) {
                auto v = edge[i];
                if (level[v] != -1 || !cap[i]) {
                    continue;
                }
                cur[v] = head[v];
                level[v] = level[t] + 1;
                if (v == ed) {
                    return true;
                }
                q[++tt] = v;
            }
        }
        return false;
    }

    int FindFlow(int st, int ed, int limit) {
        if (st == ed) {
            return limit;
        }
        int res = 0;
        for (auto i = cur[st]; i != -1 && res < limit; i = nid[i]) {
            cur[st] = i;
            auto v = edge[i];
            if (level[v] != level[st] + 1 || !cap[i]) {
                continue;
            }
            auto f = FindFlow(v, ed, min(cap[i], limit - res));
            if (!f) {
                level[v] = -1;
            }
            cap[i] -= f;
            cap[i ^ 1] += f;
            res += f;
        }
        return res;
    }

    int Dinic(int st, int ed) {
        int res = 0;
        while (HasPath(st, ed)) {
            int f;
            do {
                f = FindFlow(st, ed, 0x3f3f3f3f);
                res += f;
            } while (f);
        }
        return res;
    }

    int main() {
        memset(head, -1, sizeof head);
        memset(nid, -1, sizeof nid);
        int m, n;
        scanf("%d%d", &m, &n);
        int idx = 0;
        int s = 0, t = n + 1;
        for (int i = 1; i <= m; ++i) {
            AddEdge(s, i, 1, idx);
            AddEdge(i, s, 0, idx);
        }
        for (int i = m + 1; i <= n; ++i) {
            AddEdge(i, t, 1, idx);
            AddEdge(t, i, 0, idx);
        }
        int a, b;
        while (true) {
            scanf("%d%d", &a, &b);
            if (a == -1 && b == -1) {
                break;
            }
            AddEdge(a, b, 1, idx);
            AddEdge(b, a, 0, idx);
        }
        printf("%d\n", Dinic(s, t));
        // 输出具体方案
        for (int i = 0; i < idx; i += 2) {
            if (edge[i] > m && edge[i] <= n && !cap[i]) {  // 要求cap[i] == 0，不能有剩余容量
                printf("%d %d\n", edge[i ^ 1], edge[i]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM2175_H
