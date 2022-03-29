//
// Created by Fengwei Zhang on 12/19/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0253_H
#define ACWINGSOLUTION_PROBLEM0253_H

#include <iostream>

using namespace std;

class Problem0253 {
private:
    struct Node {
        int l;
        int r;
        int key;  // 用于BST
        int val;  // 用于大根堆
        int cnt;  // 重复数字的频率
        int size; // 当前子树包含的数字个数

        Node() {
            l = 0;
            r = 0;
            key = 0;
            val = 0;
            cnt = 0;
            size = 0;
        }
    };

    const int INF = 0x3f3f3f3f;

    int createNode(int key, Node tr[], int &idx) {
        ++idx;
        tr[idx].key = key;
        tr[idx].val = (int) random();
        tr[idx].cnt = 1;
        tr[idx].size = 1;
        return idx;
    }

    void pushUp(int p, Node tr[]) {
        tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
    }

    int buildTree(Node tr[], int &idx) {
        auto root = createNode(-INF, tr, idx);  // 两个"哨兵"：INF和-INF
        tr[root].r = createNode(INF, tr, idx);
        pushUp(root, tr);
        return root;
    }

    void zig(int &p, Node tr[]) {  // 右旋
        auto q = tr[p].l;
        tr[p].l = tr[q].r;
        tr[q].r = p;
        p = q;
        pushUp(tr[p].r, tr);
        pushUp(p, tr);
    }

    void zag(int &p, Node tr[]) {  // 左旋
        auto q = tr[p].r;
        tr[p].r = tr[q].l;
        tr[q].l = p;
        p = q;
        pushUp(tr[p].l, tr);
        pushUp(p, tr);
    }

    void insert(int &p, int key, Node tr[], int &idx) {
        if (!p) {
            p = createNode(key, tr, idx);
        } else if (tr[p].key == key) {
            ++tr[p].cnt;
        } else if (tr[p].key > key) {
            insert(tr[p].l, key, tr, idx);
            if (tr[tr[p].l].val > tr[p].val) {
                zig(p, tr);
            }
        } else {
            insert(tr[p].r, key, tr, idx);
            if (tr[tr[p].r].val > tr[p].val) {
                zag(p, tr);
            }
        }
        pushUp(p, tr);
    }

    void erase(int &p, int key, Node tr[]) {
        if (!p) {
            return;
        }
        if (tr[p].key == key) {
            if (tr[p].cnt > 1) {
                --tr[p].cnt;
            } else if (tr[p].l || tr[p].r) {
                if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) {
                    zig(p, tr);
                    erase(tr[p].r, key, tr);
                } else {
                    zag(p, tr);
                    erase(tr[p].l, key, tr);
                }
            } else {
                p = 0;
            }
        } else if (tr[p].key > key) {
            erase(tr[p].l, key, tr);
        } else {
            erase(tr[p].r, key, tr);
        }
        pushUp(p, tr);
    }

    int getRankByKey(int p, int key, Node tr[]) {
        if (!p) {
            return 0;
        }
        if (tr[p].key == key) {
            return tr[tr[p].l].size + 1;
        }
        if (tr[p].key > key) {
            return getRankByKey(tr[p].l, key, tr);
        }
        return tr[tr[p].l].size + tr[p].cnt + getRankByKey(tr[p].r, key, tr);
    }

    int getKeyByRank(int p, int rank, Node tr[]) {
        if (!p) {
            return INF;
        }
        if (tr[tr[p].l].size >= rank) {
            return getKeyByRank(tr[p].l, rank, tr);
        }
        if (tr[tr[p].l].size + tr[p].cnt >= rank) {
            return tr[p].key;
        }
        return getKeyByRank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt, tr);
    }

    int getPrev(int p, int key, Node tr[]) {
        if (!p) {
            return -INF;
        }
        if (tr[p].key >= key) {
            return getPrev(tr[p].l, key, tr);
        }
        return max(tr[p].key, getPrev(tr[p].r, key, tr));
    }

    int getNext(int p, int key, Node tr[]) {
        if (!p) {
            return INF;
        }
        if (tr[p].key <= key) {
            return getNext(tr[p].r, key, tr);
        }
        return min(tr[p].key, getNext(tr[p].l, key, tr));
    }

    int main() {
        int n = 0;
        scanf("%d", &n);
        Node tree[n + 1];
        int idx = 0;
        auto root = buildTree(tree, idx);
        while (n--) {
            int opt;
            int x;
            scanf("%d%d", &opt, &x);
            if (opt == 1) {
                insert(root, x, tree, idx);
            } else if (opt == 2) {
                erase(root, x, tree);
            } else if (opt == 3) {
                printf("%d\n", getRankByKey(root, x, tree) - 1);
            } else if (opt == 4) {
                printf("%d\n", getKeyByRank(root, x + 1, tree));
            } else if (opt == 5) {
                printf("%d\n", getPrev(root, x, tree));
            } else {
                printf("%d\n", getNext(root, x, tree));
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0253_H
