//
// Created by Fengwei Zhang on 9/21/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0243_H
#define ACWINGSOLUTION_PROBLEM0243_H

#include <iostream>

using namespace std;

class Problem0243 {
private:
    // 线段树解法
    struct Node {
        int l, r;
        long long sumOfKids;  // 子节点和
        long long incrementForKids;  // "懒"标记：未来操作前，应对子节点施加的增量值
    };

    const int N = 100010;
    Node nodes[N * 4];
    int items[N];

    void pushUp(const int idx) {
        nodes[idx].sumOfKids = nodes[idx << 1].sumOfKids + nodes[idx << 1 | 1].sumOfKids;
    }

    void pushDown(const int idx) {
        auto &root = nodes[idx];
        if (root.incrementForKids == 0) {
            return;
        }
        auto &lc = nodes[idx << 1];
        auto &rc = nodes[idx << 1 | 1];

        lc.incrementForKids += root.incrementForKids;
        rc.incrementForKids += root.incrementForKids;

        // 不要忘记这里的类型转换
        lc.sumOfKids += (long long) (lc.r - lc.l + 1) * root.incrementForKids;
        rc.sumOfKids += (long long) (rc.r - rc.l + 1) * root.incrementForKids;

        root.incrementForKids = 0;
    }

    void buildTree(const int idx, const int l, const int r) {
        nodes[idx].l = l;
        nodes[idx].r = r;
        if (l == r) {
            nodes[idx].sumOfKids = items[r];
            nodes[idx].incrementForKids = 0;
            return;
        }
        auto mid = l + ((r - l) >> 1);
        buildTree(idx << 1, l, mid);
        buildTree(idx << 1 | 1, mid + 1, r);
        pushUp(idx);
    }

    void increaseRange(const int idx, const int l, const int r, const int val) {
        if (nodes[idx].l >= l && nodes[idx].r <= r) {
            nodes[idx].sumOfKids += (long long) (nodes[idx].r - nodes[idx].l + 1) * val;
            nodes[idx].incrementForKids += val;
            return;
        }
        // 先向下应用当前标记，在做其它处理
        pushDown(idx);
        auto mid = nodes[idx].l + ((nodes[idx].r - nodes[idx].l) >> 1);
        if (l <= mid) {
            increaseRange(idx << 1, l, r, val);
        }
        if (r > mid) {
            increaseRange(idx << 1 | 1, l, r, val);
        }
        pushUp(idx);
    }

    long long queryRange(const int idx, const int l, const int r) {
        if (nodes[idx].l >= l && nodes[idx].r <= r) {
            return nodes[idx].sumOfKids;
        }
        pushDown(idx);
        auto mid = nodes[idx].l + ((nodes[idx].r - nodes[idx].l) >> 1);
        long long result = 0;
        if (l <= mid) {
            result += queryRange(idx << 1, l, r);
        }
        if (r > mid) {
            result += queryRange(idx << 1 | 1, l, r);
        }
        return result;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &items[i]);
        }
        buildTree(1, 1, n);
        char op[2];
        int l, r, val;
        while (m--) {
            scanf("%s%d%d", op, &l, &r);
            if (op[0] == 'C') {
                scanf("%d", &val);
                increaseRange(1, l, r, val);
            } else {
                printf("%lld\n", queryRange(1, l, r));
            }
        }
        return 0;
    }

    // 树状数组解法：https://www.acwing.com/solution/content/44886/
//    const int N = 100010;
//    long long ft1[N], ft2[N], nums[N];
//
//    int lowBit(const int x) {
//        return x & -x;
//    }
//
//    void updateItem(long long ft[], const int idx, const long long val, const int n) {
//        for (auto i = idx; i <= n; i += lowBit(i)) {
//            ft[i] += val;
//        }
//    }
//
//    long long prefixSum(const long long ft[], const int idx) {
//        long long res = 0;
//        for (auto i = idx; i > 0; i -= lowBit(i)) {
//            res += ft[i];
//        }
//        return res;
//    }
//
//    int main() {
//        int n, m;
//        scanf("%d%d", &n, &m);
//        for (int i = 1; i <= n; ++i) {
//            scanf("%lld", &nums[i]);
//        }
//        for (int i = 1; i <= n; ++i) {
//            int d = nums[i] - nums[i - 1];
//            updateItem(ft1, i, d, n);
//            updateItem(ft2, i, (long long) d * i, n);
//        }
//        char op[2];
//        int x1, x2, d;
//        for (int i = 0; i < m; ++i) {
//            scanf("%s%d%d", op, &x1, &x2);
//            if (op[0] == 'Q') {
//                printf("%lld\n", (prefixSum(ft1, x2) * (x2 + 1) - prefixSum(ft2, x2)) -
//                                 (prefixSum(ft1, x1 - 1) * x1 - prefixSum(ft2, x1 - 1)));
//            } else {
//                scanf("%d", &d);
//                updateItem(ft1, x1, d, n);
//                updateItem(ft2, x1, (long long) x1 * d, n);
//                updateItem(ft1, x2 + 1, -d, n);
//                updateItem(ft2, x2 + 1, -(long long) (x2 + 1) * d, n);
//            }
//        }
//        return 0;
//    }

};

#endif //ACWINGSOLUTION_PROBLEM0243_H
