//
// Created by Fengwei Zhang on 2021/6/1.
//

#ifndef ACWINGSOLUTION_PROBLEM0801_H
#define ACWINGSOLUTION_PROBLEM0801_H

#include <iostream>

using namespace std;

class Problem0801 {
public:
    unsigned int countOnes(unsigned int num) {
        unsigned int count = 0;
        while (num) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    int main() {
        int n;
        scanf("%d", &n);
        unsigned int num;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num);
            printf("%d ", countOnes(num));
        }
        printf("\n");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0801_H
