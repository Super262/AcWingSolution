//
// Created by Fengwei Zhang on 2021/6/4.
//

#ifndef ACWINGSOLUTION_PROBLEM2816_H
#define ACWINGSOLUTION_PROBLEM2816_H

#include <vector>
#include <iostream>

using namespace std;

class Problem2816 {
private:
    bool isSubArray(const vector<int> &nums1, const vector<int> &nums2) {
        const auto n = (int) nums1.size();
        const auto m = (int) nums2.size();
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                ++i;
            }
            ++j;
        }
        if (i == n) {
            return true;
        }
        return false;
    }

    int main() {
        int n;
        int m;
        scanf("%d%d", &n, &m);
        vector<int> nums1(n);
        vector<int> nums2(m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums1[i]);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d", &nums2[i]);
        }
        if (isSubArray(nums1, nums2)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM2816_H
