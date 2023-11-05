//
// Created by Fengwei Zhang on 2021/6/7.
//

#ifndef ACWINGSOLUTION_PROBLEM0143_H
#define ACWINGSOLUTION_PROBLEM0143_H

#include <iostream>

using namespace std;

class Problem0143
{
private:
    struct Node
    {
        Node *next[2]{};

        Node()
        {
            next[0] = nullptr;
            next[1] = nullptr;
        }
    };

    void insert_num(Node *p, const int &num)
    {
        for (int i = 30; i >= 0; --i)
        {
            if ((num >> i) & 1)
            {
                if (!p->next[1])
                {
                    p->next[1] = new Node();
                }
                p = p->next[1];
            }
            else
            {
                if (!p->next[0])
                {
                    p->next[0] = new Node();
                }
                p = p->next[0];
            };
        }
    }

    int get_max_xor(Node *p, const int &num)
    {
        int result = 0;
        for (int i = 30; i >= 0; --i)
        {
            result *= 2;
            if ((num >> i) & 1)
            {
                if (p->next[0])
                {
                    p = p->next[0];
                    result += 1;
                }
                else
                {
                    p = p->next[1];
                }
            }
            else
            {
                if (p->next[1])
                {
                    p = p->next[1];
                    result += 1;
                }
                else
                {
                    p = p->next[0];
                }
            };
        }
        return result;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        auto p = new Node();
        int result = 0;
        for (int i = 0, num; i < n; ++i)
        {
            scanf("%d", &num);
            insert_num(p, num);
            result = max(result, get_max_xor(p, num));
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0143_H
