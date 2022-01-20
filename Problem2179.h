//
// Created by Fengwei Zhang on 1/20/22.
//

#ifndef ACWINGSOLUTION_PROBLEM2179_H
#define ACWINGSOLUTION_PROBLEM2179_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem2179 {
private:
    void AddEdge(int a, int b, int c, int &idx, int head[], int edge[], int nid[], int cap[]) {
        edge[idx] = b;
        cap[idx] = c;
        nid[idx] = head[a];
        head[a] = idx;
        ++idx;
    }

    bool HasPath(int st, int ed, int q[], int level[], int cur[], int head[], int edge[], int nid[], int cap[]) {
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

    int FindFlow(int st, int ed, int limit, int level[], int cur[], int edge[], int nid[], int cap[]) {
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
            auto f = FindFlow(v, ed, min(limit - res, cap[i]), level, cur, edge, nid, cap);
            if (!f) {
                level[v] = -1;
            }
            res += f;
            cap[i] -= f;
            cap[i ^ 1] += f;
        }
        return res;
    }

    int Dinic(int st, int ed, int n, int head[], int edge[], int nid[], int cap[]) {
        int level[n];
        int cur[n];
        int q[n];
        int res = 0;
        memset(level, -1, sizeof level);
        memset(cur, -1, sizeof cur);
        while (HasPath(st, ed, q, level, cur, head, edge, nid, cap)) {
            int f;
            do {
                f = FindFlow(st, ed, 0x3f3f3f3f, level, cur, edge, nid, cap);
                res += f;
            } while (f);
            memset(level, -1, sizeof level);
            memset(cur, -1, sizeof cur);
        }
        return res;
    }

    int main() {
        int m, n;
        scanf("%d%d", &m, &n);
        int head[m + n + 2];
        int edge[2 * m * n + 2 * (m + n)];
        int nid[2 * m * n + 2 * (m + n)];
        int cap[2 * m * n + 2 * (m + n)];
        memset(head, -1, sizeof head);
        memset(edge, 0, sizeof edge);
        memset(nid, -1, sizeof nid);
        memset(cap, 0, sizeof cap);
        auto s = 0, t = m + n + 1;
        int idx = 0;
        int total = 0;
        for (int i = 1; i <= m; ++i) {
            int c;
            scanf("%d", &c);
            total += c;
            AddEdge(s, i, c, idx, head, edge, nid, cap);
            AddEdge(i, s, 0, idx, head, edge, nid, cap);
        }
        for (int i = m + 1; i <= m + n; ++i) {
            int c;
            scanf("%d", &c);
            AddEdge(i, t, c, idx, head, edge, nid, cap);
            AddEdge(t, i, 0, idx, head, edge, nid, cap);
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = m + 1; j <= m + n; ++j) {
                AddEdge(i, j, 1, idx, head, edge, nid, cap);
                AddEdge(j, i, 0, idx, head, edge, nid, cap);
            }
        }
        if (total == Dinic(s, t, m + n + 2, head, edge, nid, cap)) {
            printf("%d\n", 1);
            for (int v = 1; v <= m; ++v) {
                for (auto i = head[v]; i != -1; i = nid[i]) {
                    if (edge[i] > m && edge[i] <= m + n && !cap[i]) {
                        printf("%d ", edge[i] - m);
                    }
                }
                printf("\n");
            }
        } else {
            printf("%d\n", 0);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM2179_H
