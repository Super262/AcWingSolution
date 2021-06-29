//
// Created by Fengwei Zhang on 2021/6/5.
//

#ifndef ACWINGSOLUTION_PROBLEM0830_H
#define ACWINGSOLUTION_PROBLEM0830_H

#include <iostream>
#include <stack>

using namespace std;


class Problem0830 {
public:
    int closestSmaller(stack<int> &s, const int num) {
        while (!s.empty() && s.top() >= num) {
            s.pop();
        }
        int result;
        if (s.empty()) {
            result = -1;
        } else {
            result = s.top();
        }
        s.emplace(num);
        return result;
    }

    int main() {
        unsigned int n;
        scanf("%d", &n);
        int num;
        stack<int> s;
        for (unsigned int i = 0; i < n; ++i) {
            scanf("%d", &num);
            printf("%d ", closestSmaller(s, num));
        }
        printf("\n");
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0830_H
