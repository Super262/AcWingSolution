//
// Created by Fengwei Zhang on 3/24/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0256_H
#define ACWINGSOLUTION_PROBLEM0256_H

#include <iostream>

using namespace std;

class Problem0256 {
private:
    static const int K = 23;

    struct Node {
        int max_ver;
        Node *kids[2]{};

        Node() {
            max_ver = -1;
            for (auto &item: kids) {
                item = nullptr;
            }
        }
    };

    void insert(const int &k, const int s[], Node *prev, Node *cur) {
        cur->max_ver = k;
        for (auto i = K; i >= 0; --i) {
            auto j = (s[k] >> i) & 1;
            if (prev) {
                cur->kids[j ^ 1] = prev->kids[j ^ 1];
                prev = prev->kids[j];
            }
            cur->kids[j] = new Node();
            cur->kids[j]->max_ver = k;
            cur = cur->kids[j];
        }
    }

    int query(Node *root, const int &st, const int &val, const int s[]) {
        for (auto i = K; i >= 0; --i) {
            auto j = (val >> i) & 1;
            if (root->kids[j ^ 1] && root->kids[j ^ 1]->max_ver >= st) {
                root = root->kids[j ^ 1];
            } else {
                root = root->kids[j];
            }
        }
        return val ^ s[root->max_ver];
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int s[n + m + 1];
        Node *root[n + m + 1];

        s[0] = 0;
        root[0] = new Node();
        insert(0, s, nullptr, root[0]);

        int x;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            root[i] = new Node();
            s[i] = s[i - 1] ^ x;
            insert(i, s, root[i - 1], root[i]);
        }

        char op[2];
        int l, r;
        while (m--) {
            scanf("%s", op);
            if (op[0] == 'A') {
                scanf("%d", &x);
                ++n;
                root[n] = new Node();
                s[n] = s[n - 1] ^ x;
                insert(n, s, root[n - 1], root[n]);
            } else {
                scanf("%d%d%d", &l, &r, &x);
                printf("%d\n", query(root[r - 1], l - 1, s[n] ^ x, s));
            }
        }

        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0256_H
