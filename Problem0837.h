//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0837_H
#define ACWINGSOLUTION_PROBLEM0837_H

#include <iostream>

using namespace std;


class Problem0837 {
private:
    int rootIdx[100010];
    int clusterSize[100010];

    int findRoot(const int x) {
        if (x != rootIdx[x]) {
            rootIdx[x] = findRoot(rootIdx[x]);
        }
        return rootIdx[x];
    }

    void mergeSets(const int a, const int b) {
        auto rootA = findRoot(a);
        auto rootB = findRoot(b);
        if (rootA == rootB) {
            return;
        }
        auto nextSize = clusterSize[rootA] + clusterSize[rootB];
        rootIdx[rootA] = rootB;
        clusterSize[rootB] = nextSize;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            rootIdx[i] = i;
            clusterSize[i] = 1;
        }
        char op[3];
        int a, b;
        for (int i = 0; i < m; ++i) {
            scanf("%s", op);
            if (op[0] == 'C') {
                scanf("%d%d", &a, &b);
                mergeSets(a, b);
            } else if (op[1] == '1') {
                scanf("%d%d", &a, &b);
                if (findRoot(a) == findRoot(b)) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            } else {
                scanf("%d", &a);
                printf("%d\n", clusterSize[findRoot(a)]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0837_H
