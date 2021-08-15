//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0835_H
#define ACWINGSOLUTION_PROBLEM0835_H

#include <iostream>

class Problem0835 {
    // 完整背诵这部分代码！
private:
    void insertStr(const char str[], int &nextIdx, int children[][26], int wordCount[]) {
        int currentNodeIdx = 0;
        for (int i = 0; str[i]; ++i) {
            auto childIdx = str[i] - 'a';
            if (!children[currentNodeIdx][childIdx]) {
                children[currentNodeIdx][childIdx] = nextIdx;
                ++nextIdx;
            }
            currentNodeIdx = children[currentNodeIdx][childIdx];
        }
        ++wordCount[currentNodeIdx];
    }

    int queryStr(const char str[], int children[][26], int wordCount[]) {
        int currentNodeIdx = 0;
        for (int i = 0; str[i]; ++i) {
            auto childIdx = str[i] - 'a';
            if (!children[currentNodeIdx][childIdx]) {
                return 0;
            }
            currentNodeIdx = children[currentNodeIdx][childIdx];
        }
        return wordCount[currentNodeIdx];
    }

    int main() {
        const int N = 100010;
        int children[N][26];
        char str[N];
        int wordsCount[N];
        char op[2];
        int n;
        scanf("%d", &n);
        int nextIdx = 1;
        for (int i = 0; i < n; ++i) {
            scanf("%s%s", op, str);
            if (op[0] == 'I') {
                insertStr(str, nextIdx, children, wordsCount);
            } else {
                printf("%d\n", queryStr(str, children, wordsCount));
            }
        }
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0835_H
