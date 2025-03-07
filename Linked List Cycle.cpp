#include "ListNode.h"

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow) {
                return true;  // Cycle detected
            }
        }

        return false;  // No cycle found
    }
};
