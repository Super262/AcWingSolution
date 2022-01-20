//
// Created by Fengwei Zhang on 1/19/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0107_H
#define ACWINGSOLUTION_PROBLEM0107_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0107 {
private:
    static const int N = 500010;

    long long CountReversed(int nums[], int temp[], const int st, const int ed) {
        if (st >= ed) {
            return 0;
        }
        const auto mid = st + (ed - st) / 2;
        auto res = CountReversed(nums, temp, st, mid) + CountReversed(nums, temp, mid + 1, ed);
        // 拆分归并排序和统计逆序对
        auto l = st;
        auto r = mid + 1;
        while (r <= ed) {
            while (l <= mid && nums[l] <= nums[r]) {
                ++l;
            }
            res += mid - l + 1;
            ++r;
        }
        l = st;
        r = mid + 1;
        auto tt = st;
        while (l <= mid && r <= ed) {
            if (nums[l] <= nums[r]) {
                temp[tt++] = nums[l++];
            } else {
                temp[tt++] = nums[r++];
            }
        }
        while (l <= mid) {
            temp[tt++] = nums[l++];
        }
        while (r <= ed) {
            temp[tt++] = nums[r++];
        }
        memcpy(nums + st, temp + st, (ed - st + 1) * sizeof(int));
        return res;
    }

    int main() {
        int nums[N];
        int temp[N];
        while (true) {
            int n;
            scanf("%d", &n);
            if (!n) {
                break;
            }
            for (int i = 0; i < n; ++i) {
                scanf("%d", &nums[i]);
            }
            printf("%lld\n", CountReversed(nums, temp, 0, n - 1));
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0107_H
