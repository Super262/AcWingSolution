//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0840_H
#define ACWINGSOLUTION_PROBLEM0840_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0840 {
public:
    unsigned long queryValue(const unsigned long &base, const vector<vector<int>> &storage, const int &value) {
        unsigned long index = value % base + 1;
        for (const int &num : storage[index]) {
            if (num == value) {
                return index;
            }
        }
        return 0;
    }

    void insertValue(const unsigned long &base, vector<vector<int>> &storage, const int &value) {
        if (queryValue(base, storage, value) > 0) {
            return;
        }
        storage[value % base + 1].emplace_back(value);
    }


    int main() {
        const unsigned long base = 1000;
        vector<vector<int>> storage(base + 1, vector<int>());
        unsigned long n;
        scanf("%ld", &n);
        char op[2];
        int value;
        while (n--) {
            scanf("%s%d", op, &value);
            if (op[0] == 'I') {
                insertValue(base, storage, value);
            } else {
                printf("%s\n", queryValue(base, storage, value) > 0 ? "Yes" : "No");
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0840_H
