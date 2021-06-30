//
// Created by Fengwei Zhang on 2021/6/7.
//

#ifndef ACWINGSOLUTION_PROBLEM0143_H
#define ACWINGSOLUTION_PROBLEM0143_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0143 {
public:
    unsigned long nextIdx = 0;
    unsigned long storage[100010 * 31][2];

    void insertNum(const unsigned int &value) {
        unsigned long currentIdx = 0;
        bool chIndex;
        for (int i = 30; i >= 0; --i) {
            chIndex = (value >> i) & 1;
            if (!storage[currentIdx][chIndex]) {
                storage[currentIdx][chIndex] = ++nextIdx;
            }
            currentIdx = storage[currentIdx][chIndex];
        }
    }

    unsigned int getResult(const unsigned int &value) {
        unsigned int result = 0;
        unsigned long currentIdx = 0;
        bool chIndex;
        for (int i = 30; i >= 0; --i) {
            chIndex = (value >> i) & 1;
            if (storage[currentIdx][!chIndex]) {
                currentIdx = storage[currentIdx][!chIndex];
                result = result * 2 + 1;
            } else {
                currentIdx = storage[currentIdx][chIndex];
                result = result * 2 + 0;
            }
        }
        return result;
    }

    int main() {
        unsigned long n;
        scanf("%ld", &n);
        unsigned int result = 0;
        unsigned int temp;
        while (n--) {
            scanf("%d", &temp);
            insertNum(temp);
            result = max(result, getResult(temp));
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0143_H
