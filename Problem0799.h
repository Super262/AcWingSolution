//
// Created by Fengwei Zhang on 2021/6/1.
//

#ifndef ACWINGSOLUTION_PROBLEM0799_H
#define ACWINGSOLUTION_PROBLEM0799_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Problem0799
{
private:
    int longestUnique(const vector<int> &nums)
    {
        const auto n = (int)nums.size();
        unordered_map<int, int> counter;
        int result = 0;
        for (int l = 0, r = 0; r < n; ++r)
        {
            ++counter[nums[r]];
            while (l < r && counter[nums[r]] > 1)
            {
                --counter[nums[l]];
                ++l;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &nums[i]);
        }
        printf("%d\n", longestUnique(nums));
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0799_H
