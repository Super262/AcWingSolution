//
// Created by Fengwei Zhang on 10/30/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0100_H
#define ACWINGSOLUTION_PROBLEM0100_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0100 {
    // https://www.acwing.com/solution/content/4131/
private:
    int main() {
        int n;
        scanf("%d", &n);
        int arr[n + 2];
        memset(arr, 0, sizeof arr);
        int x;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            arr[i] += x;
            arr[i + 1] -= x;
        }
        long long posSum = 0;
        long long negSum = 0;
        for (int i = 2; i <= n; ++i) {
            if (arr[i] > 0) {
                posSum += (long long) arr[i];
            } else {
                negSum += -((long long) arr[i]);
            }
        }
        printf("%lld\n", min(posSum, negSum) + abs(posSum - negSum));
        printf("%lld\n", abs(posSum - negSum) + 1);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0100_H
