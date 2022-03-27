//
// Created by Fengwei Zhang on 3/26/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0246_H
#define ACWINGSOLUTION_PROBLEM0246_H

#include <iostream>

using namespace std;

class Problem0246 {
    // 利用GCD的性质和差分来简化运算：https://www.acwing.com/solution/content/42739/
private:
    struct Node {
        int l, r;
        long long d;  // 差分数组[l:r]的最大公约数
        long long prefix;  // 差分数组[l:r]的前缀和
        Node() {
            l = -1;
            r = -1;
            d = 0;
            prefix = 0;
        }
    };

    long long gcd(long long a, long long b) {
        while (b) {
            auto t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    void pushUp(Node &u, const Node &l, const Node &r) {
        u.prefix = l.prefix + r.prefix;
        u.d = gcd(l.d, r.d);
    }

    void pushUp(int u, Node tree[]) {
        pushUp(tree[u], tree[u << 1], tree[u << 1 | 1]);
    }

    void increase(int u, int idx, long long val, Node tree[]) {
        if (tree[u].l == idx && tree[u].r == idx) {
            tree[u].d += val;
            tree[u].prefix += val;
            return;
        }
        auto mid = tree[u].l + (tree[u].r - tree[u].l) / 2;
        if (idx <= mid) {
            increase(u << 1, idx, val, tree);
        } else {
            increase(u << 1 | 1, idx, val, tree);
        }
        pushUp(u, tree);
    }

    Node query(int u, int l, int r, Node tree[]) {
        if (l <= tree[u].l && tree[u].r <= r) {
            return tree[u];
        }
        auto mid = tree[u].l + (tree[u].r - tree[u].l) / 2;
        if (r <= mid) {
            return query(u << 1, l, r, tree);
        }
        if (l > mid) {
            return query(u << 1 | 1, l, r, tree);
        }
        auto lp = query(u << 1, l, r, tree);
        auto rp = query(u << 1 | 1, l, r, tree);
        auto res = Node();
        pushUp(res, lp, rp);
        return res;
    }

    void buildTree(int u, int l, int r, Node tree[], const long long arr[]) {
        tree[u].l = l;
        tree[u].r = r;
        if (l == r) {
            tree[u].d = arr[r] - arr[r - 1];
            tree[u].prefix = arr[r] - arr[r - 1];
            return;
        }
        auto mid = l + (r - l) / 2;
        buildTree(u << 1, l, mid, tree, arr);
        buildTree(u << 1 | 1, mid + 1, r, tree, arr);
        pushUp(u, tree);
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        long long arr[n + 1];
        arr[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &arr[i]);
        }
        Node tree[4 * (n + 1)];
        buildTree(1, 1, n, tree, arr);
        while (m--) {
            char op[2];
            int l, r;
            scanf("%s%d%d", op, &l, &r);
            if (op[0] == 'Q') {
                auto lp = query(1, 1, l, tree);
                auto rp = Node();
                if (r > l + 1) {
                    rp = query(1, l + 1, r, tree);
                }
                printf("%lld\n", abs(gcd(lp.prefix, rp.d)));
            } else {
                long long x;
                scanf("%lld", &x);
                increase(1, l, x, tree);
                if (r + 1 <= n) {
                    increase(1, r + 1, -x, tree);
                }
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0246_H
