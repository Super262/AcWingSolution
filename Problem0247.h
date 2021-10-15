//
// Created by Fengwei Zhang on 9/23/21.
//

#ifndef ACWINGSOLUTION_PROBLEM0247_H
#define ACWINGSOLUTION_PROBLEM0247_H

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


class Problem0247 {
    // "扫描线"基于线段树：
    // 永远只考虑根结点信息（查询时不会调用pushDown）；
    // 所有的操作都是成对出现（先加后减，成对出现，修改节点时不调用pushDown）；
private:
    struct Segment {
        double x, y1, y2;  // y轴方向线段
        int k;  // 线段权值：1 / -1
        bool operator<(const Segment &t) const {
            return x < t.x;
        }
    };

    struct Node {
        int l, r;  // 左右端点索引
        int cnt;  // 被矩形覆盖的次数
        double length;  // 总长度
    };

    const int N = 10010;
    Segment segments[N * 2];
    Node nodes[N * 2 * 4];
    vector<double> ys;  // 离散化y值

    int getIdx(double y) {
        return (int) (lower_bound(ys.begin(), ys.end(), y) - ys.begin());
    }

    void pushUp(const int idx) {
        if (nodes[idx].cnt != 0) {
            nodes[idx].length = ys[nodes[idx].r + 1] - ys[nodes[idx].l];
            return;
        }
        if (nodes[idx].l != nodes[idx].r) {
            nodes[idx].length = nodes[idx << 1].length + nodes[idx << 1 | 1].length;
        } else {
            nodes[idx].length = 0;
        }
    }

    void buildTree(const int idx, const int l, const int r) {
        nodes[idx] = {l, r, 0, 0};
        if (l == r) {
            return;
        }
        auto mid = l + ((r - l) >> 1);
        buildTree(idx << 1, l, mid);
        buildTree(idx << 1 | 1, mid + 1, r);
    }

    void modifyNode(const int idx, const int l, const int r, const int val) {
        if (nodes[idx].l >= l && nodes[idx].r <= r) {
            nodes[idx].cnt += val;
            pushUp(idx);
            return;
        }
        auto mid = nodes[idx].l + ((nodes[idx].r - nodes[idx].l) >> 1);
        if (l <= mid) {
            modifyNode(idx << 1, l, r, val);
        }
        if (r > mid) {
            modifyNode(idx << 1 | 1, l, r, val);
        }
        pushUp(idx);
    }

    int main() {
        int k = 1;
        int n;
        while (true) {
            scanf("%d", &n);
            if (n == 0) {
                break;
            }
            ys.clear();
            for (int i = 0, j = 0; i < n; ++i) {
                double x1, y1, x2, y2;
                scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
                segments[j++] = {x1, y1, y2, 1};
                segments[j++] = {x2, y1, y2, -1};
                ys.push_back(y1);
                ys.push_back(y2);
            }
            sort(ys.begin(), ys.end());
            ys.erase(unique(ys.begin(), ys.end()), ys.end());
            buildTree(1, 0, (int) ys.size() - 2);
            sort(segments, segments + 2 * n);
            double result = 0;
            for (int i = 0; i < 2 * n; ++i) {
                if (i > 0) {
                    result += nodes[1].length * (segments[i].x - segments[i - 1].x);
                }
                modifyNode(1, getIdx(segments[i].y1), getIdx(segments[i].y2) - 1, segments[i].k);
            }
            printf("Test case #%d\nTotal explored area: %.2lf\n\n", k, result);
            ++k;
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0247_H
