//
// Created by Fengwei Zhang on 2021/6/5.
//

#ifndef ACWINGSOLUTION_PROBLEM0826_H
#define ACWINGSOLUTION_PROBLEM0826_H

#include <iostream>

using namespace std;

class Problem0826 {
private:
    const int N = 100010;
    int idx = 0, headIdx = 0, nodeValue[N], nextIdx[N];

    void add_head(int x) {
        nodeValue[idx] = x;
        nextIdx[idx] = headIdx;
        headIdx = idx++;
    }

    void add(int k, int x) {
        nodeValue[idx] = x;
        nextIdx[idx] = nextIdx[k];
        nextIdx[k] = idx++;
    }

    void remove(int k) {
        nextIdx[k] = nextIdx[nextIdx[k]];
    }

    int main() {
        int a;
        headIdx = -1;
        idx = 0;
        cin >> a;
        while (a--) {
            string op;
            int k, x;
            cin >> op;
            if (op == "D") {
                cin >> k;
                if (!k) {
                    headIdx = nextIdx[headIdx];
                }
                remove(k - 1);
            } else if (op == "H") {
                cin >> x;
                add_head(x);
            } else if (op == "I") {
                cin >> k >> x;
                add(k - 1, x);
            }
        }
        for (int i = headIdx; i != -1; i = nextIdx[i]) {
            cout << nodeValue[i] << " ";
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0826_H
