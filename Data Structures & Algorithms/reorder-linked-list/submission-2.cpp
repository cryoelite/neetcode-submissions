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

    LN reverseListAndreturnHead(LN head) {
        LN cur{head};
        LN last{nullptr};
        while (cur != nullptr && cur->next != nullptr) {
            // 2 elements, 1st and 2nd
            // we update 1st's next to previous, then update the 2nd element to
            // point to the 1st and then finally set the cur pointer to the
            //  original 2nd's next
            LN temp{cur->next};  // Save the 1st's next

            cur->next = last;  // Update the 1st's next to the prev element

            last = cur;  // Update the prev elem to the 1st element

            cur = temp;  // Set current to the saved 1st's next element
            //  (2nd element)

            temp = cur->next;  // Save the 2nd's next element

            cur->next = last;  // Update the 2nd's next to the 1st element

            last = cur;  // Finally update last to be current element.

            cur = temp;
        }
        if(cur!=nullptr){
            cur->next=last;
            last=cur;
        }
        return (last != nullptr ? last : cur);
    }

    void reorderList(LN head) {
        
        LN first_half{head};
        LN last_first_half{lastOfFirstHalf(head)};
        LN second_half{last_first_half->next};

        last_first_half->next = nullptr;  // Now we have 2 lists

        // Now we reverse the 2nd half and get the new head
        second_half = reverseListAndreturnHead(second_half);
        
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
