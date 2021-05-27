//
// Created by Fengwei Zhang on 2021/5/27.
//

#ifndef ACWINGSOLUTION_PROBLEM0036_H
#define ACWINGSOLUTION_PROBLEM0036_H

struct ListNode {
    int val;
    ListNode *next{};

    explicit ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1) {
            current->next = l1;
        }
        if (l2) {
            current->next = l2;
        }
        return dummy->next;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0036_H
