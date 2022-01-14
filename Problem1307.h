//
// Created by Fengwei Zhang on 1/13/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1307_H
#define ACWINGSOLUTION_PROBLEM1307_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1307 {
private:
    int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        int f[n + 1];
        int s[n + 1];
        memset(f, 0, sizeof f);
        memset(s, 0, sizeof s);
        f[0] = 1;
        s[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = s[max(0, i - k - 1)];
            s[i] = (s[i - 1] + f[i]) % 5000011;
        }
        printf("%d\n", s[n]);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1307_H
