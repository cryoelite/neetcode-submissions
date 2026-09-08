class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy{};
        dummy.next = head;

        ListNode* element_before_left{&dummy};

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
        }

        element_before_left->next = prev;
        element_at_left->next = cur;

        return dummy.next;
    }
};