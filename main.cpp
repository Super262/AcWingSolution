#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
    int l, r;
    int allSum;
    int prefixMax;
    int suffixMax;
    int subMax;
};

const int N = 500005;
Node nodes[N * 4];
int items[N];

void pushUp(Node &root, const Node &lc, const Node &rc) {
    root.allSum = lc.allSum + rc.allSum;
    root.prefixMax = max(lc.allSum + rc.prefixMax, lc.prefixMax);
    root.suffixMax = max(rc.allSum + lc.suffixMax, rc.suffixMax);
    root.subMax = max(max(lc.subMax, rc.subMax), lc.suffixMax + rc.prefixMax);
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
        nodes[idx].allSum = nodes[idx].prefixMax = nodes[idx].suffixMax = nodes[idx].subMax = val;
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
    auto mid = (nodes[idx].l + nodes[idx].r) >> 1;
    if (r <= mid) {
        return queryMax(idx << 1, l, r);
    }
    if (l > mid) {
        return queryMax(idx << 1 | 1, l, r);
    }
    Node result;
    memset(&result, 0xCF, sizeof result);
    pushUp(result, queryMax(idx << 1, l, r), queryMax(idx << 1 | 1, l, r));
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
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            printf("%d\n", queryMax(1, x, y).subMax);
        } else {
            modifyNode(1, x, y);
        }
    }
    return 0;
}
