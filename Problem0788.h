//
// Created by Fengwei Zhang on 2021/5/29.
//

#ifndef ACWINGSOLUTION_PROBLEM0788_H
#define ACWINGSOLUTION_PROBLEM0788_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0788 {
    // 注意为避免溢出，使用long long
    // 为便于改造，拆分归并过程和统计逆序对的过程
private:
    long long MergeSort(int nums[], int st, int ed, int temp[]) {
        if (st >= ed) {
            return 0;
        }
        const auto mid = st + (ed - st) / 2;
        auto result = MergeSort(nums, st, mid, temp) + MergeSort(nums, mid + 1, ed, temp);
        auto l = st;
        auto r = mid + 1;
        while (r <= ed) {  // 统计逆序对
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
        memcpy(nums + st, temp + st, (ed - st + 1) * sizeof(int));
        return result;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int nums[n];
        int temp[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        printf("%lld\n", MergeSort(nums, 0, n - 1, temp));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0788_H
