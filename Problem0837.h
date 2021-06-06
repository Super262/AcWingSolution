//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0837_H
#define ACWINGSOLUTION_PROBLEM0837_H

#include <vector>
#include <iostream>

using namespace std;


class Problem0837 {
public:
    unsigned long findRoot(vector<unsigned long> &root, const unsigned long &target) {
        if (root[target] != target) {
            root[target] = findRoot(root, root[target]);
        }
        return root[target];
    }

    void mergeSets(vector<unsigned long> &root,
                   vector<unsigned long> &count,
                   const unsigned long &a,
                   const unsigned long &b) {
        unsigned long rootOfA = findRoot(root, a);
        unsigned long rootOfB = findRoot(root, b);
        if (rootOfA == rootOfB) {
            return;
        }
        unsigned long sum = count[rootOfA] + count[rootOfB];
        root[rootOfA] = rootOfB;
        rootOfA = findRoot(root, a);
        count[rootOfA] = sum;
    }

    int main() {
        unsigned long n, m;
        scanf("%ld%ld", &n, &m);
        vector<unsigned long> root(n + 1, 0);
        vector<unsigned long> setSize(n + 1, 1);  // 规定：只有根结点的count有意义
        for (unsigned long i = 1; i <= n; ++i) {
            root[i] = i;
        }
        char op[3];
        unsigned long a, b;
        while (m--) {
            scanf("%s", op);
            if (op[0] == 'C') {
                scanf("%ld%ld", &a, &b);
                mergeSets(root, setSize, a, b);
            } else if (op[1] == '1') {
                scanf("%ld%ld", &a, &b);
                if (findRoot(root, a) == findRoot(root, b)) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            } else {
                scanf("%ld", &a);
                printf("%ld\n", setSize[findRoot(root, a)]);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0837_H
