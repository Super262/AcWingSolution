//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0836_H
#define ACWINGSOLUTION_PROBLEM0836_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0836 {
private:
    int findRoot(int x, int parent[]) {
        auto root = x;
        while (parent[root] != root) {
            root = parent[root];
        }
        while (x != root) {
            auto prev = parent[x];
            parent[x] = root;
            x = prev;
        }
        return root;
    }

    int mergeSets(int a, int b, int parent[], int set_size[]) {
        if (a == b) {
            return -1;
        }
        if (set_size[b] > set_size[a]) {
            swap(a, b);
        }
        parent[b] = a;
        set_size[a] += set_size[b];
        return a;
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
        char op[2];
        int a, b;
        for (int i = 0; i < m; ++i) {
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'M') {
                a = findRoot(a, parent);
                b = findRoot(b, parent);
                mergeSets(a, b, parent, set_size);
                continue;
            }
            if (findRoot(a, parent) == findRoot(b, parent)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0836_H
