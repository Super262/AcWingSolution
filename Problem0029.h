//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0029_H
#define ACWINGSOLUTION_PROBLEM0029_H

struct ListNode {
    int val;
    ListNode *next{};

    explicit ListNode(int x) : val(x), next(NULL) {}
};

class Problem0029 {
public:
    ListNode *deleteDuplication(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        auto *dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while (p->next) {
            auto q = p->next;
            while (q->next && p->next->val == q->next->val) {
                q = q->next;
            }
            if (q != p->next) {
                p->next = q->next;
            } else {
                p = q;
            }
        }
        return dummy->next;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0029_H
