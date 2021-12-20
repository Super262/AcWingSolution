//
// Created by Fengwei Zhang on 12/19/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0253_H
#define ACWINGSOLUTION_PROBLEM0253_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0253 {
private:
    struct Node {
        int l_child;
        int r_child;
        int key;
        int val;
        int cnt;
        int size;

        Node() {
            l_child = 0;
            r_child = 0;
            key = 0;
            val = 0;
            cnt = 0;
            size = 0;
        }
    };

    const int INF = 0x3f3f3f3f;

    int GetNode(int key, vector<Node> &tr, int &idx) {
        ++idx;
        tr[idx].key = key;
        tr[idx].val = (int) random();
        tr[idx].cnt = 1;
        tr[idx].size = 1;
        return idx;
    }

    void PushUp(int p, vector<Node> &tr) {
        tr[p].size = tr[tr[p].l_child].size + tr[tr[p].r_child].size + tr[p].cnt;
    }

    int BuildTree(vector<Node> &tr, int &idx) {
        auto root = GetNode(-INF, tr, idx);
        tr[root].r_child = GetNode(INF, tr, idx);
        PushUp(root, tr);
        return root;
    }

    void Zig(int &p, vector<Node> &tr) {  // 右旋
        auto q = tr[p].l_child;
        tr[p].l_child = tr[q].r_child;
        tr[q].r_child = p;
        p = q;
        PushUp(tr[p].r_child, tr);
        PushUp(p, tr);
    }

    void Zag(int &p, vector<Node> &tr) {  // 左旋
        auto q = tr[p].r_child;
        tr[p].r_child = tr[q].l_child;
        tr[q].l_child = p;
        p = q;
        PushUp(tr[p].l_child, tr);
        PushUp(p, tr);
    }

    void Insert(int &p, int key, vector<Node> &tr, int &idx) {
        if (!p) {
            p = GetNode(key, tr, idx);
        } else if (tr[p].key == key) {
            ++tr[p].cnt;
        } else if (tr[p].key > key) {
            Insert(tr[p].l_child, key, tr, idx);
            if (tr[tr[p].l_child].val > tr[p].val) {
                Zig(p, tr);
            }
        } else {
            Insert(tr[p].r_child, key, tr, idx);
            if (tr[tr[p].r_child].val > tr[p].val) {
                Zag(p, tr);
            }
        }
        PushUp(p, tr);
    }

    void Erase(int &p, int key, vector<Node> &tr) {
        if (!p) {
            return;
        }
        if (tr[p].key == key) {
            if (tr[p].cnt > 1) {
                --tr[p].cnt;
            } else if (tr[p].l_child || tr[p].r_child) {
                if (!tr[p].r_child || tr[tr[p].l_child].val > tr[tr[p].r_child].val) {
                    Zig(p, tr);
                    Erase(tr[p].r_child, key, tr);
                } else {
                    Zag(p, tr);
                    Erase(tr[p].l_child, key, tr);
                }
            } else {
                p = 0;
            }
        } else if (tr[p].key > key) {
            Erase(tr[p].l_child, key, tr);
        } else {
            Erase(tr[p].r_child, key, tr);
        }
        PushUp(p, tr);
    }

    int GetRankByKey(int p, int key, vector<Node> &tr) {
        if (!p) {
            return 0;
        }
        if (tr[p].key == key) {
            return tr[tr[p].l_child].size + 1;
        }
        if (tr[p].key > key) {
            return GetRankByKey(tr[p].l_child, key, tr);
        }
        return tr[tr[p].l_child].size + tr[p].cnt + GetRankByKey(tr[p].r_child, key, tr);
    }

    int GetKeyByRank(int p, int rank, vector<Node> &tr) {
        if (!p) {
            return INF;
        }
        if (tr[tr[p].l_child].size >= rank) {
            return GetKeyByRank(tr[p].l_child, rank, tr);
        }
        if (tr[tr[p].l_child].size + tr[p].cnt >= rank) {
            return tr[p].key;
        }
        return GetKeyByRank(tr[p].r_child, rank - tr[tr[p].l_child].size - tr[p].cnt, tr);
    }

    int GetPrev(int p, int key, vector<Node> &tr) {
        if (!p) {
            return -INF;
        }
        if (tr[p].key >= key) {
            return GetPrev(tr[p].l_child, key, tr);
        }
        return max(tr[p].key, GetPrev(tr[p].r_child, key, tr));
    }

    int GetNext(int p, int key, vector<Node> &tr) {
        if (!p) {
            return INF;
        }
        if (tr[p].key <= key) {
            return GetNext(tr[p].r_child, key, tr);
        }
        return min(tr[p].key, GetNext(tr[p].l_child, key, tr));
    }

    int main() {
        int n = 0;
        scanf("%d", &n);
        vector<Node> tree(n + 1);
        int idx = 0;
        auto root = BuildTree(tree, idx);
        while (n--) {
            int opt;
            int x;
            scanf("%d%d", &opt, &x);
            if (opt == 1) {
                Insert(root, x, tree, idx);
            } else if (opt == 2) {
                Erase(root, x, tree);
            } else if (opt == 3) {
                printf("%d\n", GetRankByKey(root, x, tree) - 1);
            } else if (opt == 4) {
                printf("%d\n", GetKeyByRank(root, x + 1, tree));
            } else if (opt == 5) {
                printf("%d\n", GetPrev(root, x, tree));
            } else {
                printf("%d\n", GetNext(root, x, tree));
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0253_H
