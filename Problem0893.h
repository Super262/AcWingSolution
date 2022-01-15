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
    // https://www.acwing.com/solution/content/23435/
private:
    int SgFunc(const vector<int> &hands,
               unordered_map<int, int> &state_table,
               const int key) {
        if (state_table.find(key) != state_table.end()) {
            return state_table.find(key)->second;
        }
        unordered_set<unsigned int> existed_states;
        for (auto &h: hands) {
            if (h > key) {
                continue;
            }
            existed_states.insert(SgFunc(hands, state_table, key - h));
        }
        int s = 0;
        while (true) {
            if (existed_states.find(s) == existed_states.end()) {
                state_table[key] = s;
                return s;
            }
            ++s;
        }
    }

    int main() {
        int m;
        scanf("%d", &m);
        vector<int> hands(m, 0);
        for (auto &h: hands) {
            scanf("%d", &h);
        }
        int n;
        scanf("%d", &n);
        int result = 0;
        unordered_map<int, int> state_table;
        while (n--) {
            int h;
            scanf("%d", &h);
            result ^= SgFunc(hands, state_table, h);
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
