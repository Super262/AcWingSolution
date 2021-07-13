//
// Created by Fengwei Zhang on 2021/7/13.
//

#ifndef ACWINGSOLUTION_PROBLEM0275_H
#define ACWINGSOLUTION_PROBLEM0275_H

#include <iostream>

using namespace std;

const int N = 55, M = 2 * N;

int n, m;
int w[N][N];
int f[M][N][N];


class Problem0275 {
    // https://www.acwing.com/solution/content/3954/
public:
    int main() {
        //input
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> w[i][j];
            }
        }
        //dp
        for (int k = 2; k <= n + m; ++k) {
            for (int i = 1; i < k && i <= n; ++i) {
                for (int j = 1; j < k && j <= n; ++j) {
                    int v = w[i][k - i];
                    if (i != j) v += w[j][k - j];

                    int &t = f[k][i][j];
                    t = max(t, f[k - 1][i][j]);
                    t = max(t, f[k - 1][i - 1][j]);
                    t = max(t, f[k - 1][i][j - 1]);
                    t = max(t, f[k - 1][i - 1][j - 1]);
                    t += v;
                }
            }
        }

        //output
        cout << f[n + m][n][n] << endl;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0275_H
