//
// Created by Fengwei Zhang on 2021/7/26.
//

#ifndef ACWINGSOLUTION_PROBLEM0167_H
#define ACWINGSOLUTION_PROBLEM0167_H

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem0167 {
    // https://www.acwing.com/solution/content/36030/（代码错误：调用的开始索引应从1开始）
    // 按照组合数枚举：
    // 1. 从大到小枚举木棍；
    // 2. 当前木棍加入到组合中失败，直接略过后面所有与其相等的木棍；
    // 3. 第1根木棍失败，当前组合一定失败；
    // 4. 最后1根失败，当前组合一定失败。
private:
    static const int N = 64;
    int parts[N];
    bool isSelected[N];

    bool dfs(const int packIdx,
             const int packCapacity,
             const int partIdx,
             const int partsNum,
             const int currentPartsSum,
             const int allPartsSum) {
        if (packIdx * packCapacity == allPartsSum) {
            return true;
        }
        if (currentPartsSum == packCapacity) {
            return dfs(packIdx + 1, packCapacity, 0, partsNum, 0, allPartsSum);
        }
        for (int i = partIdx; i < partsNum; ++i) {
            if (isSelected[i]) {
                continue;
            }
            if (currentPartsSum + parts[i] > packCapacity) {
                continue;
            }
            isSelected[i] = true;
            if (dfs(packIdx, packCapacity, i + 1, partsNum, currentPartsSum + parts[i], allPartsSum)) {
                return true;
            }
            isSelected[i] = false;
            if (currentPartsSum == 0 || currentPartsSum + parts[i] == packCapacity) {
                return false;
            }
            int nextI = i;
            while (nextI < partsNum && parts[nextI] == parts[i]) {
                ++nextI;
            }
            i = nextI - 1;
        }
        return false;
    }

    int main() {
        while (true) {
            int n;
            scanf("%d", &n);
            if (n == 0) {
                break;
            }
            int allPartsSum = 0;
            for (int i = 0; i < n; ++i) {
                scanf("%d", &parts[i]);
                allPartsSum += parts[i];
            }
            sort(parts, parts + n);
            reverse(parts, parts + n);
            memset(isSelected, 0, sizeof isSelected);
            int packCapacity = 1;
            while (true) {
                if (allPartsSum % packCapacity == 0 && dfs(0, packCapacity, 0, n, 0, allPartsSum)) {
                    break;
                }
                ++packCapacity;
            }
            printf("%d\n", packCapacity);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0167_H
