//
// Created by Fengwei Zhang on 2021/5/27.
//

#ifndef ACWINGSOLUTION_PROBLEM0035_H
#define ACWINGSOLUTION_PROBLEM0035_H

struct ListNode {
    int val;
    ListNode *next{};

    explicit ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *prev_node = nullptr;
        ListNode *current = head;
        ListNode *next_node = head->next;
        while (next_node) {
            current->next = prev_node;
            prev_node = current;
            current = next_node;
            next_node = next_node->next;
        }
        current->next = prev_node;
        return current;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0035_H
