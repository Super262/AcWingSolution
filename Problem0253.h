//
// Created by Fengwei Zhang on 12/19/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0253_H
#define ACWINGSOLUTION_PROBLEM0253_H

#include <iostream>

using namespace std;

class Problem0253 {
private:
    static const int INF = 0x3f3f3f3f;
    static const bool RED = true;
    static const bool BLACK = false;

    struct Node {
        int key;
        Node *left;
        Node *right;
        bool color;  // true: red; false: black
        int rank;
        int cnt;

        explicit Node(int key) {
            this->key = key;
            left = nullptr;
            right = nullptr;
            color = RED;
            rank = 1;
            cnt = 1;
        }
    };

    class RBTree {
    public:
        RBTree() {
            root = nullptr;
        }

        void insertKey(int key) {
            root = insertKey(root, key);
            root->color = BLACK;
            reRank(root);
        }

        void removeKey(int key) {
            auto node = getNode(root, key);
            if (!node) {
                return;
            }
            root = removeKey(root, key);
            if (!root) {
                return;
            }
            reRank(root);
        }

        int getRankByKey(int key) {
            return getRankByKey(root, key);
        }

        int getKeyByRank(int rank) {
            return getKeyByRank(root, rank);
        }

        int getPreKey(int key) {
            return getPreKey(root, key);
        }

        int getNextKey(int key) {
            return getNextKey(root, key);
        }

    private:
        Node *root;

        static int getRank(Node *node) {
            if (!node) {
                return 0;
            }
            return node->rank;
        }

        static int calRank(Node *node) {
            return getRank(node->left) + getRank(node->right) + node->cnt;
        }

        static void reRank(Node *node) {
            if (!node) {
                return;
            }
            node->rank = calRank(node);
        }

        static bool isRed(Node *node) {
            if (!node) {
                return BLACK;
            }
            return node->color;
        }

        static Node *leftRotate(Node *node) {
            auto x = node->right;
            node->right = x->left;
            x->left = node;
            x->color = node->color;
            node->color = RED;
            reRank(node);
            reRank(x);
            return x;
        }

        static Node *rightRotate(Node *node) {
            auto x = node->left;
            node->left = x->right;
            x->right = node;
            x->color = node->color;
            node->color = RED;
            reRank(node);
            reRank(x);
            return x;
        }

        static void setAsRed(Node *node) {
            node->color = RED;
            node->left->color = BLACK;
            node->right->color = BLACK;
        }

        static Node *getNode(Node *node, int key) {
            while (node && key != node->key) {
                if (key < node->key) {
                    node = node->left;
                } else {
                    node = node->right;
                }
            }
            return node;
        }

        static Node *getMinNode(Node *node) {
            if (!node) {
                return nullptr;
            }
            while (node->left) {
                node = node->left;
            }
            return node;
        }

        static Node *removeMinNode(Node *node) {
            if (!node->left) {
                auto x = node->right;
                node->right = nullptr;
                reRank(x);
                return x;
            }
            node->left = removeMinNode(node->left);
            reRank(node);
            return node;
        }

        static Node *insertKey(Node *node, int key) {
            if (!node) {
                return new Node(key);
            }
            if (key < node->key) {
                node->left = insertKey(node->left, key);
            } else if (key > node->key) {
                node->right = insertKey(node->right, key);
            } else {
                ++node->cnt;
                reRank(node);
                return node;
            }
            if (!isRed(node->left) && isRed(node->right)) {
                node = leftRotate(node);
            }
            if (isRed(node->left) && isRed(node->left->left)) {
                node = rightRotate(node);
            }
            if (isRed(node->left) && isRed(node->right)) {
                setAsRed(node);
            }
            reRank(node);
            return node;
        }

        static Node *removeKey(Node *node, int key) {
            if (!node) {
                return nullptr;
            }
            if (key < node->key) {
                node->left = removeKey(node->left, key);
                reRank(node);
                return node;
            }
            if (key > node->key) {
                node->right = removeKey(node->right, key);
                reRank(node);
                return node;
            }
            if (node->cnt > 1) {
                --node->cnt;
                reRank(node);
                return node;
            }
            if (!node->left) {
                auto x = node->right;
                node->right = nullptr;
                reRank(x);
                return x;
            }
            if (!node->right) {
                auto x = node->left;
                node->left = nullptr;
                reRank(x);
                return x;
            }
            auto successor = getMinNode(node->right);
            successor->right = removeMinNode(node->right);
            reRank(successor->right);
            successor->left = node->left;
            node->left = nullptr;
            node->right = nullptr;
            reRank(successor);
            return successor;
        }

        static int getRankByKey(Node *node, int key) {
            if (!node) {
                return 0;
            }
            if (key > node->key) {
                return getRank(node->left) + node->cnt + getRankByKey(node->right, key);
            }
            if (key < node->key) {
                return getRankByKey(node->left, key);
            }
            return getRank(node->left) + 1;
        }

        static int getKeyByRank(Node *node, int rank) {
            if (!node) {
                return INF;
            }
            auto leftRank = getRank(node->left);
            if (rank <= leftRank) {
                return getKeyByRank(node->left, rank);
            }
            if (rank <= leftRank + node->cnt) {
                return node->key;
            }
            return getKeyByRank(node->right, rank - leftRank - node->cnt);
        }

        static int getPreKey(Node *node, int key) {
            if (!node) {
                return -INF;
            }
            if (key <= node->key) {
                return getPreKey(node->left, key);
            }
            return max(node->key, getPreKey(node->right, key));
        }

        static int getNextKey(Node *node, int key) {
            if (!node) {
                return INF;
            }
            if (key >= node->key) {
                return getNextKey(node->right, key);
            }
            return min(node->key, getNextKey(node->left, key));
        }
    };

    int main() {
        int n;
        scanf("%d", &n);
        RBTree rbTree;
        rbTree.insertKey(-INF);
        rbTree.insertKey(INF);
        while (n--) {
            int op;
            int val;
            scanf("%d%d", &op, &val);
            if (op == 1) {
                rbTree.insertKey(val);
            } else if (op == 2) {
                rbTree.removeKey(val);
            } else if (op == 3) {
                printf("%d\n", rbTree.getRankByKey(val) - 1);
            } else if (op == 4) {
                printf("%d\n", rbTree.getKeyByRank(val + 1));
            } else if (op == 5) {
                printf("%d\n", rbTree.getPreKey(val));
            } else {
                printf("%d\n", rbTree.getNextKey(val));
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0253_H
