//
// Created by Fengwei Zhang on 12/23/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1125_H
#define ACWINGSOLUTION_PROBLEM1125_H

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double INF = 0x3f3f3f3f;

class Problem1125 {
    // https://www.acwing.com/solution/content/8428/
private:
    double GetRealDistance(int a, int b, const vector<pair<int, int>> &points) {
        auto x1 = points[a].first;
        auto y1 = points[a].second;
        auto x2 = points[b].first;
        auto y2 = points[b].second;
        return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

    void floyd(int n, vector<vector<double>> &dist) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            points[i] = {x, y};
        }
        vector<vector<double>> dist(n, vector<double>(n, INF));
        char temp[n + 2];
        for (int i = 0; i < n; ++i) {
            scanf("%s", temp);
            for (int j = 0; j < n; ++j) {
                if (i == j) {  // 注意：Floyd初始化时，dist[a][a] = 0！
                    dist[i][j] = 0;
                    continue;
                }
                if (temp[j] == '0') {
                    continue;
                }
                dist[i][j] = GetRealDistance(i, j, points);
            }
        }
        floyd(n, dist);
        vector<double> max_length(n, 0);  // 牧场内牧区间距离的最大值
        double res_1 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] > INF / 2) {
                    continue;
                }
                max_length[i] = max(max_length[i], dist[i][j]);
                res_1 = max(res_1, max_length[i]);
            }
        }
        double res_2 = INF;  // 两个牧场的牧区间最短的距离
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] < INF / 2) {
                    continue;
                }
                res_2 = min(res_2, max_length[i] + max_length[j] + GetRealDistance(i, j, points));
            }
        }
        printf("%.6lf", max(res_1, res_2));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1125_H
