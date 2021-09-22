//
// Created by Fengwei Zhang on 9/21/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1275_H
#define ACWINGSOLUTION_PROBLEM1275_H

#include <iostream>

using namespace std;

class Problem1275 {
private:
    struct Node {
        int l, r, v;
    };

    const int N = 200005;
    Node nodes[N * 4];

    void buildTree(const int idx, const int l, const int r) {
        nodes[idx].l = l;
        nodes[idx].r = r;
        if (l == r) {
            return;
        }
        auto mid = (l + r) >> 1;
        buildTree(idx << 1, l, mid);
        buildTree(idx << 1 | 1, mid + 1, r);
    }

    int queryMax(int idx, int l, int r) {
        if (nodes[idx].l >= l && nodes[idx].r <= r) {
            return nodes[idx].v;
        }
        auto mid = (nodes[idx].l + nodes[idx].r) >> 1;
        if (r <= mid) {
            return queryMax(idx << 1, l, r);
        }
        if (l > mid) {
            return queryMax(idx << 1 | 1, l, r);
        }
        return max(queryMax(idx << 1, l, r), queryMax(idx << 1 | 1, l, r));
    }

    void modifyNode(const int idx, const int x, const int v) {
        if (nodes[idx].l == nodes[idx].r) {
            nodes[idx].v = v;
            return;
        }
        int mid = (nodes[idx].l + nodes[idx].r) >> 1;
        if (x <= mid) {
            modifyNode(idx << 1, x, v);
        } else {
            modifyNode(idx << 1 | 1, x, v);
        }
        nodes[idx].v = max(nodes[idx << 1].v, nodes[idx << 1 | 1].v);
    }

    int main() {
        int n = 0, lastResult = 0;
        int m, MOD;
        cin >> m >> MOD;
        buildTree(1, 1, m);
        char op;
        int t;
        while (m--) {
            cin >> op >> t;
            if (op == 'A') {
                ++n;
                modifyNode(1, n, (int) (((long long) t + lastResult) % MOD));
            } else {
                lastResult = queryMax(1, n - t + 1, n);
                cout << lastResult << endl;
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1275_H
