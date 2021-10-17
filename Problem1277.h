//
// Created by Fengwei Zhang on 10/16/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1277_H
#define ACWINGSOLUTION_PROBLEM1277_H

#include <iostream>

using namespace std;

class Problem1277 {
private:
    struct Node {
        int l, r;
        int sum;
        int add, mul;
    };

    const int N = 100005;
    Node nodes[4 * N];
    int items[N];

    void pushUp(const int idx, const int p) {
        nodes[idx].sum = (int) (((long long) nodes[idx << 1].sum + nodes[idx << 1 | 1].sum) % p);
    }

    void eval(const int idx, const int mul, const int add, const int p) {
        nodes[idx].sum = (int) (
                ((long long) nodes[idx].sum * mul + (long long) (nodes[idx].r - nodes[idx].l + 1) * add) % p);
        nodes[idx].mul = (int) ((long long) nodes[idx].mul * mul % p);
        nodes[idx].add = (int) (((long long) nodes[idx].add * mul + add) % p);
    }

    void pushDown(const int idx, const int p) {
        eval(idx << 1, nodes[idx].mul, nodes[idx].add, p);
        eval(idx << 1 | 1, nodes[idx].mul, nodes[idx].add, p);
        nodes[idx].mul = 1;
        nodes[idx].add = 0;
    }

    void buildTree(const int idx, const int l, const int r, const int p) {
        nodes[idx] = {l, r, 0, 0, 1};
        if (l == r) {
            nodes[idx].sum = items[l] % p;
            return;
        }
        auto mid = l + (r - l) / 2;
        buildTree(idx << 1, l, mid, p);
        buildTree(idx << 1 | 1, mid + 1, r, p);
        pushUp(idx, p);
    }

    void modifyRange(const int idx, const int l, const int r, const int mul, const int add, const int p) {
        if (nodes[idx].l >= l && nodes[idx].r <= r) {
            eval(idx, mul, add, p);
            return;
        }
        pushDown(idx, p);
        auto mid = nodes[idx].l + (nodes[idx].r - nodes[idx].l) / 2;
        if (l <= mid) {
            modifyRange(idx << 1, l, r, mul, add, p);
        }
        if (r > mid) {
            modifyRange(idx << 1 | 1, l, r, mul, add, p);
        }
        pushUp(idx, p);
    }

    int queryRange(const int idx, const int l, const int r, const int p) {
        if (l <= nodes[idx].l && nodes[idx].r <= r) {
            return nodes[idx].sum;
        }
        pushDown(idx, p);
        int result = 0;
        auto mid = nodes[idx].l + (nodes[idx].r - nodes[idx].l) / 2;
        if (l <= mid) {
            result = (int) (((long long) result + queryRange(idx << 1, l, r, p)) % p);
        }
        if (r > mid) {
            result = (int) (((long long) result + queryRange(idx << 1 | 1, l, r, p)) % p);
        }
        return result;
    }

    int main() {
        int n, p;
        scanf("%d%d", &n, &p);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &items[i]);
        }
        buildTree(1, 1, n, p);
        int m;
        scanf("%d", &m);
        int op, t, g, c;
        while (m--) {
            scanf("%d%d%d", &op, &t, &g);
            if (op == 1) {
                scanf("%d", &c);
                modifyRange(1, t, g, c, 0, p);
            } else if (op == 2) {
                scanf("%d", &c);
                modifyRange(1, t, g, 1, c, p);
            } else {
                printf("%d\n", queryRange(1, t, g, p));
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1277_H
