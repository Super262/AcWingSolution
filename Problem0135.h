//
// Created by Fengwei Zhang on 2021/7/20.
//

#ifndef ACWINGSOLUTION_PROBLEM0135_H
#define ACWINGSOLUTION_PROBLEM0135_H

#include <iostream>
#include <deque>

using namespace std;

class Problem0135 {
private:
    int maxSeq(int nums[], int n, int m) {
        int res = -0x3f3f3f3f;
        deque<int> q;
        for (int i = 0; i < n; ++i) {
            while (!q.empty() && i - q.front() + 1 > m) {
                q.pop_front();
            }
            if (!q.empty()) {
                res = max(res, nums[i] - nums[q.front()]);
            }
            while (!q.empty() && nums[q.back()] >= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return res;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int nums[n + 1];
        nums[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &nums[i]);
            nums[i] += nums[i - 1];
        }
        printf("%d\n", maxSeq(nums, n + 1, m + 1));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0135_H
