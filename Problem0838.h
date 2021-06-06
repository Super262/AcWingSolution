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
    void downNode(vector<int> &h, const unsigned long &rootIndex) {
        // 有效索引从1开始
        unsigned long minimalIndex = rootIndex;
        if (rootIndex * 2 <= h.size() - 1 && h[2 * rootIndex] < h[minimalIndex]) {
            minimalIndex = 2 * rootIndex;
        }
        if (2 * rootIndex + 1 <= h.size() - 1 && h[2 * rootIndex + 1] < h[minimalIndex]) {
            minimalIndex = 2 * rootIndex + 1;
        }
        if (rootIndex != minimalIndex) {
            swap(h[rootIndex], h[minimalIndex]);
            downNode(h, minimalIndex);
        }
    }

    void buildHeap(vector<int> &h) {
        // 建堆复杂度为O(n)
        // 有效索引从1开始；
        for (unsigned long i = (h.size() - 1) / 2; i > 0; --i) {
            downNode(h, i);
        }
    }

    int heapPop(vector<int> &h) {
        int result = h[1];
        h[1] = h[h.size() - 1];
        h.pop_back();
        downNode(h, 1);
        return result;
    }

    int main() {
        unsigned long n, m;
        scanf("%ld%ld", &n, &m);
        vector<int> myHeap(n + 1, 0);
        for (unsigned long i = 1; i <= n; ++i) {
            scanf("%d", &myHeap[i]);
        }
        buildHeap(myHeap);
        for (unsigned long i = 1; i <= m; ++i) {
            printf("%d ", heapPop(myHeap));
        }
        printf("\n");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0838_H
