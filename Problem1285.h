//
// Created by Fengwei Zhang on 1/19/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1285_H
#define ACWINGSOLUTION_PROBLEM1285_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1285 {
    // https://www.acwing.com/solution/content/44953/
private:
    static const int M = 1000002, K = 26;
    int tree[M][K], counter[M], fail[M];

    int InsertWord(const char s[], int &idx) {
        int p = 0;
        for (int i = 0; s[i]; ++i) {
            auto ch = s[i] - 'a';
            if (!tree[p][ch]) {
                tree[p][ch] = ++idx;
            }
            p = tree[p][ch];
            ++counter[p];
        }
        return p;
    }

    void BuildAC(int q[]) {
        int hh = 0, tt = -1;
        for (int i = 0; i < K; ++i) {
            if (!tree[0][i]) {
                continue;
            }
            q[++tt] = tree[0][i];
        }
        while (hh <= tt) {
            auto cur = q[hh++];
            for (int i = 0; i < K; ++i) {
                auto p = tree[cur][i];
                if (p) {
                    fail[p] = tree[fail[cur]][i];
                    q[++tt] = p;
                } else {
                    tree[cur][i] = tree[fail[cur]][i];
                }
            }
        }
    }

    int main() {
        char str[M];
        memset(str, 0, sizeof str);
        memset(tree, 0, sizeof tree);
        memset(counter, 0, sizeof counter);
        memset(fail, 0, sizeof fail);
        int n;
        scanf("%d", &n);
        int wid[n];
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", str);
            wid[i] = InsertWord(str, idx);
        }
        int q[M];
        BuildAC(q);
        for (int i = idx; i >= 0; --i) {
            counter[fail[q[i]]] += counter[q[i]];
        }
        for (int i = 0; i < n; ++i) {
            printf("%d\n", counter[wid[i]]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1285_H
