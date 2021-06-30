//
// Created by Fengwei Zhang on 2021/6/7.
//

#ifndef ACWINGSOLUTION_PROBLEM0143_H
#define ACWINGSOLUTION_PROBLEM0143_H

#include <iostream>

using namespace std;

class Problem0143 {
public:
    void insertNum(unsigned int storage[][2], const unsigned int num, unsigned int &nextIdx) {
        unsigned int currentIdx = 0;
        for (int i = 30; i >= 0; --i) {
            bool chIndex = (num >> i) & 1;
            if (!storage[currentIdx][chIndex]) {
                storage[currentIdx][chIndex] = ++nextIdx;
            }
            currentIdx = storage[currentIdx][chIndex];
        }
    }

    unsigned int maxXOR(const unsigned int storage[][2], const unsigned int num) {
        unsigned int result = 0;
        unsigned int currentIdx = 0;
        for (int i = 30; i >= 0; --i) {
            bool chIndex = (num >> i) & 1;
            if (storage[currentIdx][!chIndex]) {
                result = result * 2 + 1;
                currentIdx = storage[currentIdx][!chIndex];
            } else {
                result = result * 2 + 0;
                currentIdx = storage[currentIdx][chIndex];
            }
        }
        return result;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        unsigned int result = 0;
        unsigned int storage[31 * 100001][2];
        unsigned int num;
        unsigned int nextIdx = 0;
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d", &num);
            insertNum(storage, num, nextIdx);
            result = max(result, maxXOR(storage, num));
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0143_H
