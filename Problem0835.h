//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0835_H
#define ACWINGSOLUTION_PROBLEM0835_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0835 {
    // 完整背诵这部分代码！
public:
    void insert(const string &word,
                vector<vector<unsigned long long>> &children,
                vector<unsigned long long> &wordsCount,
                unsigned long long &nextIdx) {
        unsigned long long currentIdx = 0;
        for (const char ch : word) {
            unsigned long long chIndex = ch - 'a';
            if (!children[currentIdx][chIndex]) {
                children[currentIdx][chIndex] = ++nextIdx;
            }
            currentIdx = children[currentIdx][chIndex];
            while (currentIdx >= children.size()) {
                children.emplace_back(vector<unsigned long long>(26, 0));
            }
            while (currentIdx >= wordsCount.size()) {
                wordsCount.emplace_back(0);
            }
        }
        ++wordsCount[currentIdx];
    }

    unsigned long long query(const string &word,
                             const vector<vector<unsigned long long>> &children,
                             const vector<unsigned long long> &wordsCount) {
        unsigned long long currentIdx = 0;
        for (const char ch : word) {
            unsigned long long chIndex = ch - 'a';
            if (currentIdx >= children.size() || currentIdx >= wordsCount.size() || !children[currentIdx][chIndex]) {
                return 0;
            }
            currentIdx = children[currentIdx][chIndex];
        }
        return wordsCount[currentIdx];
    }

    int main() {
        unsigned long long n;
        cin >> n;
        char op;
        string word;
        vector<vector<unsigned long long>> children(1, vector<unsigned long long>(26, 0));
        vector<unsigned long long> wordsCount(1, 0);
        unsigned long long nextIdx = 0;
        for (unsigned long long i = 0; i < n; ++i) {
            cin >> op >> word;
            if (op == 'I') {
                insert(word, children, wordsCount, nextIdx);
            } else {
                printf("%llu\n", query(word, children, wordsCount));
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0835_H
