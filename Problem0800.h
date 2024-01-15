//
// Created by Fengwei Zhang on 2021/6/3.
//

#ifndef ACWINGSOLUTION_PROBLEM0800_H
#define ACWINGSOLUTION_PROBLEM0800_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0800
{
private:
    pair<int, int> target_sum(const vector<int> &nums1, const vector<int> &nums2, const int &t)
    {
        const auto n = (int)nums1.size();
        const auto m = (int)nums2.size();
        int i = 0;
        auto j = m - 1;
        while (i < n && j >= 0)
        {
            if (nums1[i] + nums2[j] == t)
            {
                return {i, j};
            }
            else if (nums1[i] + nums2[j] > t)
            {
                --j;
            }
            else
            {
                ++i;
            }
        }
        return {-1, -1};
    }

    int main()
    {
        int n;
        int m;
        int t;
        scanf("%d%d%d", &n, &m, &t);
        vector<int> nums1(n);
        vector<int> nums2(m);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &nums1[i]);
        }
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &nums2[i]);
        }
        auto res = target_sum(nums1, nums2, t);
        printf("%d %d\n", res.first, res.second);
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0800_H
