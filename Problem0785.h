//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0785_H
#define ACWINGSOLUTION_PROBLEM0785_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0785 {
private:
    void quickSort(vector<int> &nums, int st, int ed) {
        if (st >= ed) {
            return;
        }
        auto l = st - 1;
        auto r = ed + 1;
        // auto p = nums[st + (ed - st) / 2];  // 选择偏左的中点
        auto p = nums[st + (ed - st + 1) / 2];  // 选择偏右的中点
        while (l < r) {
            while (nums[++l] < p);  // 注意：循环条件不包含 l < r
            while (nums[--r] > p);
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }
        // 对应偏左的中点
        // quickSort(nums, st, r);
        // quickSort(nums, r + 1, ed);

        // 对应偏右的中点
        quickSort(nums, st, l - 1);
        quickSort(nums, l, ed);
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<int> nums(n, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        quickSort(nums, 0, n - 1);
        for (int i = 0; i < n; ++i) {
            printf("%d ", nums[i]);
        }
        printf("\n");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0785_H
