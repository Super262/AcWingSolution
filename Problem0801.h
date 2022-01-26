//
// Created by Fengwei Zhang on 2021/6/1.
//

#ifndef ACWINGSOLUTION_PROBLEM0801_H
#define ACWINGSOLUTION_PROBLEM0801_H

#include <iostream>

using namespace std;

class Problem0801 {
private:
    int LowBit(const int x) {
        return x & (-x);
    }

    int CountOnes(int x) {
        int result = 0;
        while (x > 0) {
            x -= LowBit(x);
            ++result;
        }
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            printf("%d ", CountOnes(x));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0801_H
