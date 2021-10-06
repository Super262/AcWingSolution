//
// Created by Fengwei Zhang on 10/6/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1184_H
#define ACWINGSOLUTION_PROBLEM1184_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem1184 {
    // https://www.acwing.com/solution/content/16024/
private:
    const int N = 100100, M = 400100;
    int headIndex[N], vertexValue[M], nextIndex[M];
    int answer[N * 2];
    bool used[M];
    int din[N], dout[N];
    int type;
    int answerTop = 0;

    void addEdge(const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        nextIndex[idx] = headIndex[a];
        headIndex[a] = idx;
        ++idx;
    }

    void dfs(const int u) {
        for (int &idx = headIndex[u]; idx != -1;) {
            if (used[idx]) {
                idx = nextIndex[idx];
                continue;
            }
            used[idx] = true;
            if (type == 1) {
                used[idx ^ 1] = true;
            }
            int t;
            if (type == 1) {
                t = idx / 2 + 1;
                if (idx & 1) {
                    t = -t;
                }
            } else {
                t = idx + 1;
            }
            int v = vertexValue[idx];
            idx = nextIndex[idx];
            dfs(v);
            answer[answerTop++] = t;
        }
    }

    int main() {
        int n, m;
        scanf("%d%d%d", &type, &n, &m);
        memset(headIndex, -1, sizeof headIndex);
        memset(nextIndex, -1, sizeof nextIndex);
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            addEdge(a, b, idx);
            if (type == 1) {
                addEdge(b, a, idx);
            }
            ++din[b];
            ++dout[a];
        }
        if (type == 1) {
            for (int i = 1; i <= n; ++i) {
                if ((din[i] + dout[i]) & 1) {
                    puts("NO");
                    return 0;
                }
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                if (din[i] != dout[i]) {
                    puts("NO");
                    return 0;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (headIndex[i] == -1) {
                continue;
            }
            dfs(i);
            break;
        }
        if (answerTop < m) {
            puts("NO");
            return 0;
        }
        puts("YES");
        for (int i = answerTop - 1; i >= 0; --i) {
            cout << answer[i] << " ";
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1184_H
