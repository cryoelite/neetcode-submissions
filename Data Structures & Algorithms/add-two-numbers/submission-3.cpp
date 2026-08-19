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
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* new_head{new ListNode()};
        ListNode* result{new_head};
        ListNode* prev{nullptr};

        while (l1 != nullptr || l2 != nullptr) {
            int l_val{0};
            int r_val{0};
            if (l1 != nullptr) {
                l_val = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                r_val = l2->val;
                l2 = l2->next;
            }
            int sum{l_val + r_val + result->val};

            result->val = sum % 10;
            result->next = new ListNode();
            prev = result;
            result = result->next;
            if (sum / 10 != 0) {
                sum /= 10;
                result->val = sum;
            }
        }
        if (result->val == 0 && prev != nullptr) {
            prev->next = nullptr;
        }
        return new_head;
    }
};
