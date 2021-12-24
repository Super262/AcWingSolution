//
// Created by Fengwei Zhang on 12/24/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0345_H
#define ACWINGSOLUTION_PROBLEM0345_H

#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

class Problem0345 {
    // 利用Floyd算法的特点，结合快速幂：https://www.acwing.com/solution/content/17209/
private:
    static const int N = 210;
    int graph[N][N];
    int res[N][N];
    int n = 0, k = 0, m = 0, s = 0, e = 0;

    void multiply(int c[][N], int a[][N], int b[][N]) {
        // c可能和a、b相同，设置缓冲区
        int temp[N][N];
        memset(temp, 0x3f, sizeof temp);
        for (int t = 1; t <= n; ++t) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    temp[i][j] = min(temp[i][j], a[i][t] + b[t][j]);
                }
            }
        }
        memcpy(c, temp, sizeof temp);
    }

    void qmi() {
        memset(res, 0x3f, sizeof res);
        for (int i = 1; i <= n; ++i) {
            res[i][i] = 0;
        }
        while (k) {
            if (k & 1) {
                multiply(res, res, graph);
            }
            multiply(graph, graph, graph);
            k >>= 1;
        }
    }

    int main() {
        scanf("%d%d%d%d", &k, &m, &s, &e);
        memset(graph, 0x3f, sizeof graph);
        unordered_map<int, int> ids;
        if (!ids.count(s)) {
            ids[s] = ++n;
        }
        if (!ids.count(e)) {
            ids[e] = ++n;
        }
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &c, &a, &b);
            if (!ids.count(a)) {
                ids[a] = ++n;
            }
            if (!ids.count(b)) {
                ids[b] = ++n;
            }
            a = ids[a];
            b = ids[b];
            graph[a][b] = min(graph[a][b], c);
            graph[b][a] = graph[a][b];
        }
        qmi();
        printf("%d\n", res[ids[s]][ids[e]]);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0345_H
