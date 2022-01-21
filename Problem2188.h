//
// Created by Fengwei Zhang on 1/20/22.
//

#ifndef ACWINGSOLUTION_PROBLEM2188_H
#define ACWINGSOLUTION_PROBLEM2188_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem2188 {
private:
    void AddEdge(int a, int b, int c, int d, int &idx, int head[], int edge[], int nid[], int cap[], int low[]) {
        edge[idx] = b;
        cap[idx] = d - c;
        low[idx] = c;
        nid[idx] = head[a];
        head[a] = idx;
        idx++;
        edge[idx] = a;
        cap[idx] = 0;
        nid[idx] = head[b];
        head[b] = idx;
        ++idx;
    }

    bool HasPath(int st, int ed, int q[], int cur[], int level[], int head[], int edge[], int nid[], int cap[]) {
        int hh = 0, tt = -1;
        q[++tt] = st;
        cur[st] = head[st];
        level[st] = 0;
        while (hh <= tt) {
            auto t = q[hh++];
            for (auto i = head[t]; i != -1; i = nid[i]) {
                auto v = edge[i];
                if (level[v] != -1 || !cap[i]) {
                    continue;
                }
                level[v] = level[t] + 1;
                cur[v] = head[v];
                if (v == ed) {
                    return true;
                }
                q[++tt] = v;
            }
        }
        return false;
    }

    int FindPath(int st, int ed, int limit, int cur[], int level[], int edge[], int nid[], int cap[]) {
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
            auto f = FindPath(v, ed, min(limit - res, cap[i]), cur, level, edge, nid, cap);
            if (!f) {
                level[v] = -1;
            }
            cap[i] -= f;
            cap[i ^ 1] += f;
            res += f;
        }
        return res;
    }

    int Dinic(int st, int ed, int n, int head[], int edge[], int nid[], int cap[]) {
        int res = 0;
        int q[n];
        int level[n];
        int cur[n];
        memset(level, -1, sizeof level);
        memset(cur, -1, sizeof cur);
        while (HasPath(st, ed, q, cur, level, head, edge, nid, cap)) {
            int f;
            do {
                f = FindPath(st, ed, 0x3f3f3f3f, cur, level, edge, nid, cap);
                res += f;
            } while (f);
            memset(level, -1, sizeof level);
            memset(cur, -1, sizeof cur);
        }
        return res;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int s = 0, t = n + 1;
        int head[n + 1];
        int edge[(n + m) * 2];
        int nid[(n + m) * 2];
        int cap[(n + m) * 2];
        int low[(n + m) * 2];
        int f[n + 1];
        memset(head, -1, sizeof head);
        memset(edge, 0, sizeof edge);
        memset(nid, -1, sizeof nid);
        memset(cap, 0, sizeof cap);
        memset(low, 0, sizeof low);
        memset(f, 0, sizeof f);
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            AddEdge(a, b, c, d, idx, head, edge, nid, cap, low);
            f[a] -= c;
            f[b] += c;
        }
        int total = 0;
        for (int v = 1; v <= n; ++v) {
            if (f[v] > 0) {
                total += f[v];
                AddEdge(s, v, 0, f[v], idx, head, edge, nid, cap, low);
            } else if (f[v] < 0) {
                AddEdge(v, t, 0, -f[v], idx, head, edge, nid, cap, low);
            }
        }
        if (Dinic(s, t, n + 2, head, edge, nid, cap) != total) {
            puts("NO");
        } else {
            puts("YES");
            for (int i = 0; i < m * 2; i += 2) {  // 最初被添加的m条边
                printf("%d\n", cap[i ^ 1] + low[i]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM2188_H
