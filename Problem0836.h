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
    int rootIdx[100010];

    int findRoot(const int x) {
        if (rootIdx[x] != x) {
            rootIdx[x] = findRoot(rootIdx[x]);
        }
        return rootIdx[x];
    }

    void mergeSets(const int a, const int b) {
        rootIdx[findRoot(a)] = rootIdx[findRoot(b)];
        findRoot(a);
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            rootIdx[i] = i;
        }
        char op[2];
        int a, b;
        for (int i = 0; i < m; ++i) {
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'M') {
                mergeSets(a, b);
            } else {
                if (findRoot(a) == findRoot(b)) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0836_H
