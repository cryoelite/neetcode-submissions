/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    using LN = ListNode*;

   public:
    /// ->next is the start of the next half
    LN lastOfFirstHalf(LN head) {
        LN s{head};
        LN f{head->next};
        while (f != nullptr && f->next != nullptr) {
            s = s->next;
            f = f->next->next;
        }

        return s;
    }

    LN reverseList(LN head) {
        LN prev = nullptr;
        LN cur = head;

        while (cur != nullptr) {
            LN next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    void reorderList(LN head) {
        LN first_half{head};
        LN last_first_half{lastOfFirstHalf(head)};
        LN second_half{last_first_half->next};

        last_first_half->next = nullptr;  // Now we have 2 lists

        // Now we reverse the 2nd half and get the new head
        second_half = reverseList(second_half);

        // Now we intersperse the 2nd half's element with the first one
        while (second_half != nullptr) {
            LN f_next{first_half->next};
            LN s_next{second_half->next};

            first_half->next = second_half;
            first_half = first_half->next;
            first_half->next = f_next;

            first_half = first_half->next;
            second_half = s_next;
        }
    }
};
