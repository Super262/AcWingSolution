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
    bool queryValue(const int target, const vector<unsigned int> &headIdx, const vector<unsigned int> &nextIdx,
                    const vector<int> &storage) {
        const int N = (int) headIdx.size();
        const int r = (target % N + N) % N;  // 消除负数的影响
        for (unsigned int idx = headIdx[r]; idx != 0; idx = nextIdx[idx]) {
            if (storage[idx] == target) {
                return true;
            }
        }
        return false;
    }

    void
    insertValue(const int target, vector<unsigned int> &headIdx, vector<unsigned int> &nextIdx, vector<int> &storage,
                unsigned int &idx) {
        if (queryValue(target, headIdx, nextIdx, storage)) {
            return;
        }
        const int N = (int) headIdx.size();
        const int r = (target % N + N) % N;  // 消除负数的影响
        ++idx;
        while (idx >= nextIdx.size()) {
            nextIdx.emplace_back(0);
        }
        while (idx >= storage.size()) {
            storage.emplace_back(0);
        }
        nextIdx[idx] = headIdx[r];
        headIdx[r] = idx;
        storage[idx] = target;
    }

    int main() {
        const int N = 10001;
        vector<unsigned int> headIdx(N + 1, 0);
        vector<unsigned int> nextIdx;
        vector<int> storage;
        unsigned int idx = 0;
        unsigned int n;
        scanf("%d", &n);
        char op[2];
        int value;
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%s%d", op, &value);
            if (op[0] == 'I') {
                insertValue(value, headIdx, nextIdx, storage, idx);
            } else {
                if (queryValue(value, headIdx, nextIdx, storage)) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0840_H
