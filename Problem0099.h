//
// Created by Fengwei Zhang on 10/30/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0099_H
#define ACWINGSOLUTION_PROBLEM0099_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem0099 {
private:
    const int N = 5001;

    int main() {
        int graph[N + 10][N + 10];
        memset(graph, 0, sizeof graph);
        int n, r;
        scanf("%d%d", &n, &r);  // 注意：r可能多于5000
        r = min(r, N);
        int x, y, w;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            graph[x + 1][y + 1] += w;  // 不同目标可能在同一位置（不是等于，要加上原有的）！
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                graph[i][j] += graph[i - 1][j] + graph[i][j - 1] - graph[i - 1][j - 1];
            }
        }
        int result = 0;
        for (int si = 1; si + r - 1 <= N; ++si) {
            auto ei = si + r - 1;
            for (int sj = 1; sj + r - 1 <= N; ++sj) {
                auto ej = sj + r - 1;
                result = max(result, graph[ei][ej] + graph[si - 1][sj - 1] - graph[ei][sj - 1] - graph[si - 1][ej]);
            }
        }
        printf("%d\n", result);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0099_H
