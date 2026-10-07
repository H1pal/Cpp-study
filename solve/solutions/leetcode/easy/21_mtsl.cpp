//
// Created by gmlvkf282 on 26. 10. 7..
//

#include "Easy.h"

namespace easy {
    ListNode* mergeTwoLists(ListNode* &list1, ListNode* &list2) {
        const int MAX_VALUE = 100;
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;

        while (list1 != nullptr || list2 != nullptr) {
            const int val1 = (list1 != nullptr) ? list1->val : MAX_VALUE+1;
            const int val2 = (list2 != nullptr) ? list2->val : MAX_VALUE+1;

            if (val1 < val2) {
                head->next = list1;
                list1 = list1->next;
            }
            else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }

        if (list1 != nullptr) head->next = list1;
        if (list2 != nullptr) head->next = list2;
        return dummy->next;
    }
}
