//
// Created by Fengwei Zhang on 1/20/22.
//

#ifndef ACWINGSOLUTION_PROBLEM2172_H
#define ACWINGSOLUTION_PROBLEM2172_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem2173 {
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
        int flow = 0;
        for (auto i = cur[st]; i != -1 && flow < limit; i = nid[i]) {
            cur[st] = i;
            auto v = edge[i];
            if (level[v] != level[st] + 1 || !cap[i]) {
                continue;
            }
            auto f = FindFlow(v, ed, min(cap[i], limit - flow), level, cur, edge, nid, cap);
            if (!f) {
                level[v] = -1;
            }
            cap[i] -= f;
            cap[i ^ 1] += f;
            flow += f;
        }
        return flow;
    }

    int Dinic(int st, int ed, int n, int head[], int edge[], int nid[], int cap[]) {
        int res = 0;
        int q[n + 1];
        int level[n + 1];  // 记录点的层次
        int cur[n + 1];  // 弧优化
        memset(level, -1, sizeof level);
        memset(cur, -1, sizeof cur);
        while (HasPath(st, ed, q, level, cur, head, edge, nid, cap)) {
            int flow;
            do {
                flow = FindFlow(st, ed, 0x3f3f3f3f, level, cur, edge, nid, cap);
                res += flow;
            } while (flow);
            memset(level, -1, sizeof level);
        }
        return res;
    }

    int main() {
        int n, m, s, t;
        scanf("%d%d%d%d", &n, &m, &s, &t);
        int head[n + 1];
        int edge[2 * m + 1];
        int nid[2 * m + 1];
        int cap[2 * m + 1];
        memset(head, -1, sizeof head);
        memset(edge, 0, sizeof edge);
        memset(nid, -1, sizeof nid);
        memset(cap, 0, sizeof cap);
        int idx = 0;
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            AddEdge(a, b, c, idx, head, edge, nid, cap);
            AddEdge(b, a, 0, idx, head, edge, nid, cap);
        }
        printf("%d\n", Dinic(s, t, n, head, edge, nid, cap));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM2172_H
