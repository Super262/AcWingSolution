//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0835_H
#define ACWINGSOLUTION_PROBLEM0835_H

#include <vector>
#include <iostream>

using namespace std;

class Problem0835 {
public:
    void insert(const string &word,
                vector<vector<unsigned int>> &children,
                vector<unsigned int> &wordsCount,
                unsigned int &idx) {
        unsigned long currentLevel = 0;
        for (char ch : word) {
            unsigned long childIndex = ch - 'a';
            if (!children[currentLevel][childIndex]) {
                children[currentLevel][childIndex] = ++idx;
            }
            currentLevel = children[currentLevel][childIndex];
            while (currentLevel >= children.size()) {
                children.emplace_back(vector<unsigned int>(26, 0));
            }
            while (currentLevel >= wordsCount.size()) {
                wordsCount.emplace_back(0);
            }
        }
        ++wordsCount[currentLevel];
    }

    unsigned int query(const string &word,
                       const vector<vector<unsigned int>> &children,
                       const vector<unsigned int> &wordsCount) {
        unsigned long currentLevel = 0;
        for (char ch : word) {
            if (currentLevel >= children.size()) {
                return 0;
            }
            unsigned long childIndex = ch - 'a';
            if (!children[currentLevel][childIndex]) {
                return 0;
            }
            currentLevel = children[currentLevel][childIndex];
        }
        return wordsCount[currentLevel];
    }

    int main() {
        unsigned int idx = 0;  // 与链表中idx作用类似

        // 初始化，创建一个空的根结点
        vector<vector<unsigned int>> children(1, vector<unsigned int>(26, 0));
        vector<unsigned int> wordsCount(1, 0);

        unsigned int n;
        char op;
        string word;
        cin >> n;
        while (n--) {
            cin >> op >> word;
            if (op == 'I') {
                insert(word, children, wordsCount, idx);
            } else {
                cout << query(word, children, wordsCount) << endl;
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0835_H
