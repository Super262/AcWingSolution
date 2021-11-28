//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0789_H
#define ACWINGSOLUTION_PROBLEM0789_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0789 {
private:
    void queryRange(const vector<int> &nums, const int t) {
        int l = 0;
        int r = (int) nums.size() - 1;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] >= t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[r] != t) {
            printf("-1 -1\n");
            return;
        }
        printf("%d ", r);
        l = 0;
        r = (int) nums.size() - 1;
        while (l < r) {
            auto mid = l + (r - l + 1) / 2;
            if (nums[mid] <= t) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (nums[l] != t) {
            printf("-1 -1\n");
            return;
        }
        printf("%d\n", l);
    }

    int main() {
        int n;
        int k;
        scanf("%d%d", &n, &k);
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        int t;
        for (int i = 0; i < k; ++i) {
            scanf("%d", &t);
            queryRange(nums, t);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0789_H
