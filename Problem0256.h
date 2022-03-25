//
// Created by Fengwei Zhang on 3/24/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0256_H
#define ACWINGSOLUTION_PROBLEM0256_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0256 {
private:
    static const int N = 600010;
    static const int K = 25;
    static const int M = K * N;

    int s[N];  // s[i] = a[0] ^ a[1] ^ ... a[i]
    int tree[M][2];  // Trie某个节点的索引号
    int max_ver[M];  // max_id[i]：索引号为i的节点的Trie中的最大版本
    int root[N];  // root[i]：版本为i的Trie指向的节点编号
    int idx;

    void insert(int k, int prev, int cur) {
        max_ver[cur] = k;
        for (auto i = K - 2; i >= 0; --i) {  // 由低位向高位插入
            auto j = (s[k] >> i) & 1;
            if (prev) {
                tree[cur][j ^ 1] = tree[prev][j ^ 1];  // 链接旧版本
            }
            tree[cur][j] = ++idx;
            max_ver[tree[cur][j]] = k;
            cur = tree[cur][j];
            prev = tree[prev][j];
        }
    }

    int query(int u, int l, int c) {  // 从s[l]开始查询目标值
        for (int i = K - 2; i >= 0; --i) {
            auto j = (c >> i) & 1;
            if (max_ver[tree[u][j ^ 1]] >= l) {
                u = tree[u][j ^ 1];
            } else {
                u = tree[u][j];
            }
        }
        return c ^ s[max_ver[u]];
    }

    int main() {
        idx = 0;
        int n, m;
        scanf("%d%d", &n, &m);
        s[0] = 0;
        max_ver[0] = -1;
        root[0] = ++idx;
        insert(0, 0, root[0]);
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            root[i] = ++idx;
            s[i] = s[i - 1] ^ x;
            insert(i, root[i - 1], root[i]);
        }
        while (m--) {
            char op[2];
            scanf("%s", op);
            if (op[0] == 'A') {
                int x;
                scanf("%d", &x);
                ++n;
                root[n] = ++idx;
                s[n] = s[n - 1] ^ x;
                insert(n, root[n - 1], root[n]);
            } else {
                int l, r, x;
                scanf("%d%d%d", &l, &r, &x);
                printf("%d\n", query(root[r - 1], l - 1, s[n] ^ x));
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0256_H
