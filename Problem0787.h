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
        auto mid = st + (ed - st) / 2;
        mergeSort(nums, st, mid, temp);
        mergeSort(nums, mid + 1, ed, temp);
        int t = st;
        int l = st;
        int r = mid + 1;
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
        for (int i = st; i <= ed; ++i) {
            nums[i] = temp[i];
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<int> nums(n);
        vector<int> temp(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        mergeSort(nums, 0, n - 1, temp);
        for (int i = 0; i < n; ++i) {
            printf("%d ", nums[i]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0787_H
