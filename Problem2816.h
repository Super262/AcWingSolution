//
// Created by Fengwei Zhang on 2021/6/4.
//

#ifndef ACWINGSOLUTION_PROBLEM2816_H
#define ACWINGSOLUTION_PROBLEM2816_H

#include <vector>
#include <iostream>

using namespace std;

class Problem2816 {
public:
    bool isSubseq(const int a[], const unsigned int m, const int b[], const unsigned int n) {
        unsigned int i = 0;
        unsigned int j = 0;
        while(j < n && i < m) {
            if(a[i] == b[j]) {
                ++i;
            }
            ++j;
        }
        if (i == m) {
            return true;
        }
        return false;
    }

    int main() {
        unsigned int m, n;
        scanf("%d%d", &m, &n);
        auto a = new int[m];
        auto b = new int[n];
        for (unsigned int i = 0; i < m; ++i) {
            scanf("%d", &a[i]);
        }
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }
        if (isSubseq(a, m, b, n)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        delete[] a;
        delete[] b;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM2816_H
