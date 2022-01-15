//
// Created by Fengwei Zhang on 2021/6/16.
//

#ifndef ACWINGSOLUTION_PROBLEM0891_H
#define ACWINGSOLUTION_PROBLEM0891_H

#include <iostream>

using namespace std;

class Problem0891 {
    // https://www.acwing.com/solution/content/14269/
private:
    bool simpleNim(const int stones[], const int size) {
        int result = 0;
        for (int i = 0; i < size; ++i) {
            result ^= stones[i];
        }
        return result != 0;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int stones[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &stones[i]);
        }
        if (simpleNim(stones, n)) {
            puts("Yes");
        } else {
            puts("No");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0891_H
