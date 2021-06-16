//
// Created by Fengwei Zhang on 2021/6/16.
//

#ifndef ACWINGSOLUTION_PROBLEM0891_H
#define ACWINGSOLUTION_PROBLEM0891_H

#include <iostream>

using namespace std;

class Problem0891 {
public:
    bool simpleNim(const unsigned int *stonesCount, const unsigned int size) {
        unsigned int result = 0;
        for (unsigned int i = 0; i < size; ++i) {
            result ^= stonesCount[i];
        }
        return result != 0;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        auto stonesCount = new unsigned int[n];
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d", &stonesCount[i]);
        }
        if (simpleNim(stonesCount, n)) {
            puts("Yes");
        } else {
            puts("No");
        }
        delete[] stonesCount;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0891_H
