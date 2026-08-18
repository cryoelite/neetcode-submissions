class Solution {
    using LN = ListNode*;

public:
    LN reverseList(LN head) {
        LN prev = nullptr;
        LN cur = head;

        while (cur) {
            LN next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    void reorderList(LN head) {
        if (!head || !head->next) {
            return;
        }

        // 1. Find end of first half
        LN slow = head;
        LN fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split
        LN second = slow->next;
        slow->next = nullptr;

        // 3. Reverse second half
        second = reverseList(second);

        // 4. Merge
        LN first = head;

        while (second) {
            LN first_next = first->next;
            LN second_next = second->next;

            first->next = second;
            second->next = first_next;

            first = first_next;
            second = second_next;
        }
    }
};