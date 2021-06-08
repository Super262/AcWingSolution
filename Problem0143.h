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
    unsigned long idx = 0;
    unsigned long storage[100010 * 31][2];

    void insertNum(const unsigned int &value) {
        unsigned long currentLevel = 0;
        bool childIndex;
        for (int i = 30; i >= 0; --i) {
            childIndex = (value >> i) & 1;
            if (!storage[currentLevel][childIndex]) {
                storage[currentLevel][childIndex] = ++idx;
            }
            currentLevel = storage[currentLevel][childIndex];
        }
    }

    unsigned int getResult(const unsigned int &value) {
        unsigned int result = 0;
        unsigned long currentLevel = 0;
        bool childIndex;
        for (int i = 30; i >= 0; --i) {
            childIndex = (value >> i) & 1;
            if (storage[currentLevel][!childIndex]) {
                currentLevel = storage[currentLevel][!childIndex];
                result = result * 2 + 1;
            } else {
                currentLevel = storage[currentLevel][childIndex];
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
