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
        vector<pair<int, int>> addReqs(n);
        vector<pair<int, int>> queryReqs(m);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &addReqs[i].first, &addReqs[i].second);
            indices.emplace_back(addReqs[i].first);
            indices.emplace_back(addReqs[i].second);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &queryReqs[i].first, &queryReqs[i].second);
            indices.emplace_back(queryReqs[i].first);
            indices.emplace_back(queryReqs[i].second);
        }
        sort(indices.begin(), indices.end());
        indices.erase(unique(indices.begin(), indices.end()), indices.end());
        vector<int> storage(indices.size() + 1, 0);
        for (const auto &p: addReqs) {
            storage[getIdx(p.first, indices)] += p.second;
        }
        for (int i = 1; i < storage.size(); ++i) {
            storage[i] += storage[i - 1];
        }
        for (const auto &p: queryReqs) {
            auto a = getIdx(p.first, indices);
            auto b = getIdx(p.second, indices);
            printf("%d\n", storage[b] - storage[a - 1]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0802_H
