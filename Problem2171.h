//
// Created by Fengwei Zhang on 1/20/22.
//

#ifndef ACWINGSOLUTION_PROBLEM2171_H
#define ACWINGSOLUTION_PROBLEM2171_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem2171 {
private:
    static const int INF = 0x3f3f3f3f;

    void AddEdge(int a, int b, int c, int &idx, int head[], int nid[], int edge[], int flow[]) {
        edge[idx] = b;
        flow[idx] = c;
        nid[idx] = head[a];
        head[a] = idx;
        ++idx;
    }

    bool HasPath(int s, int t, int q[], bool visited[], int d[], int pre[], int head[], int nid[], int e[], int f[]) {
        int hh = 0, tt = -1;
        q[++tt] = s;
        visited[s] = true;
        d[s] = INF;
        while (hh <= tt) {
            auto cur = q[hh++];
            for (auto i = head[cur]; i != -1; i = nid[i]) {
                auto v = e[i];
                if (visited[v] || !f[i]) {
                    continue;
                }
                visited[v] = true;
                d[v] = min(d[cur], f[i]);
                pre[v] = i;
                if (v == t) {
                    return true;
                }
                q[++tt] = v;
            }
        }
        return false;
    }

    int EK(int s, int t, int n, int head[], int nid[], int edge[], int flow[]) {
        int r = 0;
        bool visited[n + 1];
        int d[n + 1];
        int pre[n + 1];
        int q[n + 1];
        memset(visited, 0, sizeof visited);
        while (HasPath(s, t, q, visited, d, pre, head, nid, edge, flow)) {
            r += d[t];
            for (int i = t; i != s; i = edge[pre[i] ^ 1]) {
                flow[pre[i]] -= d[t];
                flow[pre[i] ^ 1] += d[t];
            }
            memset(visited, 0, sizeof visited);
        }
        return r;
    }

    int main() {
        int n, m, s, t;
        scanf("%d%d%d%d", &n, &m, &s, &t);
        int head[n + 1];
        int nid[2 * m];
        int edge[2 * m];
        int flow[2 * m];
        memset(head, -1, sizeof head);
        memset(nid, -1, sizeof nid);
        memset(edge, 0, sizeof edge);
        memset(flow, 0, sizeof flow);
        int idx = 0;
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            AddEdge(a, b, c, idx, head, nid, edge, flow);
            AddEdge(b, a, 0, idx, head, nid, edge, flow);
        }
        printf("%d\n", EK(s, t, n, head, nid, edge, flow));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM2171_H
