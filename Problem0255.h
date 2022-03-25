//
// Created by Fengwei Zhang on 3/25/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0255_H
#define ACWINGSOLUTION_PROBLEM0255_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Problem0255 {
private:
    struct Node {
        int l, r;
        int cnt;

        Node() {
            l = -1;
            r = -1;
            cnt = 0;
        }
    };

    int getIdx(const int x, const vector<int> &data) {  // 有效返回值从0开始
        return (int) (lower_bound(data.begin(), data.end(), x) - data.begin());
    }

    int buildTree(int l, int r, int &idx, Node tree[]) {
        ++idx;
        auto p = idx;
        if (l == r) {
            return p;
        }
        auto mid = l + (r - l) / 2;
        tree[p].l = buildTree(l, mid, idx, tree);
        tree[p].r = buildTree(mid + 1, r, idx, tree);
        return p;
    }

    int query(int q, int p, int l, int r, int k, Node tree[]) {
        if (l == r) {
            return r;
        }
        auto cnt = tree[tree[q].l].cnt - tree[tree[p].l].cnt;
        auto mid = l + (r - l) / 2;
        if (k <= cnt) {
            return query(tree[q].l, tree[p].l, l, mid, k, tree);
        }
        return query(tree[q].r, tree[p].r, mid + 1, r, k - cnt, tree);
    }

    int insert(int p, int l, int r, int x, int &idx, Node tree[]) {  // 插入数据，返回新版本的节点编号
        ++idx;
        auto q = idx;
        tree[q] = tree[p];
        if (l == r) {
            ++tree[q].cnt;
            return q;
        }
        auto mid = l + (r - l) / 2;
        if (x <= mid) {
            tree[q].l = insert(tree[p].l, l, mid, x, idx, tree);
        } else {
            tree[q].r = insert(tree[p].r, mid + 1, r, x, idx, tree);
        }
        tree[q].cnt = tree[tree[q].l].cnt + tree[tree[q].r].cnt;
        return q;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        Node tree[(n + 1) * 21];
        int root[n + 1];  // 保存每个版本的根节点的编号
        int arr[n + 1];
        vector<int> data;
        data.reserve(n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
            data.emplace_back(arr[i]);
        }
        sort(data.begin(), data.end());  // 离散化
        data.erase(unique(data.begin(), data.end()), data.end());
        int idx = 0;
        root[0] = buildTree(0, (int) data.size() - 1, idx, tree);
        for (int i = 1; i <= n; ++i) {
            root[i] = insert(root[i - 1], 0, (int) data.size() - 1, getIdx(arr[i], data), idx, tree);
        }
        while (m--) {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", data[query(root[r], root[l - 1], 0, (int) data.size() - 1, k, tree)]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0255_H
