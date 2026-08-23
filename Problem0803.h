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
    /* 贪心算法：左端点排序 */
    /* 如果不需要输出合并后的所有区间，我们可以省去result和start，*/
    /* 只记录end和结果集的大小 */
private:
    vector<pair<int, int>> MergeSegments(vector<pair<int, int>> &segs)
    {
        vector<pair<int, int>> result;
        if (!segs.size())
            return result;
        sort(segs.begin(), segs.end());
        auto start = segs[0].first;
        auto end = segs[0].second;
        for (const auto &s : segs)
        {
            if (s.first > end)
            {
                result.emplace_back(pair<int, int>(start, end));
                start = s.first;
                end = s.second;
            }
            else
                end = max(end, s.second);
        }
        result.emplace_back(pair<int, int>(start, end));
        return result;
    }

    int main()
    {
        int n;
        scanf("%d", &n);
        vector<pair<int, int>> segs(n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &segs[i].first, &segs[i].second);
        printf("%d\n", (int)MergeSegments(segs).size());
        return 0;
    }
};

#endif // ACWINGSOLUTION_PROBLEM0803_H
