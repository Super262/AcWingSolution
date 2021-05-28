//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0789_H
#define ACWINGSOLUTION_PROBLEM0789_H

#include <iostream>
#include <vector>

using namespace std;

class Problem0789 {
public:
    void print_range(const vector<int> &array, const int &target) {
        unsigned long left, right, mid;
        left = 0;
        right = array.size() - 1;
        while (left < right) {
            // 选择一个靠"左"的中点；
            mid = left + (right - left) / 2;
            if (array[mid] == target) {
                right = mid;
            } else if (array[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (array[left] != target) {
            cout << "-1 -1" << endl;
            return;
        }
        cout << left << " ";
        left = 0;
        right = array.size() - 1;
        while (left < right) {
            // 选择一个靠"右"的中点；
            mid = left + (right - left + 1) / 2;
            if (array[mid] == target) {
                left = mid;
            } else if (array[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (array[left] != target) {
            cout << "-1 -1" << endl;
            return;
        }
        cout << right << endl;
    }

    int main() {
        int n, targetsCount;
        cin >> n >> targetsCount;
        vector<int> array(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
        }
        int target;
        for (int i = 0; i < targetsCount; ++i) {
            cin >> target;
            print_range(array, target);
        }
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0789_H
