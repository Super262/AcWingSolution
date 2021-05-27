//
// Created by Fengwei Zhang on 2021/5/27.
//

#ifndef ACWINGSOLUTION_PROBLEM0028_H
#define ACWINGSOLUTION_PROBLEM0028_H

struct ListNode {
    int val;
    ListNode *next{};

    explicit ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode *node) {
        ListNode *temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        temp->next = nullptr;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0028_H
