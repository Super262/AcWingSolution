//
// Created by Fengwei Zhang on 2021/6/3.
//

#ifndef ACWINGSOLUTION_PROBLEM0803_H
#define ACWINGSOLUTION_PROBLEM0803_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Problem0803
{
    // 贪心算法：左端点排序
private:
    vector<pair<int, int>> MergeSegments(vector<pair<int, int>> &segs)
    {
        sort(segs.begin(), segs.end());
        const int invalid_value = -2e9;
        vector<pair<int, int>> result;
        auto start = invalid_value;
        auto end = invalid_value;
        for (const auto &s : segs)
        {
            if (s.first > end)
            {
                if (end != invalid_value)
                {
                    result.emplace_back(pair<int, int>(start, end));
                }
                start = s.first;
                end = s.second;
            }
            else
            {
                end = max(end, s.second);
            }
        }
        if (end != invalid_value)
        {
            result.emplace_back(pair<int, int>(start, end));
        }
        return result;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        vector<pair<int, int>> segs(n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &segs[i].first, &segs[i].second);
        }
        printf("%d\n", (int)MergeSegments(segs).size());
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0803_H
