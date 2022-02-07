//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0831_H
#define ACWINGSOLUTION_PROBLEM0831_H

#include <iostream>

using namespace std;

class Problem0831 {
private:
    void buildFail(const char p[], int fail[], const int n) {
        fail[0] = 0;
        int right = 1;
        int left = 0;
        while (right < n) {
            if (p[left] == p[right]) {
                ++left;
                fail[right] = left;
                ++right;
            } else if (left) {
                left = fail[left - 1];
            } else {
                fail[right] = 0;
                ++right;
            }
        }
    }

    void printFail(const char s[], const int s_len, const char p[], const int fail[], const int p_len) {
        int si = 0;
        int pi = 0;
        while (si < s_len) {
            if (s[si] == p[pi]) {
                ++si;
                ++pi;
            } else if (pi) {
                pi = fail[pi - 1];
            } else {
                ++si;
            }
            if (pi == p_len) {
                printf("%d ", si - p_len);
                pi = fail[pi - 1];
            }
        }
        printf("\n");
    }

    int main() {
        int p_len;
        scanf("%d", &p_len);
        char p[p_len + 1];
        scanf("%s", p);
        int s_len;
        scanf("%d", &s_len);
        char s[s_len + 1];
        scanf("%s", s);
        int fail[p_len];
        buildFail(p, fail, p_len);
        printFail(s, s_len, p, fail, p_len);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0831_H
