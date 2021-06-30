//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0836_H
#define ACWINGSOLUTION_PROBLEM0836_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0836 {
public:
    unsigned long findRoot(vector<unsigned long> &root, const unsigned long target) {
        if (target != root[target]) {
            root[target] = findRoot(root, root[target]);
        }
        return root[target];
    }

    void mergeSets(vector<unsigned long> &root, const unsigned long a, const unsigned long b) {
        root[findRoot(root, a)] = findRoot(root, b);
        findRoot(root, a);
    }

    int main() {
        unsigned long n, m;
        scanf("%ld%ld", &n, &m);
        vector<unsigned long> root(n + 1, 0);
        for (unsigned long i = 1; i <= n; ++i) {
            root[i] = i;
        }
        char op[2];
        unsigned long a, b;
        for (unsigned long i = 0; i < m; ++i) {
            scanf("%s%ld%ld", op, &a, &b);
            if (op[0] == 'M') {
                mergeSets(root, a, b);
            } else {
                if (findRoot(root, a) == findRoot(root, b)) {
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
