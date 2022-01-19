//
// Created by Fengwei Zhang on 1/19/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0106_H
#define ACWINGSOLUTION_PROBLEM0106_H

#include <iostream>
#include <queue>

using namespace std;

class Problem0106 {
private:
    int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
            int k, n;
            scanf("%d%d", &k, &n);
            printf("%d %d\n", k, (n + 1) / 2);
            priority_queue<int, vector<int>, greater<int>> down;
            priority_queue<int, vector<int>, less<int>> up;
            int cnt = 0;
            for (int i = 1; i <= n; ++i) {
                int x;
                scanf("%d", &x);
                if (up.empty() || x <= up.top()) {
                    up.emplace(x);
                } else {
                    down.emplace(x);
                }
                if (up.size() > down.size() + 1) {
                    down.emplace(up.top());
                    up.pop();
                }
                if (up.size() < down.size()) {
                    up.emplace(down.top());
                    down.pop();
                }
                if (i % 2) {
                    printf("%d ", up.top());
                    ++cnt;
                    if (cnt % 10 == 0) {
                        printf("\n");
                    }
                }
            }
            if (cnt % 10) {  // 输出结束，仍未输出回车，最后添加回车
                printf("\n");
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0106_H
