//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0017_H
#define ACWINGSOLUTION_PROBLEM0017_H

#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next{};

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Problem0017 {
public:
    vector<int> printListReversingly(ListNode *head) {
        vector<int> result;
        while (head) {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0017_H
