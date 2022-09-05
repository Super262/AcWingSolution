//
// Created by Fengwei Zhang on 9/20/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0238_H
#define ACWINGSOLUTION_PROBLEM0238_H

#include <iostream>
#include <cmath>

using namespace std;

class Problem0238 {
private:
    static const int N = 30010;
    int clsSize[N], dist[N], parent[N];

    int findRoot(int x) {
        if (x != parent[x]) {
            int root = findRoot(parent[x]);
            dist[x] += dist[parent[x]];
            parent[x] = root;
        }
        return parent[x];
    }

    void mergeSets(int a, int b) {
        auto pa = findRoot(a);
        auto pb = findRoot(b);
        if (pa == pb) {
            return;
        }
        dist[pa] = clsSize[pb];
        clsSize[pb] += clsSize[pa];
        parent[pa] = pb;
    }

    int querySets(int a, int b) {
        auto pa = findRoot(a);
        auto pb = findRoot(b);
        if (pa == pb) {
            return max(abs(dist[a] - dist[b]) - 1, 0);
        }
        return -1;
    }

    int main() {
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
            clsSize[i] = 1;
        }
        int n;
        scanf("%d", &n);
        char op[2];
        int a, b;
        for (int i = 0; i < n; ++i) {
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'M') {
                mergeSets(a, b);
            } else {
                printf("%d\n", querySets(a, b));
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0238_H
