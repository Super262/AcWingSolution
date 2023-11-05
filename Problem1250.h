//
// Created by Fengwei Zhang on 9/19/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1250_H
#define ACWINGSOLUTION_PROBLEM1250_H

#include <iostream>

using namespace std;

class Problem1250 {
private:
    static const int N = 200;
    int parent[N * N];

    int find_root(int x) {
        auto u = x;
        while (u != parent[u]) {
            u = parent[u];
        }
        while (x != u) {
            auto p = parent[x];
            parent[x] = u;
            x = p;
        }
        return u;
    }

    bool addEdge(const int x, const int y, const int n, const char direction) {
        auto a = x * n + y;
        int b = 0;
        if (direction == 'D') {
            b = (x + 1) * n + y;
        } else {
            b = x * n + (y + 1);
        }
        auto pa = find_root(a);
        auto pb = find_root(b);
        if (pa == pb) {  // a和b在同一个连通块中，直接返回
            return true;
        }
        parent[pa] = pb;
        return false;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n * n; ++i) {
            parent[i] = i;
        }
        int i;
        for (i = 1; i <= m; ++i) {
            int x, y;
            char d;
            cin >> x >> y >> d;
            if (addEdge(x - 1, y - 1, n, d)) {  // 存储的索引从0开始，需把输入坐标减1
                printf("%d\n", i);
                break;
            }
        }
        if (i > m) {
            printf("draw\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1250_H
