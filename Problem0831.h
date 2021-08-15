//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0831_H
#define ACWINGSOLUTION_PROBLEM0831_H

#include <iostream>

using namespace std;

class Problem0831 {
private:
    void buildNextStart(const char p[], int nextStart[], const int pLen) {
        nextStart[0] = 0;
        int right = 1;
        int left = 0;
        while (right < pLen) {
            if (p[left] == p[right]) {
                ++left;
                nextStart[right] = left;
                ++right;
            } else if (left) {
                left = nextStart[left - 1];
            } else {
                nextStart[right] = 0;
                ++right;
            }
        }
    }

    void printMatchedStart(const char s[], const int sLen, const char p[], const int nextStart[], const int pLen) {
        int si = 0;
        int pi = 0;
        while (si < sLen) {
            if (s[si] == p[pi]) {
                ++si;
                ++pi;
            } else if (pi) {
                pi = nextStart[pi - 1];
            } else {
                ++si;
            }
            if (pi == pLen) {
                printf("%d ", si - pLen);
                pi = nextStart[pi - 1];
            }
        }
        printf("\n");
    }

    int main() {
        int pLen;
        scanf("%d", &pLen);
        auto p = new char[pLen + 1];
        scanf("%s", p);
        int sLen;
        scanf("%d", &sLen);
        auto s = new char[sLen + 1];
        scanf("%s", s);
        auto nextStart = new int[pLen];
        buildNextStart(p, nextStart, pLen);
        printMatchedStart(s, sLen, p, nextStart, pLen);
        delete[] p;
        delete[] s;
        delete[] nextStart;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0831_H
