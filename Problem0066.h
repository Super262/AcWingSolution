//
// Created by Fengwei Zhang on 2021/5/28.
//

#ifndef ACWINGSOLUTION_PROBLEM0066_H
#define ACWINGSOLUTION_PROBLEM0066_H

struct ListNode {
    int val;
    ListNode *next{};

    explicit ListNode(int x) : val(x), next(NULL) {}
};

class Problem0066 {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (true) {
            if (!p1 && !p2) {
                break;
            }
            if (p1 == p2) {
                return p1;
            }
            if (!p1) {
                p1 = headB;
            } else {
                p1 = p1->next;
            }
            if (!p2) {
                p2 = headA;
            } else {
                p2 = p2->next;
            }
        }
        return nullptr;
    }
};

#endif //ACWINGSOLUTION_PROBLEM0066_H
