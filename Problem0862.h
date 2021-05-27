//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0862_H
#define ACWINGSOLUTION_PROBLEM0862_H

#include <vector>
#include <iostream>
#include <algorithm>


struct Pair {
    int x;
    double y;
    string z;
};

class Problem0862 {
private:
    bool cmp(Pair &a, Pair &b) {
        return a.x < b.x;
    }

public:
    int main() {
        int n;
        cin >> n;
        vector <Pair> pairs;
        for (int i = 0; i < n; ++i) {
            Pair p;
            cin >> p.x >> p.y >> p.z;
            pairs.emplace_back(p);
        }
        sort(pairs.begin(), pairs.end(), cmp);
        for (int i = 0; i < n; ++i) {
            printf("%d %.2lf %s\n", pairs[i].x, pairs[i].y, pairs[i].z.c_str());
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0862_H
