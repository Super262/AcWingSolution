//
// Created by Fengwei Zhang on 2021/5/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0788_H
#define ACWINGSOLUTION_PROBLEM0788_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0788 {
private:
    long long mergeSort(vector<int> &nums, int st, int ed, vector<int> &temp) {
        if (st >= ed) {
            return 0;
        }
        const auto mid = st + (ed - st) / 2;
        auto result = mergeSort(nums, st, mid, temp) + mergeSort(nums, mid + 1, ed, temp);
        auto l = st;
        auto r = mid + 1;
        while (r <= ed) {
            while (l <= mid && nums[l] <= nums[r]) {
                ++l;
            }
            result += mid - l + 1;
            ++r;
        }
        l = st;
        r = mid + 1;
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
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<int> nums(n);
        vector<int> temp(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        printf("%lld\n", mergeSort(nums, 0, n - 1, temp));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0788_H
