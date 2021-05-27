//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0020_H
#define ACWINGSOLUTION_PROBLEM0020_H

#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    /** Initialize your data structure here. */
    MyQueue() = default;

    /** Push element x to the back of queue. */
    void push(int x) {
        while (!s2.empty()) {
            s1.emplace(s2.top());
            s2.pop();
        }
        s1.emplace(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (!s1.empty()) {
            s2.emplace(s1.top());
            s1.pop();
        }
        int res = s2.top();
        s2.pop();
        return res;
    }

    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.emplace(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

#endif //ACWINGSOLUTION_PROBLEM0020_H
