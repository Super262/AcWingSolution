//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0240_H
#define ACWINGSOLUTION_PROBLEM0240_H

#include <iostream>

using namespace std;

class Problem0240 {
public:
    int findRoot(const int target, vector<int> &parent, vector<int> &distanceToParent) {
        if (target != parent[target]) {
            int r = findRoot(parent[target], parent, distanceToParent);
            distanceToParent[target] += distanceToParent[parent[target]];
            parent[target] = r;
        }
        return parent[target];
    }

    int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> parent(n + 1, 0);
        vector<int> distanceToParent(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        int op, a, b;
        int result = 0;
        for (int i = 0; i < k; ++i) {
            scanf("%d%d%d", &op, &a, &b);
            if(a > n || b > n) {
                ++result;
                continue;
            }
            auto ra = findRoot(a, parent, distanceToParent);
            auto rb = findRoot(b, parent, distanceToParent);
            if (op == 1) {
                if (ra == rb && (distanceToParent[a] - distanceToParent[b]) % 3) {
                    ++result;
                } else if (ra != rb) {
                    parent[ra] = rb;
                    distanceToParent[ra] = distanceToParent[b] - distanceToParent[a];
                }
            } else {
                if (ra == rb && (distanceToParent[a] - distanceToParent[b] - 1) % 3) {
                    ++result;
                } else if (ra != rb) {
                    parent[ra] = rb;
                    distanceToParent[ra] = distanceToParent[b] - distanceToParent[a] + 1;
                }
            }
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0240_H
