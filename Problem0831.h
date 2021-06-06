//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0831_H
#define ACWINGSOLUTION_PROBLEM0831_H

#include <iostream>

using namespace std;

class Problem0831 {
public:
    void buildNext(const char s[], unsigned long next[], const unsigned long l) {
        unsigned long i = 1;
        unsigned long now = 0;
        next[0] = 0;
        while (i < l) {
            if (s[i] == s[now]) {
                ++now;
                next[i] = now;
                ++i;
            } else if (now) {
                now = next[now - 1];
            } else {
                next[i] = 0;
                ++i;
            }
        }
    }

    void printMatchedStart(const char s[], const unsigned long s_l, const char p[], const unsigned long p_l,
                           const unsigned long next[]) {
        unsigned long p_now = 0;
        unsigned long s_now = 0;
        while (s_now < s_l) {
            if (p[p_now] == s[s_now]) {
                ++p_now;
                ++s_now;
            } else if (p_now) {
                p_now = next[p_now - 1];
            } else {
                ++s_now;
            }
            if (p_now == p_l) {
                printf("%ld ", s_now - p_l);
                p_now = next[p_now - 1];
            }
        }
        printf("\n");
    }

    int main() {
        unsigned long n, m;
        scanf("%ld", &n);
        auto *p = new char[n + 1];
        scanf("%s", p);
        scanf("%ld", &m);
        auto *s = new char[m + 1];
        scanf("%s", s);
        auto *next = new unsigned long[n];
        buildNext(p, next, n);
        printMatchedStart(s, m, p, n, next);
        delete[] p;
        delete[] s;
        delete[] next;
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0831_H
