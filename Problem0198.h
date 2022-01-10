//
// Created by Fengwei Zhang on 1/10/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0198_H
#define ACWINGSOLUTION_PROBLEM0198_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0198 {
    // https://www.acwing.com/solution/content/12080/
private:
    void Dfs(int p_idx, const int primes[], int max_power, int f_cnt, int &answer, int temp, int &result, int n) {
        if (f_cnt > answer || (answer == f_cnt && temp < result)) {
            result = temp;
            answer = f_cnt;
        }
        if (p_idx == 9) {
            return;
        }
        for (int i = 1; i <= max_power; ++i) {
            if ((long long) temp * primes[p_idx] > n) {
                return;
            }
            temp *= primes[p_idx];
            // 注意约数的计算：f_cnt * (i + 1)
            Dfs(p_idx + 1, primes, max_power, f_cnt * (i + 1), answer, temp, result, n);
        }
    }

    int main() {
        const int primes[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
        const int max_power = 30;
        int answer = 1;
        int result = 1;
        int n;
        scanf("%d", &n);
        Dfs(0, primes, max_power, 1, answer, 1, result, n);
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0198_H
