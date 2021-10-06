//
// Created by Fengwei Zhang on 10/5/21.
//

#ifndef ACWINGSOLUTION_PROBLEM1123_H
#define ACWINGSOLUTION_PROBLEM1123_H

#include <iostream>
#include <cmath>

using namespace std;

class Problem1123 {
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
