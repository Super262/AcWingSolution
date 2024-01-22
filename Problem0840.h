//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0840_H
#define ACWINGSOLUTION_PROBLEM0840_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0840
{
private:
    bool query_value(const int &value, const vector<int> &head_idx,
                     const vector<int> &next_idx, const vector<int> &storage)
    {
        const auto &n = (int)head_idx.size();
        const auto &r = (value % n + n) % n; // 消除负数的影响
        for (auto idx = head_idx[r]; idx; idx = next_idx[idx])
        {
            if (storage[idx] == value)
            {
                return true;
            }
        }
        return false;
    }

    void insert_value(const int &value, vector<int> &head_idx,
                      vector<int> &next_idx, vector<int> &storage, int &idx)
    {
        if (query_value(value, head_idx, next_idx, storage))
        {
            return;
        }
        const auto &n = (int)head_idx.size();
        const auto &r = (value % n + n) % n; // 消除负数的影响
        if (idx + 1 >= next_idx.size())
        {
            next_idx.emplace_back(0);
        }
        if (idx + 1 >= storage.size())
        {
            storage.emplace_back(0);
        }
        ++idx;
        next_idx[idx] = head_idx[r];
        head_idx[r] = idx;
        storage[idx] = value;
    }

    int main()
    {
        vector<int> head_idx(10002, 0);
        vector<int> next_idx(1, 0);
        vector<int> storage(1);
        int n, idx = 0;
        scanf("%d", &n);
        char op[2];
        for (int i = 0, value; i < n; ++i)
        {
            scanf("%s%d", op, &value);
            if (op[0] == 'I')
            {
                insert_value(value, head_idx, next_idx, storage, idx);
                continue;
            }
            if (query_value(value, head_idx, next_idx, storage))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0840_H
