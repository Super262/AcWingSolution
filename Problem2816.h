//
// Created by Fengwei Zhang on 2021/6/4.
//

#ifndef ACWINGSOLUTION_PROBLEM2816_H
#define ACWINGSOLUTION_PROBLEM2816_H

#include <vector>
#include <iostream>

using namespace std;

class Problem2816 {
public:
    bool isSubSeq(const vector<int> &child, const vector<int> &parent) {
        if (child.empty() || child.size() > parent.size()) {
            return false;
        }
        unsigned long i = 0;
        unsigned long j = 0;
        while (i < child.size() && j < parent.size()) {
            if (child[i] == parent[j]) {
                ++i;
            }
            ++j;
        }
        if (i < child.size()) {
            return false;
        }
        return true;
    }

    int main() {
        unsigned long n, m;
        scanf("%ld%ld", &n, &m);
        vector<int> child(n, 0);
        vector<int> parent(m, 0);
        for (unsigned long i = 0; i < n; ++i) {
            scanf("%d", &child[i]);
        }
        for (unsigned long i = 0; i < m; ++i) {
            scanf("%d", &parent[i]);
        }
        printf("%s", (isSubSeq(child, parent) ? "Yes" : "No"));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM2816_H
