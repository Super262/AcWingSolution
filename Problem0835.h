//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0835_H
#define ACWINGSOLUTION_PROBLEM0835_H

#include <iostream>

class Problem0835
{
    // 完整背诵这部分代码！
private:
    struct Node
    {
        int cnt;
        Node *children[26]{};

        Node()
        {
            cnt = 0;
            for (auto &item : children)
            {
                item = nullptr;
            }
        }
    };

    void insert_str(Node *root, const char *str)
    {
        auto current = root;
        for (int i = 0, idx; str[i]; ++i)
        {
            idx = str[i] - 'a';
            if (!current->children[idx])
            {
                current->children[idx] = new Node();
            }
            current = current->children[idx];
        }
        ++current->cnt;
    }

    int query_str(Node *root, const char *str)
    {
        auto current = root;
        for (int i = 0, idx; str[i]; ++i)
        {
            idx = str[i] - 'a';
            if (!current->children[idx])
            {
                return 0;
            }
            current = current->children[idx];
        }
        return current->cnt;
    }

    int main()
    {
        char str[100010];
        char op[2];
        int n;
        scanf("%d", &n);
        auto root = new Node();
        for (int i = 0; i < n; ++i)
        {
            scanf("%s%s", op, str);
            if (op[0] == 'I')
            {
                insert_str(root, str);
            }
            else
            {
                printf("%d\n", query_str(root, str));
            }
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0835_H
