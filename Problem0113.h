//
// Created by Fengwei Zhang on 10/31/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0113_H
#define ACWINGSOLUTION_PROBLEM0113_H

// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
    // https://www.acwing.com/solution/content/2676/
public:
    vector<int> specialSort(int N) {
        vector<int> result(1, 1);
        for (int num = 2; num <= N; ++num) {
            int l = 0, r = result.size() - 1;
            while (l <= r) {
                auto mid = l + (r - l) / 2;
                // 不存在相等的情况
                if (compare(result[mid], num)) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            result.insert(result.begin() + l, num); // 此时l > r，l是插入位置
        }
        return result;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0113_H
