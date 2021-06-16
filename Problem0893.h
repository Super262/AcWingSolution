//
// Created by Fengwei Zhang on 2021/6/16.
//

#ifndef ACWINGSOLUTION_PROBLEM0893_H
#define ACWINGSOLUTION_PROBLEM0893_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;


class Problem0893 {
public:
    using namespace std;

    unsigned int sg(const vector<unsigned int> &handSize,
                    unordered_map<unsigned int, unsigned int> &stateTable,
                    const unsigned int key) {
        if (stateTable.find(key) != stateTable.end()) {
            return stateTable.find(key)->second;
        }
        unordered_set<unsigned int> existedStates;
        for (const unsigned int &h:handSize) {
            if (h > key) {
                continue;
            }
            existedStates.insert(sg(handSize, stateTable, key - h));
        }
        unsigned int s = 0;
        while (true) {
            if (existedStates.find(s) == existedStates.end()) {
                stateTable[key] = s;
                return s;
            }
            ++s;
        }
    }

    int main() {
        unsigned int m;
        scanf("%d", &m);
        vector<unsigned int> handSize(m, 0);
        for (unsigned int &h:handSize) {
            scanf("%d", &h);
        }
        int n;
        scanf("%d", &n);
        unsigned int h;
        unsigned int result = 0;
        unordered_map<unsigned int, unsigned int> stateTable;
        while (n--) {
            scanf("%d", &h);
            result ^= sg(handSize, stateTable, h);
        }
        if (result) {
            puts("Yes");
        } else {
            puts("No");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0893_H
