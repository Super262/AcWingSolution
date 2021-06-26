//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0789_H
#define ACWINGSOLUTION_PROBLEM0789_H

#include <iostream>

using namespace std;

class Problem0789 {
public:
    void print_range(const int *array, unsigned long long n, const int &target) {
        unsigned long long left, right, mid;
        left = 0;
        right = n - 1;
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
            printf("-1 -1\n");
            return;
        }
        printf("%llu ", left);
        left = 0;
        right = n - 1;
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
            printf("-1 -1\n");
            return;
        }
        printf("%llu\n", right);
    }

    int main() {
        unsigned long long n;
        unsigned long long targetsCount;
        scanf("%lld%lld", &n, &targetsCount);
        auto array = new int[n];
        for (unsigned long long i = 0; i < n; ++i) {
            scanf("%d", &array[i]);
        }
        int target;
        for (unsigned long long i = 0; i < targetsCount; ++i) {
            scanf("%d", &target);
            print_range(array, n, target);
        }
        delete[] array;
        return 0;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0789_H
