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
public:
    const int N = 64;
    int partSize[N];
    bool isSelected[N];

    bool dfs(const int packIdx,
             const int currentPackSize,
             const int packMaxVolume,
             const int partIdx,
             const int partsNum,
             const int partsSizeSum) {
        if (packIdx * packMaxVolume == partsSizeSum) {
            return true;
        }
        if (currentPackSize == packMaxVolume) {
            return dfs(packIdx + 1, 0, packMaxVolume, 0, partsNum, partsSizeSum);
        }
        for (int i = partIdx; i < partsNum; ++i) {
            if (isSelected[i]) {
                continue;
            }
            if (currentPackSize + partSize[i] > packMaxVolume) {
                continue;
            }
            isSelected[i] = true;
            if (dfs(packIdx, currentPackSize + partSize[i], packMaxVolume, i + 1, partsNum, partsSizeSum)) {
                return true;
            }
            isSelected[i] = false;
            if (currentPackSize == 0 || currentPackSize + partSize[i] == packMaxVolume) {
                return false;
            }
            int nextI = i;
            while (nextI < partsNum && partSize[nextI] == partSize[i]) {
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
            int partsSizeSum = 0;
            for (int i = 0; i < n; ++i) {
                scanf("%d", &partSize[i]);
                partsSizeSum += partSize[i];
            }
            sort(partSize, partSize + n);
            reverse(partSize, partSize + n);
            memset(isSelected, 0, sizeof isSelected);
            int packMaxVolume = 1;
            while (true) {
                if (partsSizeSum % packMaxVolume == 0 && dfs(0, 0, packMaxVolume, 0, n, partsSizeSum)) {
                    break;
                }
                ++packMaxVolume;
            }
            printf("%d\n", packMaxVolume);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0167_H
