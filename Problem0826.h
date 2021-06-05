//
// Created by Fengwei Zhang on 2021/6/5.
//

#ifndef ACWINGSOLUTION_PROBLEM0826_H
#define ACWINGSOLUTION_PROBLEM0826_H

#include <iostream>

using namespace std;

class Problem0826 {
public:
    const int N = 100010;
    int idx = 0, head = 0, n[N], ne[N];

    void add_head(int x) {
        n[idx] = x;
        ne[idx] = head;
        head = idx++;
    }

    void add(int k, int x) {
        n[idx] = x;
        ne[idx] = ne[k];
        ne[k] = idx++;
    }

    void remove(int k) {
        ne[k] = ne[ne[k]];
    }

    int main() {
        int a;
        head = -1;
        idx = 0;
        cin >> a;
        while (a--) {
            string op;
            int k, x;
            cin >> op;
            if (op == "D") {

                cin >> k;
                if (!k)head = ne[head];
                remove(k - 1);
            } else if (op == "H") {
                cin >> x;
                add_head(x);
            } else if (op == "I") {
                cin >> k >> x;
                add(k - 1, x);
            }
        }
        for (int i = head; i != -1; i = ne[i])
            cout << n[i] << " ";
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0826_H
