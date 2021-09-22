//
// Created by Fengwei Zhang on 9/21/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0245_H
#define ACWINGSOLUTION_PROBLEM0245_H

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem0245 {
    // https://www.acwing.com/solution/content/19422/
private:
    struct Node {
        int l, r;  // 区间端点
        int allSum;  // 区间和
        int prefixMax;  // 区间最大前缀和
        int suffixMax;  // 区间最大后缀和
        int subMax;  // 区间最大子段和
    };

    const int N = 500010;
    int items[N];
    Node nodes[4 * N];

    void pushUp(Node &root, const Node &lChild, const Node &rChild) {
        root.allSum = lChild.allSum + rChild.allSum;
        root.prefixMax = max(lChild.prefixMax, lChild.allSum + rChild.prefixMax);
        root.suffixMax = max(rChild.suffixMax, rChild.allSum + lChild.suffixMax);
        root.subMax = max(max(lChild.subMax, rChild.subMax), lChild.suffixMax + rChild.prefixMax);
    }

    void buildTree(const int idx, const int l, const int r) {
        nodes[idx].l = l;
        nodes[idx].r = r;
        if (l == r) {
            nodes[idx].allSum = items[r];
            nodes[idx].prefixMax = items[r];
            nodes[idx].suffixMax = items[r];
            nodes[idx].subMax = items[r];
            return;
        }
        auto mid = l + ((r - l) >> 1);
        buildTree(idx << 1, l, mid);
        buildTree(idx << 1 | 1, mid + 1, r);
        pushUp(nodes[idx], nodes[idx << 1], nodes[idx << 1 | 1]);
    }

    void modifyNode(const int idx, const int x, const int val) {
        if (nodes[idx].l == x && nodes[idx].r == x) {
            nodes[idx].allSum = val;
            nodes[idx].prefixMax = val;
            nodes[idx].suffixMax = val;
            nodes[idx].subMax = val;
            return;
        }
        auto mid = nodes[idx].l + ((nodes[idx].r - nodes[idx].l) >> 1);
        if (x <= mid) {
            modifyNode(idx << 1, x, val);
        } else {
            modifyNode(idx << 1 | 1, x, val);
        }
        pushUp(nodes[idx], nodes[idx << 1], nodes[idx << 1 | 1]);
    }

    Node queryMax(const int idx, const int l, const int r) {
        if (nodes[idx].l >= l && nodes[idx].r <= r) {
            return nodes[idx];
        }
        auto mid = nodes[idx].l + ((nodes[idx].r - nodes[idx].l) >> 1);
        if (r <= mid) {
            return queryMax(idx << 1, l, r);
        }
        if (l > mid) {
            return queryMax(idx << 1 | 1, l, r);
        }
        Node result;
        auto lt = queryMax(idx << 1, l, r);
        auto rt = queryMax(idx << 1 | 1, l, r);
        memset(&result, 0xCF, sizeof result);
        pushUp(result, lt, rt);
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &items[i]);
        }
        buildTree(1, 1, n);
        int op, x, y;
        while (m--) {
            scanf("%d%d%d", &op, &x, &y);
            if (op == 1) {
                if (x > y) {
                    swap(x, y);
                }
                printf("%d\n", queryMax(1, x, y).subMax);
            } else {
                modifyNode(1, x, y);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0245_H
