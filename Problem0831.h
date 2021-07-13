//
// Created by Fengwei Zhang on 2021/6/6.
//

#ifndef ACWINGSOLUTION_PROBLEM0831_H
#define ACWINGSOLUTION_PROBLEM0831_H

#include <iostream>

using namespace std;

class Problem0831 {
public:
    void buildNext(const char str[], unsigned long long nextStart[], const unsigned long long len) {
        unsigned long long i = 1;
        unsigned long long now = 0;
        nextStart[0] = 0;
        while (i < len) {
            if (str[i] == str[now]) {
                ++now;
                nextStart[i] = now;
                ++i;
            } else if (now) {
                now = nextStart[now - 1];
            } else {
                nextStart[i] = 0;
                ++i;
            }
        }
    }

    void printMatchedStart(const char s[],
                           const unsigned long long sLen,
                           const char p[],
                           const unsigned long long nextStart[],
                           const unsigned long long pLen) {
        unsigned long long i = 0;
        unsigned long long j = 0;
        while (i < sLen) {
            if (s[i] == p[j]) {
                ++i;
                ++j;
            } else if (j) {
                j = nextStart[j - 1];
            } else {
                ++i;
            }
            if (j == pLen) {
                printf("%llu ", i - pLen);
                j = nextStart[j - 1];
            }
        }
        printf("\n");
    }

    int main() {
        unsigned long long m;
        scanf("%lld", &m);
        auto p = new char[m + 1];
        scanf("%s", p);
        unsigned long long n;
        scanf("%lld", &n);
        auto s = new char[n + 1];
        scanf("%s", s);
        auto nextStart = new unsigned long long[m];
        buildNext(p, nextStart, m);
        printMatchedStart(s, n, p, nextStart, m);
        delete[] p;
        delete[] s;
        delete[] nextStart;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0831_H
