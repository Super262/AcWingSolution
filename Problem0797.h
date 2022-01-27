//
// Created by Fengwei Zhang on 2021/5/31.
//

#ifndef ACWINGSOLUTION_PROBLEM0797_H
#define ACWINGSOLUTION_PROBLEM0797_H

#include <vector>
#include <iostream>

using namespace std;


class Problem0797 {
private:
    void Increase(vector<int> &arr, const int left, const int right, int v) {
        arr[left] += v;
        arr[right + 1] -= v;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> arr(n + 2, 0);  // 长度为n+2！
        int t;
        // 初始化：区间起点和终点相同
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &t);
            Increase(arr, i, i, t);
        }
        int l, r, c;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &l, &r, &c);
            Increase(arr, l, r, c);
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
