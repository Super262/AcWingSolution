//
// Created by Fengwei Zhang on 1/18/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1282_H
#define ACWINGSOLUTION_PROBLEM1282_H

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

class Problem1282 {
private:
    static const int N = 26, M = 1000010;

    struct Node {
        int cnt;
        Node *children[N]{};
        Node *fail;

        Node() {
            cnt = 0;
            memset(children, 0, sizeof children);
            fail = nullptr;
        }
    };

    void InsertWord(Node *root, const char word[]) {
        auto p = root;
        for (int i = 0; word[i]; ++i) {
            int ch = word[i] - 'a';
            if (!p->children[ch]) {
                p->children[ch] = new Node();
            }
            p = p->children[ch];
        }
        ++p->cnt;
    }

    void BuildAC(Node *root) {
        queue<Node *> q;
        q.emplace(root);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < N; ++i) {
                if (!cur->children[i]) {
                    continue;
                }
                if (cur == root) {
                    cur->children[i]->fail = root;
                } else {
                    auto p = cur->fail;
                    while (p != root && !p->children[i]) {
                        p = p->fail;
                    }
                    if (p->children[i]) {
                        p = p->children[i];
                    }
                    cur->children[i]->fail = p;
                }
                q.emplace(cur->children[i]);
            }
        }
    }

    int main() {
        int t;
        scanf("%d", &t);
        char str[M];
        while (t--) {
            memset(str, 0, sizeof str);
            auto root = new Node();
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                scanf("%s", str);
                InsertWord(root, str);
            }
            BuildAC(root);
            scanf("%s", str);
            int res = 0;
            auto r = root;
            for (int i = 0; str[i]; ++i) {
                int ch = str[i] - 'a';
                while (r != root && !r->children[ch]) {
                    r = r->fail;
                }
                if (r->children[ch]) {
                    r = r->children[ch];
                }
                for (auto p = r; p; p = p->fail) {
                    res += p->cnt;
                    p->cnt = 0;
                }
            }
            printf("%d\n", res);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1282_H
