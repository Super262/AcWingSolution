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
    unsigned long findRoot(vector<unsigned long> &root, const unsigned long &target) {
        // 通过递归完成路径压缩
        if (target != root[target]) {  // 判断当前节点是否是根结点
            root[target] = findRoot(root, root[target]);
        }
        return root[target];
    }

    void mergeSets(vector<unsigned long> &root, const unsigned long &a, const unsigned long &b) {
        root[findRoot(root, a)] = findRoot(root, b);   // 修改根结点
        findRoot(root, a);   // 路径压缩
    }

    int main() {
        unsigned long n, m;
        scanf("%ld%ld", &n, &m);
        vector<unsigned long> root(n + 1, 0);
        for (unsigned long i = 1; i <= n; ++i) {
            root[i] = i;
        }
        unsigned long a, b;
        while (m--) {
            char op[2];
            scanf("%s", op);
            scanf("%ld%ld", &a, &b);
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
