//
// Created by Fengwei Zhang on 2021/6/5.
//

#ifndef ACWINGSOLUTION_PROBLEM0829_H
#define ACWINGSOLUTION_PROBLEM0829_H

#include <iostream>

using namespace std;

class Problem0829 {
public:
    void pop(unsigned long &front, unsigned long m) {
        ++front;
        front %= m;
    }

    void push(const int value, int data[], unsigned long &end, unsigned long m) {
        data[end++] = value;
        end %= m;
    }

    bool empty(const unsigned long front, const unsigned long end) {
        return front == end;
    }

    int peek(const int data[], const unsigned long front) {
        return data[front];
    }

    int main() {
        unsigned long m;
        cin >> m;
        int data[m];
        unsigned long front = 0;
        unsigned long end = 0;
        string op;
        int value;
        for (int i = 0; i < m; ++i) {
            cin >> op;
            if (op == "push") {
                cin >> value;
                push(value, data, end, m);
            } else if (op == "query") {
                cout << peek(data, front) << endl;
            } else if (op == "empty") {
                cout << (empty(front, end) ? "YES" : "NO") << endl;
            } else {
                pop(front, m);
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0829_H
