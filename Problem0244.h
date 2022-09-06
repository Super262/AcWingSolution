//
// Created by Fengwei Zhang on 9/21/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0244_H
#define ACWINGSOLUTION_PROBLEM0244_H

#include <iostream>

using namespace std;

class Problem0244 {
    // https://www.acwing.com/solution/content/1012/
private:
    static const int N = 100000;
    int arr[N], ft[N];

    int lowBit(const int x) {
        return x & -x;
    }

    void updateItem(const int idx, const int val, const int n) {
        for (int i = idx; i <= n; i += lowBit(i)) {
            ft[i] += val;
        }
    }

    int prefixSum(const int idx) {
        int res = 0;
        for (int i = idx; i > 0; i -= lowBit(i)) {
            res += ft[i];
        }
        return res;
    }

    int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            updateItem(i, 1, n);
        }
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        for (int i = n; i > 0; --i) {
            int l = 1;
            auto r = n;
            while (l < r) {  // 二分查找：靠左搜索的模版
                int mid = l + (r - l) / 2;
                int t = prefixSum(mid);
                if (t < arr[i] + 1) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            arr[i] = r;
            updateItem(r, -1, n);
        }
        for (int i = 1; i <= n; ++i) {
            printf("%d\n", arr[i]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0244_H
