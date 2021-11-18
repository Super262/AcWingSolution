//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0838_H
#define ACWINGSOLUTION_PROBLEM0838_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0838 {
public:
    void downNode(vector<int> &heap, unsigned long long rootIndex) {
        unsigned long long minimalIndex = rootIndex;
        while (true) {
            if (rootIndex * 2 < heap.size() && heap[rootIndex * 2] < heap[minimalIndex]) {
                minimalIndex = 2 * rootIndex;
            }
            if (rootIndex * 2 + 1 < heap.size() && heap[rootIndex * 2 + 1] < heap[minimalIndex]) {
                minimalIndex = 2 * rootIndex + 1;
            }
            if (rootIndex == minimalIndex) {
                return;
            }
            swap(heap[rootIndex], heap[minimalIndex]);
            rootIndex = minimalIndex;
        }
    }

    void upNode(vector<int> &heap, unsigned long long rootIndex) {
        while (rootIndex / 2 && heap[rootIndex / 2] > heap[rootIndex]) {
            swap(heap[rootIndex / 2], heap[rootIndex]);
            rootIndex /= 2;
        }
    }

    void buildHeap(vector<int> &heap) {
        for (unsigned long long i = (heap.size() - 1) / 2; i > 0; --i) {
            downNode(heap, i);
        }
    }

    int heapPop(vector<int> &heap) {
        auto result = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        downNode(heap, 1);
        return result;
    }

    int main() {
        unsigned long long n, m;
        scanf("%lld%lld", &n, &m);
        vector<int> heap(n + 1, 0);
        for (unsigned long long i = 1; i <= n; ++i) {
            scanf("%d", &heap[i]);
        }
        buildHeap(heap);
        for (unsigned long long i = 0; i < m; ++i) {
            printf("%d ", heapPop(heap));
        }
        printf("\n");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0838_H
