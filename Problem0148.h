//
// Created by Fengwei Zhang on 2021/6/25.
//

#ifndef ACWINGSOLUTION_PROBLEM0148_H
#define ACWINGSOLUTION_PROBLEM0148_H

#include <iostream>
#include <queue>

using namespace std;

class Problem0148
{
    // 霍夫曼树，不要误认为是"石子合并问题"（AcWing0282）
private:
    int huffman_tree(const int *items, const int &n)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; ++i)
        {
            pq.emplace(items[i]);
        }
        int result = 0;
        while (pq.size() > 1)
        {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            pq.emplace(a + b);
            result += a + b;
        }
        return result;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        int items[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &items[i]);
        }
        printf("%d\n", huffman_tree(items, n));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0148_H
