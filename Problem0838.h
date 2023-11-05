//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0838_H
#define ACWINGSOLUTION_PROBLEM0838_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0838
{
private:
    void down_node(vector<int> &heap, unsigned long long root_index)
    {
        while (true)
        {
            auto minimal_index = root_index;
            if (root_index * 2 < heap.size() && heap[root_index * 2] < heap[minimal_index])
            {
                minimal_index = 2 * root_index;
            }
            if (root_index * 2 + 1 < heap.size() && heap[root_index * 2 + 1] < heap[minimal_index])
            {
                minimal_index = 2 * root_index + 1;
            }
            if (root_index == minimal_index)
            {
                return;
            }
            swap(heap[root_index], heap[minimal_index]);
            root_index = minimal_index;
        }
    }

    void up_node(vector<int> &heap, unsigned long long root_index)
    {
        while (root_index / 2 && heap[root_index / 2] > heap[root_index])
        {
            swap(heap[root_index / 2], heap[root_index]);
            root_index /= 2;
        }
    }

    void build_heap(vector<int> &heap)
    {
        for (auto i = (heap.size() - 1) / 2; i > 0; --i)
        {
            down_node(heap, i);
        }
    }

    int heap_pop(vector<int> &heap)
    {
        auto result = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        down_node(heap, 1);
        return result;
    }

    int main()
    {
        unsigned long long n, m;
        scanf("%lld%lld", &n, &m);
        vector<int> heap(n + 1);
        for (unsigned long long i = 1; i <= n; ++i)
        {
            scanf("%d", &heap[i]);
        }
        build_heap(heap);
        for (unsigned long long i = 0; i < m; ++i)
        {
            printf("%d ", heap_pop(heap));
        }
        printf("\n");
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0838_H
