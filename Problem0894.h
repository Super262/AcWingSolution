//
// Created by Fengwei Zhang on 2021/6/16.
//

#ifndef ACWINGSOLUTION_PROBLEM0894_H
#define ACWINGSOLUTION_PROBLEM0894_H

#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Problem0894 {
public:
    unsigned int sg(const unsigned int key, unordered_map<unsigned int, unsigned int> &stateTable) {
        if (stateTable.find(key) != stateTable.end()) {
            return stateTable[key];
        }
        unordered_set<unsigned int> existedStates;
        for (unsigned int h1 = 0; h1 < key; ++h1) {
            for (unsigned int h2 = 0; h2 <= h1; ++h2) {
                existedStates.insert(sg(h1, stateTable) ^ sg(h2, stateTable));
            }
        }
        unsigned int s = 0;
        while (true) {
            if (!existedStates.count(s)) {
                stateTable[key] = s;
                return s;
            }
            ++s;
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        unsigned int result = 0;
        unsigned int k;
        unordered_map<unsigned int, unsigned int> stateTable;
        while (n--) {
            scanf("%d", &k);
            result ^= sg(k, stateTable);
        }
        if (result) {
            puts("Yes");
        } else {
            puts("No");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0894_H
