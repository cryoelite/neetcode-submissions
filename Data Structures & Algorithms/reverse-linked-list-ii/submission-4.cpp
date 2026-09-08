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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* element_before_left{new ListNode()};
        element_before_left->next = head;
        for (int i{1}; i < left; ++i) {
            element_before_left = element_before_left->next;
        }

        ListNode* cur{element_before_left->next};
        ListNode* element_at_left{cur};
        ListNode* prev{nullptr};

        for (int i{1}; i <= right - left + 1; ++i) {
            ListNode* temp{cur->next};
            cur->next = prev;
            prev = cur;
            cur = temp;

        }  // cur can be nullptr

        if (left == 1) {
            head = prev;
        } else {
            element_before_left->next = prev;
        }
        element_at_left->next = cur;

        return head;
    }
};