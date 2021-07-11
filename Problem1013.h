//
// Created by Fengwei Zhang on 2021/7/11.
//

#ifndef ACWINGSOLUTION_PROBLEM1013_H
#define ACWINGSOLUTION_PROBLEM1013_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1013 {
public:
    int solutionForMaxValue(const int kindsNum, const int packVolume, int **itemsValue, int *solution) {
        auto dp = new int *[kindsNum + 1];
        for (int i = 0; i <= kindsNum; ++i) {
            dp[i] = new int[packVolume + 1];
            memset(dp[i], 0, sizeof(int) * (packVolume + 1));
        }
        for (int i = 1; i <= kindsNum; ++i) {
            for (int v = 0; v <= packVolume; ++v) {
                for (int j = 0; j <= v; ++j) {
                    dp[i][v] = max(dp[i][v], dp[i - 1][v - j] + itemsValue[i][j]);
                }
            }
        }
        int result = dp[kindsNum][packVolume];
        int currentPackVolume = packVolume;
        for (int i = kindsNum; i >= 1; --i) {
            for (int j = 0; j <= currentPackVolume; ++j) {
                if (dp[i][currentPackVolume] == dp[i - 1][currentPackVolume - j] + itemsValue[i][j]) {
                    solution[i] = j;
                    currentPackVolume -= j;
                    break;
                }
            }
        }
        for (int i = 0; i <= kindsNum; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }

    int main() {
        int kindsNum;
        int packVolume;
        scanf("%d%d", &kindsNum, &packVolume);
        auto itemsValue = new int *[kindsNum + 1];
        for (int i = 0; i <= kindsNum; ++i) {
            itemsValue[i] = new int[packVolume + 1];
            memset(itemsValue[i], 0, sizeof(int) * (packVolume + 1));
        }
        for (int i = 1; i <= kindsNum; ++i) {
            for (int j = 1; j <= packVolume; ++j) {
                scanf("%d", &itemsValue[i][j]);
            }
        }
        auto solution = new int[kindsNum + 1];
        printf("%d\n", solutionForMaxValue(kindsNum, packVolume, itemsValue, solution));
        for (int i = 1; i <= kindsNum; ++i) {
            printf("%d %d\n", i, solution[i]);
        }
        for (int i = 0; i <= kindsNum; ++i) {
            delete[] itemsValue[i];
        }
        delete[] itemsValue;
        delete[] solution;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1013_H
