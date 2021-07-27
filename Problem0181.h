//
// Created by Fengwei Zhang on 2021/7/27.
//

#ifndef ACWINGSOLUTION_PROBLEM0181_H
#define ACWINGSOLUTION_PROBLEM0181_H

#include <iostream>
#include <algorithm>

using namespace std;

class Problem0181 {
    // https://www.acwing.com/solution/content/4056/
    /*
      0     1
      2     3
4  5  6  7  8  9  10
      11    12
13 14 15 16 17 18 19
      20    21
      22    23
*/
public:
    int point[24];
    int opScope[8][7] = {
            {0,  2,  6,  11, 15, 20, 22},
            {1,  3,  8,  12, 17, 21, 23},
            {10, 9,  8,  7,  6,  5,  4},
            {19, 18, 17, 16, 15, 14, 13},
            {23, 21, 17, 12, 8,  3,  1},
            {22, 20, 15, 11, 6,  2,  0},
            {13, 14, 15, 16, 17, 18, 19},
            {4,  5,  6,  7,  8,  9,  10}
    };
    int centralArea[8] = {6, 7, 8, 11, 12, 15, 16, 17};
    int inverseOperation[8] = {5, 4, 7, 6, 1, 0, 3, 2};

    int funcF() {
        int freq[4] = {0, 0, 0, 0};
        for (int i : centralArea) {
            ++freq[point[i]];
        }
        int s = 0;
        for (int i = 1; i <= 3; i++) s = max(s, freq[i]);
        return 8 - s;
    }

    void doOperation(const int opIdx) {
        int t = point[opScope[opIdx][0]];
        for (int i = 1; i < 7; ++i) {
            point[opScope[opIdx][i - 1]] = point[opScope[opIdx][i]];
        }
        point[opScope[opIdx][6]] = t;
    }

    bool dfs(const int currentDepth, const int maxDepth, const int prevOpIdx, string &path) {
        if (currentDepth + funcF() > maxDepth) {
            return false;
        }
        if (funcF() == 0) {
            return true;
        }
        for (int opIdx = 0; opIdx < 8; ++opIdx) {
            if (inverseOperation[opIdx] == prevOpIdx) {
                continue;
            }
            doOperation(opIdx);
            path.push_back((char) ('A' + opIdx));
            if (dfs(currentDepth + 1, maxDepth, opIdx, path)) {
                return true;
            }
            doOperation(inverseOperation[opIdx]);
            path.pop_back();
        }
        return false;
    }

    int main() {
        while (true) {
            int first;
            scanf("%d", &first);
            if (first == 0) {
                break;
            }
            point[0] = first;
            for (int i = 1; i < 24; ++i) {
                scanf("%d", &point[i]);
            }
            int maxDepth = 0;
            string path;
            while (!dfs(0, maxDepth, -1, path)) {
                ++maxDepth;
            }
            if (maxDepth == 0) {
                printf("No moves needed\n");
            } else {
                printf("%s\n", path.data());
            }
            printf("%d\n", point[centralArea[0]]);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0181_H
