//
// Created by Fengwei Zhang on 2021/6/7.
//

#ifndef ACWINGSOLUTION_PROBLEM0143_H
#define ACWINGSOLUTION_PROBLEM0143_H

#include <iostream>

using namespace std;

class Problem0143 {
private:
    struct Node {
        Node *next[2]{};

        Node() {
            next[0] = nullptr;
            next[1] = nullptr;
        }
    };

    void insertNum(Node *root, const unsigned int num) {
        auto p = root;
        for (int i = 30; i >= 0; --i) {
            if ((num >> i) & 1) {
                if (!p->next[1]) {
                    p->next[1] = new Node();
                }
                p = p->next[1];
            } else {
                if (!p->next[0]) {
                    p->next[0] = new Node();
                }
                p = p->next[0];
            };
        }
    }

    unsigned int maxXOR(Node *root, const unsigned int num) {
        unsigned int result = 0;
        auto p = root;
        for (int i = 30; i >= 0; --i) {
            result *= 2;
            if ((num >> i) & 1) {
                if (p->next[0]) {
                    p = p->next[0];
                    result += 1;
                } else {
                    p = p->next[1];
                }
            } else {
                if (p->next[1]) {
                    p = p->next[1];
                    result += 1;
                } else {
                    p = p->next[0];
                }
            };
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        unsigned int num;
        auto root = new Node();
        unsigned int result = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num);
            insertNum(root, num);
            result = max(result, maxXOR(root, num));
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0143_H
