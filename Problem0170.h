//
// Created by Fengwei Zhang on 2021/7/26.
//

#ifndef ACWINGSOLUTION_PROBLEM0170_H
#define ACWINGSOLUTION_PROBLEM0170_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0170 {
    // https://www.acwing.com/solution/content/38248/
    // 1. 优先枚举较大的数
    // 2. 排除等效冗余：如果某两组数的和相等，我们只枚举其中一组
private:
    int path[101];
    bool isSelected[101];

    bool dfs(const int prevDepth, const int maxDepth, const int n) {
        if (prevDepth == maxDepth) {
            return path[prevDepth] == n;
        }
        for (int i = prevDepth; i >= 0; --i) {
            for (int j = i; j >= 0; --j) {
                int nextNum = path[i] + path[j];
                if (nextNum > n || nextNum <= path[prevDepth] || isSelected[nextNum]) {
                    continue;
                }
                isSelected[nextNum] = true;
                path[prevDepth + 1] = nextNum;
                if (dfs(prevDepth + 1, maxDepth, n)) {
                    return true;
                }
                isSelected[nextNum] = false;
            }
        }
        return false;
    }

    int main() {
        int n;
        while (true) {
            scanf("%d", &n);
            if (n == 0) {
                break;
            }
            int maxDepth = 0;
            path[0] = 1;
            memset(isSelected, 0, sizeof isSelected);
            while (!dfs(0, maxDepth, n)) {
                ++maxDepth;
            }
            for (int i = 0; i <= maxDepth; ++i) {
                printf("%d ", path[i]);
            }
            printf("\n");
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0170_H
