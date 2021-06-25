//
// Created by Fengwei Zhang on 2021/6/25.
//

#ifndef ACWINGSOLUTION_PROBLEM0148_H
#define ACWINGSOLUTION_PROBLEM0148_H

#include <iostream>
#include <queue>

using namespace std;

class Problem0148 {
public:
    int huffmanTreeHelper(const int *items, const unsigned int n) {
        if (n <= 1) {
            return 0;
        }
        priority_queue<int, vector<int>, greater<int>> heap;
        for (unsigned int i = 0; i < n; ++i) {
            heap.emplace(items[i]);
        }
        int result = 0;
        int a;
        int b;
        while (heap.size() >= 2) {
            a = heap.top();
            heap.pop();
            b = heap.top();
            heap.pop();
            result += a + b;
            heap.emplace(a + b);
        }
        return result;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        auto items = new int[n];
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d", &items[i]);
        }
        printf("%d\n", huffmanTreeHelper(items, n));
        delete[] items;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0148_H
