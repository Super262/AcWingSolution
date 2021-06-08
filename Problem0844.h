//
// Created by Fengwei Zhang on 2021/6/8.
//

#ifndef ACWINGSOLUTION_PROBLEM0844_H
#define ACWINGSOLUTION_PROBLEM0844_H

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Problem0844 {
public:
    int bfs(vector<vector<int>> &matrix, const vector<int> &dx, const vector<int> &dy) {
        const int n = matrix.size() - 1;
        const int m = matrix[matrix.size() - 1].size() - 1;
        if (matrix[0][0] == 1 || matrix[n][m] == 1) {
            return 2147483647;
        }
        int result = 0;
        queue<pair<int, int>> q;
        q.emplace(pair<int, int>(0, 0));
        matrix[0][0] = 1;
        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize--) {
                pair<int, int> node = q.front();
                q.pop();
                if (node.first == n && node.second == m) {
                    return result;
                }
                for (int i = 0; i < dx.size() && i < dy.size(); ++i) {
                    int nextX = node.first + dx[i];
                    int nextY = node.second + dy[i];
                    if (nextX < 0 || nextX > n || nextY < 0 || nextY > m || matrix[nextX][nextY] == 1) {
                        continue;
                    }
                    q.emplace(pair<int, int>(nextX, nextY));
                    matrix[nextX][nextY] = 1;
                }
            }
            ++result;
        }
        return 2147483647;
    }

    int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (vector<int> &row:matrix) {
            for (int &num:row) {
                scanf("%d", &num);
            }
        }
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        printf("%d\n", bfs(matrix, dx, dy));
        return 0;
    }

};

#endif //ACWINGSOLUTION_PROBLEM0844_H
