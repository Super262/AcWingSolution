//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0787_H
#define ACWINGSOLUTION_PROBLEM0787_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0787 {
private:
    void mergeSort(vector<int> &nums, int st, int ed, vector<int> &temp) {
        if (st >= ed) {
            return;
        }
        auto l = st;
        auto mid = st + (ed - st) / 2;
        auto r = mid + 1;
        mergeSort(nums, st, mid, temp);
        mergeSort(nums, r, ed, temp);
        auto t = st;
        while (l <= mid && r <= ed) {
            if (nums[l] <= nums[r]) {
                temp[t] = nums[l];
                ++l;
            } else {
                temp[t] = nums[r];
                ++r;
            }
            ++t;
        }
        while (l <= mid) {
            temp[t] = nums[l];
            ++l;
            ++t;
        }
        while (r <= ed) {
            temp[t] = nums[r];
            ++r;
            ++t;
        }
        for (auto i = st; i <= ed; ++i) {
            nums[i] = temp[i];
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<int> nums(n, 0);
        vector<int> temp(n, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        mergeSort(nums, 0, n - 1, temp);
        for (int i = 0; i < n; ++i) {
            printf("%d ", nums[i]);
        }
        printf("\n");
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0787_H
