//
// Created by Fengwei Zhang on 2021/6/3.
//

#ifndef ACWINGSOLUTION_PROBLEM0802_H
#define ACWINGSOLUTION_PROBLEM0802_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Problem0802 {
private:
    int getIdx(int idx, const vector<int> &indices) {
        return (int) (lower_bound(indices.begin(), indices.end(), idx) - indices.begin() + 1);  // 索引从1开始
    }

    int main() {
        int n;
        int m;
        scanf("%d%d", &n, &m);
        vector<int> indices;
        vector<pair<int, int>> add_reqs(n);
        vector<pair<int, int>> query_reqs(m);
        for (int i = 0; i < n; ++i) {
            int x, c;
            scanf("%d%d", &x, &c);
            indices.emplace_back(x);
            add_reqs[i] = {x, c};
        }
        for (int i = 0; i < m; ++i) {
            int l, r;
            scanf("%d%d", &l, &r);
            indices.emplace_back(l);
            indices.emplace_back(r);
            query_reqs[i] = {l, r};
        }
        // 标准步骤：排序、去重
        sort(indices.begin(), indices.end());
        indices.erase(unique(indices.begin(), indices.end()), indices.end());

        vector<int> data(indices.size() + 1, 0);  // 离散化后的索引从1开始，别忘记加1
        for (const auto &p: add_reqs) {
            data[getIdx(p.first, indices)] += p.second;
        }
        for (int i = 1; i < data.size(); ++i) {
            data[i] += data[i - 1];
        }
        for (const auto &p: query_reqs) {
            auto a = getIdx(p.first, indices);
            auto b = getIdx(p.second, indices);
            printf("%d\n", data[b] - data[a - 1]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0802_H
