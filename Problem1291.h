//
// Created by Fengwei Zhang on 1/10/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1291_H
#define ACWINGSOLUTION_PROBLEM1291_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1291 {
private:
    int main() {
        const int N = 1000000;
        int counter[N + 1];
        int freq[N + 1];
        memset(counter, 0, sizeof counter);
        memset(freq, 0, sizeof freq);
        int n;
        scanf("%d", &n);
        int nums[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
            ++counter[nums[i]];
        }
        for (int num = 1; num <= N; ++num) {
            for (int p = num; p <= N; p += num) {
                freq[p] += counter[num];
            }
        }
        for (int i = 0; i < n; ++i) {
            printf("%d\n", freq[nums[i]] - 1);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1291_H
