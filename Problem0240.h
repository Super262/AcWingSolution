//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0240_H
#define ACWINGSOLUTION_PROBLEM0240_H

#include <iostream>

using namespace std;

class Problem0240 {
public:
    int findRoot(const int x, int *parent, int *distanceToParent) {
        if (parent[x] != x) {
            int root = findRoot(parent[x], parent, distanceToParent);
            distanceToParent[x] += distanceToParent[parent[x]];
            parent[x] = root;
        }
        return parent[x];
    }

    int main() {
        int n;
        int k;
        scanf("%d%d", &n, &k);
        auto *parent = new int[n + 1];
        auto *distanceToParent = new int[n + 1];
        for (int i = 0; i < n + 1; ++i) {
            parent[i] = i;
            distanceToParent[i] = 0;
        }
        int op, a, b;
        int result = 0;
        while (k--) {
            scanf("%d%d%d", &op, &a, &b);
            if (a > n || b > n) {
                ++result;
                continue;
            }
            const int pa = findRoot(a, parent, distanceToParent);
            const int pb = findRoot(b, parent, distanceToParent);
            if (op == 1) {
                if (pa == pb && (distanceToParent[a] - distanceToParent[b]) % 3) {
                    // a, b 在同一棵树上且到根结点的距离不同，为假话
                    ++result;
                } else if (pa != pb) {
                    parent[pa] = pb;
                    // 调整a的父节点到根的距离，使(d[a] - d[b]) % 3 == 0 成立
                    distanceToParent[pa] = distanceToParent[b] - distanceToParent[a];
                }
            } else {
                if (pa == pb && (distanceToParent[a] - distanceToParent[b] - 1) % 3) {
                    // a, b 在同一棵树上且到根结点的距离差不是1，为假话
                    ++result;
                } else if (pa != pb) {
                    parent[pa] = pb;
                    // 调整a的父节点到根的距离，使(d[a] - d[b] - 1) % 3 == 0 成立
                    distanceToParent[pa] = distanceToParent[b] + 1 - distanceToParent[a];
                }
            }
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0240_H
