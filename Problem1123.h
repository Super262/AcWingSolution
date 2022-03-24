//
// Created by Fengwei Zhang on 10/5/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1123_H
#define ACWINGSOLUTION_PROBLEM1123_H

#include <iostream>
#include <cmath>

using namespace std;

class Problem1123 {
    // 无向图，所有边都连通，存在欧拉路径的充分必要条件：度数为奇数的点只能有0个或2个，度数为奇数的点是起点和终点。
    //
    // 无向图，所有边都连通，存在欧拉回路的充分必要条件：度数为奇数的点只能有0个。
    //
    // 有向图，所有边都连通，存在欧拉路径的充分必要条件：所有点的出度都等于入度；
    // 或者除了2个点，其余点出度等于入度，剩余的2个点a、b，a的出度比入度多1，b的入度比出度多1，a是起点，b是终点
    //
    // 有向图，所有边都连通，存在欧拉回路的充分必要条件：所有点的出度都等于入度
private:
    int main() {
        long x1, y1, x2, y2;  // 防止溢出发生（dx * dx）
        scanf("%ld%ld", &x1, &x2);
        long double length = 0;
        while (scanf("%ld%ld%ld%ld", &x1, &y1, &x2, &y2) != -1) {
            auto dx = x2 - x1;
            auto dy = y2 - y1;
            length += sqrt(dx * dx + dy * dy) * 2;  // 不要忘记乘2：双向道路
        }
        auto minutes = (long) round(length / 1000 / 20 * 60);
        auto hours = minutes / 60;
        minutes %= 60;
        printf("%ld:%02ld\n", hours, minutes);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1123_H
