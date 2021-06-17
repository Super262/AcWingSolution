//
// Created by Fengwei Zhang on 2021/6/17.
//

#ifndef ACWINGSOLUTION_PROBLEM0002_H
#define ACWINGSOLUTION_PROBLEM0002_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0002 {
public:
    unsigned int knapsackMaxValue(const unsigned int *size,
                                  const unsigned int *value,
                                  const unsigned int count,
                                  const unsigned int volume) {
        auto *dp = new unsigned int[volume + 1];
        memset(dp, 0, sizeof(unsigned int));
        for (unsigned int i = 0; i < count; ++i) {
            for (unsigned int j = volume; j >= size[i]; --j) {
                dp[j] = max(dp[j], dp[j - size[i]] + value[i]);
            }
        }
        auto result = dp[volume];
        delete[] dp;
        return result;
    }

    int main() {
        unsigned int count, volume;
        scanf("%d%d", &count, &volume);
        auto size = new unsigned int[count];
        auto value = new unsigned int[count];
        for (unsigned int i = 0; i < count; ++i) {
            scanf("%d%d", &size[i], &value[i]);
        }
        printf("%d\n", knapsackMaxValue(size, value, count, volume));
        delete[] size;
        delete[] value;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0002_H
