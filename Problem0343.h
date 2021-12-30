//
// Created by Fengwei Zhang on 12/23/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0343_H
#define ACWINGSOLUTION_PROBLEM0343_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Problem0343 {
private:
    void Floyd(const int n, vector<vector<bool>> &dist) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!dist[i][k] || !dist[k][j]) {
                        continue;
                    }
                    dist[i][j] = true;
                }
            }
        }
    }

    int Check(const int n, const vector<vector<bool>> &dist) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][i]) {
                return 2;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {   // 避免重复计算，j < i
                if (!dist[i][j] && !dist[j][i]) {
                    return 0;
                }
            }
        }
        return 1;
    }

    char *GetSequence(const int n, const vector<vector<bool>> &dist) {
        struct Node {
            char ch;
            int level;

            bool operator<(Node &node) const {
                return level < node.level;
            }
        };
        auto res = new char[n + 1];
        Node nodes[n];
        for (int i = 0; i < n; ++i) {
            nodes[i] = {(char) ('A' + i), 0};
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dist[i][j]) {
                    ++nodes[j].level;
                } else {
                    ++nodes[i].level;
                }
            }
        }
        sort(nodes, nodes + n);
        for (int i = 0; i < n; ++i) {
            res[i] = nodes[i].ch;
        }
        res[n] = '\0';
        return res;
    }

    int main() {
        while (true) {
            int n, m;
            scanf("%d%d", &n, &m);
            if (n == 0 && m == 0) {
                break;
            }
            vector<vector<bool>> graph(n, vector<bool>(n, false));
            int t = 0;  // 语句个数
            int type = 0;  // 0：没有矛盾，1：关系确定，2：有矛盾
            char temp[4];
            for (int i = 0; i < m; ++i) {
                scanf("%s", temp);
                if (type > 0) {
                    continue;
                }
                auto a = (int) (temp[0] - 'A');
                auto b = (int) (temp[2] - 'A');
                graph[a][b] = true;
                Floyd(n, graph);
                type = Check(n, graph);
                ++t;
            }
            if (type == 0) {
                printf("Sorted sequence cannot be determined.\n");
            } else if (type == 2) {
                printf("Inconsistency found after %d relations.\n", t);
            } else {
                printf("Sorted sequence determined after %d relations: %s.\n", t, GetSequence(n, graph));
            }
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0343_H
