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

    int find_root(int x) {
        if (x != parent[x]) {
            int root = find_root(parent[x]);
            dist[x] += dist[parent[x]];
            parent[x] = root;
        }
        return parent[x];
    }

    void merge_sets(int a, int b) {
        auto pa = find_root(a);
        auto pb = find_root(b);
        if (pa == pb) {
            return;
        }
        dist[pa] = clsSize[pb];
        clsSize[pb] += clsSize[pa];
        parent[pa] = pb;
    }

    int querySets(int a, int b) {
        auto pa = find_root(a);
        auto pb = find_root(b);
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
                merge_sets(a, b);
            } else {
                printf("%d\n", querySets(a, b));
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0238_H
