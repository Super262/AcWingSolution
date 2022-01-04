//
// Created by Fengwei Zhang on 1/4/22.
//

#ifndef ACWINGSOLUTION_PROBLEM0376_H
#define ACWINGSOLUTION_PROBLEM0376_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Problem0376 {
    // 最小点覆盖 == 最大匹配数
    // https://www.acwing.com/solution/content/8921/
private:
    bool HasMatched(const int u, const vector<vector<bool>> &graph, bool visited[], int matched_idx[]) {
        for (int v = 0; v < graph[u].size(); ++v) {
            if (!graph[u][v]) {
                continue;
            }
            if (visited[v]) {
                continue;
            }
            visited[v] = true;
            if (matched_idx[v] == -1 || HasMatched(matched_idx[v], graph, visited, matched_idx)) {
                matched_idx[v] = u;
                return true;
            }
        }
        return false;
    }

    int main() {
        int n, m, k;
        while (true) {
            scanf("%d", &n);
            if (n == 0) {
                break;
            }
            scanf("%d%d", &m, &k);
            vector<vector<bool>> graph(n, vector<bool>(m, false));
            while (k--) {
                int i, a, b;
                scanf("%d%d%d", &i, &a, &b);
                if (!a || !b) {
                    continue;
                }
                graph[a][b] = true;  // 这里相当于只创建单向边
            }
            int result = 0;
            bool visited[m];
            int matched_idx[m];
            memset(matched_idx, -1, sizeof matched_idx);
            for (int v = 0; v < n; ++v) {
                memset(visited, 0, sizeof visited);
                if (HasMatched(v, graph, visited, matched_idx)) {
                    ++result;
                }
            }
            printf("%d\n", result);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0376_H
