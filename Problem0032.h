//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0032_H
#define ACWINGSOLUTION_PROBLEM0032_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem0032 {
public:
    void reOrderArray(vector<int> &array) {
        if (array.size() < 2) {
            return;
        }
        unsigned long left = 0;
        unsigned long right = array.size() - 1; // 若array为空，这里会发生溢出。
        while (left < right) {
            while (left < right && array[left] % 2 == 1) {
                ++left;
            }
            while (left < right && array[right] % 2 == 0) {
                --right;
            }
            if (left < right) {
                swap(array[left], array[right]);
                ++left;
                --right;
            }
        }
    }
};

#endif //ACWINGSOLUTION_PROBLEM0032_H
