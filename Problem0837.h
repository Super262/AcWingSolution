//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0837_H
#define ACWINGSOLUTION_PROBLEM0837_H

#include <iostream>

using namespace std;

class Problem0837 {
private:
    int findRoot(int x, int parent[]) {
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

    int mergeSets(int pa, int pb, int parent[], int set_size[]) {
        if (pa == pb) {
            return -1;
        }
        if (set_size[pa] > set_size[pb]) {
            swap(pa, pb);
        }
        set_size[pa] += set_size[pb];
        parent[pb] = pa;
        return pa;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int parent[n + 1];
        int set_size[n + 1];
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            set_size[i] = 1;
        }
        char op[3];
        int a, b;
        for (int i = 0; i < m; ++i) {
            scanf("%s", op);
            if (op[0] == 'C') {
                scanf("%d%d", &a, &b);
                auto pa = findRoot(a, parent);
                auto pb = findRoot(b, parent);
                mergeSets(pa, pb, parent, set_size);
            } else if (op[1] == '1') {
                scanf("%d%d", &a, &b);
                if (findRoot(a, parent) == findRoot(b, parent)) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            } else {
                scanf("%d", &a);
                printf("%d\n", set_size[findRoot(a, parent)]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0837_H
