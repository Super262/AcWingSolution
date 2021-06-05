//
// Created by Fengwei Zhang on 2021/5/31.
//

#ifndef ACWINGSOLUTION_PROBLEM0797_H
#define ACWINGSOLUTION_PROBLEM0797_H

#include <vector>
#include <iostream>

using namespace std;


class Problem0797 {
public:
    void increase(vector<int> &arr, const unsigned long &left, const unsigned long &right, int value) {
        arr[left] += value;
        arr[right + 1] -= value;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> arr(n + 1, 0);
        int t;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &t);
            increase(arr, i, i, t);
        }
        int l, r, c;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &l, &r, &c);
            increase(arr, l, r, c);
        }
        for (int i = 1; i <= n; ++i) {
            arr[i] += arr[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0797_H