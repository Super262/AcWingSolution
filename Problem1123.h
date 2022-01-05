//
// Created by Fengwei Zhang on 10/5/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1123_H
#define ACWINGSOLUTION_PROBLEM1123_H

#include <iostream>
#include <cmath>

using namespace std;

class Problem1123 {
    // 无向图，所有边都连通，存在欧拉路径的充分必要条件：度数为奇数的点只能有0个或2个。
    //
    // 无向图，所有边都连通，存在欧拉回路的充分必要条件：度数为奇数的点只能有0个。
    //
    // 有向图，所有边都连通，存在欧拉路径的充分必要条件：所有点的出度都等于入度；
    // 或者除了2个点，其余点出度等于入度，剩余的2个点a、b，a的出度比入度多1，b的入度比出度多1，a是起点，b是终点
    //
    // 有向图，所有边都连通，存在欧拉回路的充分必要条件：所有点的出度都等于入度
private:
    int main() {
        double x1, y1, x2, y2;
        cin >> x1 >> y1;
        double length = 0;
        while (cin >> x1 >> y1 >> x2 >> y2) {
            auto dx = x2 - x1;
            auto dy = y2 - y1;
            length += sqrt(dx * dx + dy * dy) * 2;
        }
        int minutes = (int) round(length / 1000 / 20 * 60);
        int hours = minutes / 60;
        minutes %= 60;
        printf("%d:%02d\n", hours, minutes);
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM1123_H
