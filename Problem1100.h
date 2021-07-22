//
// Created by Fengwei Zhang on 2021/7/22.
//

#ifndef ACWINGSOLUTION_PROBLEM1100_H
#define ACWINGSOLUTION_PROBLEM1100_H

#include <iostream>
#include <cstring>

using namespace std;

class Problem1100 {
public:
    const int N = 200001;
    int q[N];
    int dist[N];

    int bfs(const int start, const int end) {
        int hh = 0, tt = -1;
        memset(dist, -1, sizeof dist);
        dist[start] = 0;
        q[++tt] = start;
        while (hh <= tt) {
            auto root = q[hh++];
            if (root == end) {
                return dist[end];
            }
            if (root + 1 >= 0 && root + 1 <= N && dist[root + 1] == -1) {
                q[++tt] = root + 1;
                dist[root + 1] = dist[root] + 1;
            }
            if (root - 1 >= 0 && root - 1 <= N && dist[root - 1] == -1) {
                q[++tt] = root - 1;
                dist[root - 1] = dist[root] + 1;
            }
            if (root * 2 >= 0 && root * 2 <= N && dist[root * 2] == -1) {
                q[++tt] = root * 2;
                dist[root * 2] = dist[root] + 1;
            }
        }
        return -1;
    }

    int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", bfs(n, k));
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1100_H
